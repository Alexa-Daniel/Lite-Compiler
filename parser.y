%{
    #include <iostream>
    #include <string>
    #include <vector>
    #include <cstdio>
    #include <fstream>
    #include "SymbolTable.h"
    #include "ASTNode.h"

    using namespace std;

    extern int yylex();
    extern int yylineno;
    extern FILE* yyin;
    void yyerror(const char *s);

    SymbolTable* currentScope = nullptr;
    std::vector<std::pair<string, string>> currentParams;
    std::ofstream tableFile("tables.txt");
%}

%code requires {
    #include <string>
    #include <vector>
    #include "ASTNode.h"
}

%union {
    std::string* stringVal;
    ASTNode* astNode;
    std::vector<ASTNode*>* nodeList;
    std::vector<std::string>* typeList;
}

//%define parse.error detailed
//%define parse.lac full

%token <stringVal> INT_VAL FLOAT_VAL STRING_VAL BOOL_VAL CHAR_VAL ID
%token TYPE_INT TYPE_BOOL TYPE_CHAR TYPE_FLOAT TYPE_STRING TYPE_VOID
%token CLASS PUBLIC PRIVATE PROTECTED CONST
%token IF SWITCH CASE DEFAULT ELSE WHILE FOR DO RETURN BREAK CONTINUE MAIN PRINT TRUE FALSE
%token ASSIGN INC DEC ADD_ASSIGN SUB_ASSIGN
%token AND OR NOT
%token EQ NEQ LT GT LE GE PLUS MINUS MUL DIV MOD
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA DOT COLON
%token TILDE ARROW AMPER
%token DECL AS
%token UNLESS REPEAT SWAP CHANCE
%token POWER REPEAT_STR RANDOM COMP APPROX

/* NETERMINALI */
%type <stringVal> primitive_type ptr_list var_type return_type

%type <astNode> expression non_semicolon_expression semicolon_expression boolean_expression variable complex_variable
%type <astNode> statement print_statement statement_or_decl

%type <nodeList> statement_list full_statement_list
%type <nodeList> array_init_list

%type <typeList> arg_list args

%right ASSIGN ADD_ASSIGN SUB_ASSIGN
%left OR
%left AND
%nonassoc EQ NEQ APPROX COMP
%nonassoc LT GT LE GE
%left PLUS MINUS RANDOM
%left REPEAT_STR
%left MUL DIV MOD
%right POWER
%right NOT TILDE AMPER
%left DOT ARROW LBRACKET LPAREN
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start program

%%

/* =============================
   STRUCTURA PROGRAMULUI
   ============================= */

program : 
        { 
            currentScope = new SymbolTable("Global"); 
        }
        global_decl_list main_function
        {
            if(currentScope) 
            {
                currentScope->Print(tableFile);
                delete currentScope; 
                currentScope = nullptr;
            }
            tableFile.close();
        }
        ;

global_decl_list : global_decl_list global_item
                 | 
                 ;
                 
global_item : var_declaration
            | func_decl
            | class_decl
            ;

/* =============================
   TIPURI
   ============================= */

primitive_type : TYPE_BOOL   { $$ = new string("bool"); }
               | TYPE_INT    { $$ = new string("int"); }
               | TYPE_FLOAT  { $$ = new string("float"); }
               | TYPE_CHAR   { $$ = new string("char"); }
               | TYPE_STRING { $$ = new string("string"); }
               ;

ptr_list : MUL          { $$ = new string("*"); }
         | ptr_list MUL { $$ = new string(*$1 + "*"); delete $1; }
         ;

var_type : primitive_type  { $$ = $1; }
         | primitive_type ptr_list { $$ = new string(*$1 + *$2); delete $1; delete $2; }
         | ID              { $$ = $1; }
         | ID ptr_list     { $$ = new string(*$1 + *$2); delete $1; delete $2; }
         ;

return_type : var_type { $$ = $1; }
            | TYPE_VOID       { $$ = new string("void"); }
            | TYPE_VOID ptr_list { $$ = new string("void" + *$2); delete $2; }
            ;
          

/* =======================================
   DECLARATII
   ======================================= */

var_declaration : DECL ID AS var_type SEMICOLON 
                { 
                    if(currentScope->symbols.find(*$2) != currentScope->symbols.end()) {
                        string msg = "Eroare semantica: Variabila '" + *$2 + "' este deja definita in acest scope.";
                        yyerror(msg.c_str());
                    }
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    currentScope->addSymbol(SymbolInfo(*$2, *$4, "variable", scopeType));
                    delete $2; delete $4;
                }
                | DECL ID AS var_type ASSIGN expression SEMICOLON
                {
                    if(currentScope->symbols.find(*$2) != currentScope->symbols.end()) {
                        string msg = "Eroare semantica: Variabila '" + *$2 + "' este deja definita in acest scope.";
                        yyerror(msg.c_str());
                    }
                    if(*$4 != $6->nodeType && $6->nodeType != "error") {
                         string msg = "Eroare semantica: Tip incompatibil la initializarea variabilei '" + *$2 + "': asteptat '" + *$4 + "', primit '" + $6->nodeType + "'";
                         yyerror(msg.c_str());
                    }

                    string computedVal = $6->eval(currentScope).toString();
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    SymbolInfo s(*$2, *$4, "variable", scopeType + " initialized", computedVal);
                    s.hasValue = true;
                    currentScope->addSymbol(s);
                    
                    delete $2; delete $4; delete $6;
                }
                | DECL ID LBRACKET INT_VAL RBRACKET AS var_type SEMICOLON
                {
                    if(currentScope->symbols.find(*$2) != currentScope->symbols.end()) 
                        yyerror("Redefinire vector.");
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    currentScope->addSymbol(SymbolInfo(*$2, *$7, "array", scopeType));

                    delete $2; delete $4; delete $7;
                }
                | DECL ID LBRACKET INT_VAL RBRACKET AS var_type ASSIGN LBRACE array_init_list RBRACE SEMICOLON
                {
                    if(currentScope->symbols.find(*$2) != currentScope->symbols.end())
                        yyerror("Redefinire vector.");

                    string declaredType = *$7;
                    if($10)
                    {
                        for(ASTNode* node : *$10)
                        {
                            if(node->nodeType != declaredType && node->nodeType != "error")
                            {
                                string msg = "Eroare semantica: Element de tip '" + node->nodeType + "' intr-un vector de tip '" + declaredType + "'";
                                yyerror(msg.c_str());
                            }
                        }
                    }
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    currentScope->addSymbol(SymbolInfo(*$2, declaredType, "array", scopeType + " with value"));

                    if($10) 
                    {
                        for(auto n : *$10)
                            delete n;
                        delete $10;
                    }
                    delete $2; delete $4; delete $7;
                }
                | CONST DECL ID AS var_type ASSIGN expression SEMICOLON
                {
                    if(currentScope->symbols.find(*$3) != currentScope->symbols.end())
                        yyerror("Redefinire constanta.");
                    if(*$5 != $7->nodeType && $7->nodeType != "error")
                        yyerror("Tipuri incompatibile la const.");
                    string computedVal = $7->eval(currentScope).toString();
                    string scopeType = currentScope->parentScope == nullptr ? "global" : "local";
                    SymbolInfo s(*$3, "const " + *$5, "constant variable", scopeType, computedVal);
                    s.hasValue = true;
                    currentScope->addSymbol(s);

                    delete $3; delete $5; delete $7;
                }
                ;

array_init_list : array_init_list COMMA expression 
                {
                    $$=$1;
                    $$->push_back($3);
                }
                | expression 
                { 
                    $$=new std::vector<ASTNode*>();
                    $$->push_back($1);
                }
                | 
                {
                    $$=new std::vector<ASTNode*>();
                }
                ;

/* =============================
   EXPRESII
   ============================= */

variable : ID 
        { 
            SymbolInfo* info = currentScope->lookup(*$1);
            string t = "error";
            if(!info) {
                string msg = "Eroare semantica: Variabila '" + *$1 + "' nu a fost declarata.";
                yyerror(msg.c_str());
            }
            else
            {
                t = info->type;
                if(t.find("const ") == 0) {
                    t = t.substr(6);
                }
            }
        
            $$=new IdNode(*$1, t);
            delete $1;
        }
        | complex_variable { $$ = $1; }
        ;

complex_variable : variable DOT ID 
                 { 
                    IdNode* varNode = dynamic_cast<IdNode*>($1);
                    string finalType = "error";
                    if (varNode)
                    {
                        SymbolInfo* objSym=currentScope->lookup(varNode->getName());
                        if (objSym)
                        {
                            string memType;
                            if(currentScope->checkClassMember(objSym->type, *$3, memType))
                            {
                                finalType = memType;
                            }
                            else
                            {
                                string err = "Eroare semantica: Membrul '" + *$3 + "' nu exista in definitia clasei '" + objSym->type + "'";
                                yyerror(err.c_str());
                            }
                        }
                    }
                    $$ = new OtherNode(finalType);
                    delete $1; delete $3; 
                 }
                 | variable ARROW ID { $$ = new OtherNode("ptr_field"); delete $1; delete $3; }
                 | variable LBRACKET expression RBRACKET
                 { 
                     $$ = new OtherNode($1->nodeType);
                     delete $1; delete $3;
                 }
                 | MUL variable { $$ = new OtherNode("deref"); delete $2; }
                 ;

semicolon_expression :variable ASSIGN expression 
                     { 
                        IdNode* id = dynamic_cast<IdNode*>($1);
                        if(id)
                        {
                            if(id->nodeType != $3->nodeType && id->nodeType != "error" && $3->nodeType != "error")
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la atribuirea variabilei '" + id->getName() + "': asteptat '" + id->nodeType + "', primit '" + $3->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            $$ = new AssignNode(id->getName(), $3, id->nodeType);
                        }
                        else
                        {
                            $$=new OtherNode("complex_assign");
                        }
                        delete $1;
                     }
                     | variable ADD_ASSIGN expression { $$=new OtherNode("add_assign"); delete $1; delete $3;}
                     | variable SUB_ASSIGN expression { $$=new OtherNode("sub_assign"); delete $1; delete $3;}
                     | variable INC { $$=new OtherNode("inc_post"); delete $1;}
                     | variable DEC { $$=new OtherNode("dec_post"); delete $1;}
                     | INC variable { $$=new OtherNode("inc_pre"); delete $2; }
                     | DEC variable { $$=new OtherNode("dec_pre"); delete $2; }
                     ;

boolean_expression : expression OR expression 
                   { 
                        if($1->nodeType != "bool" || $3->nodeType != "bool") 
                        {
                            string msg = "Eroare semantica: Operatorul 'OR' asteapta operanzi 'bool', dar a primit '" + $1->nodeType + "' si '" + $3->nodeType + "'";
                            yyerror(msg.c_str());
                        }
                        $$=new BinaryNode($1, $3, "||", "bool");
                   }
                   | expression AND expression 
                   { 
                        if($1->nodeType != "bool" || $3->nodeType != "bool") 
                        {
                            string msg = "Eroare semantica: Operatorul 'AND' asteapta operanzi 'bool', dar a primit '" + $1->nodeType + "' si '" + $3->nodeType + "'";
                            yyerror(msg.c_str());
                        }
                        $$=new BinaryNode($1, $3, "&&", "bool");
                   }
                   | expression EQ expression 
                   { 
                        if($1->nodeType != $3->nodeType) 
                        {
                            string msg = "Eroare semantica: Tipuri incompatibile la egalitate: operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                            yyerror(msg.c_str());
                        }
                        $$=new BinaryNode($1, $3, "==", "bool");
                   }
                   | expression NEQ expression 
                   { 
                       if($1->nodeType != $3->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la neegalitate: operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       $$=new BinaryNode($1, $3, "!=", "bool");
                   }
                   | expression LT expression 
                   { 
                       if($1->nodeType != $3->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la comparatie (<): operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       $$=new BinaryNode($1, $3, "<", "bool");
                   }
                   | expression GT expression 
                   { 
                       if($1->nodeType != $3->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la comparatie (>): operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       $$=new BinaryNode($1, $3, ">", "bool");
                   }
                   | expression LE expression 
                   { 
                       if($1->nodeType != $3->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la comparatie (<=): operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       $$=new BinaryNode($1, $3, "<=", "bool");
                   }
                   | expression GE expression 
                   { 
                       if($1->nodeType != $3->nodeType) 
                       {
                           string msg = "Eroare semantica: Tipuri incompatibile la comparatie (>=): operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                           yyerror(msg.c_str());
                       }
                       $$=new BinaryNode($1, $3, ">=", "bool");
                   }
                   | NOT expression 
                   { 
                        if($2->nodeType != "bool") 
                        {
                            string msg = "Eroare semantica: Operatorul 'NOT' se aplica doar expresiilor 'bool', primit '" + $2->nodeType + "'";
                            yyerror(msg.c_str());
                        }
                        $$=new UnaryNode($2, "!", "bool"); 
                   }
                   | TRUE { $$=new LiteralNode("bool", "true"); }
                   | FALSE { $$=new LiteralNode("bool", "false"); }
                   ;

non_semicolon_expression : boolean_expression { $$=$1; }
                         | expression PLUS expression 
                         { 
                            if($1->nodeType != $3->nodeType)
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la adunare: operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            $$=new BinaryNode($1, $3, "+", $1->nodeType);
                         }
                         | expression MINUS expression 
                         { 
                            if($1->nodeType != $3->nodeType)
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la scadere: operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            $$=new BinaryNode($1, $3, "-", $1->nodeType);
                         }
                         | expression MUL expression 
                         { 
                            if($1->nodeType != $3->nodeType)
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la inmultire: operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            $$=new BinaryNode($1, $3, "*", $1->nodeType);
                         }
                         | expression DIV expression 
                         { 
                            if($1->nodeType != $3->nodeType)
                            {
                                string msg = "Eroare semantica: Tipuri incompatibile la impartire: operand stang '" + $1->nodeType + "' vs operand drept '" + $3->nodeType + "'";
                                yyerror(msg.c_str());
                            }
                            $$=new BinaryNode($1, $3, "/", $1->nodeType);
                         }
                         | expression MOD expression 
                         { 
                             if($1->nodeType != "int" || $3->nodeType != "int")
                             {
                                  string msg = "Eroare semantica: Operatorul 'MOD' necesita operanzi 'int', dar a primit '" + $1->nodeType + "' si '" + $3->nodeType + "'";
                                  yyerror(msg.c_str());
                            }
                             $$=new BinaryNode($1, $3, "%", "int");
                         }
                         
                         | MINUS expression %prec NOT 
                         { 
                             if($2->nodeType != "int" && $2->nodeType != "float")
                             {
                                  string msg = "Eroare semantica: Operatorul unar '-' necesita 'int' sau 'float', dar a primit '" + $2->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             $$=new UnaryNode($2, "-", $2->nodeType); 
                         }
                         | TILDE expression 
                         { 
                             if($2->nodeType != "int")
                             {
                                  string msg = "Eroare semantica: Operatorul '~' necesita 'int', dar a primit '" + $2->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             $$=new UnaryNode($2, "~", "int"); 
                         }
                         | AMPER variable 
                         { 
                             $$=new OtherNode("address_of"); 
                             delete $2; 
                         }
                         
                         | expression APPROX expression 
                         { 
                             if($1->nodeType != "float" || $3->nodeType != "float")
                             {
                                  string msg = "Eroare semantica: Operatorul 'APPROX' (~=) necesita operanzi 'float', dar a primit '" + $1->nodeType + "' si '" + $3->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             delete $1; delete $3;
                             $$=new OtherNode("bool"); 
                         }
                         | expression RANDOM expression 
                         { 
                             if($1->nodeType != "int" || $3->nodeType != "int")
                             {
                                  string msg = "Eroare semantica: Operatorul 'RANDOM' (\?\?) necesita interval 'int', dar a primit '" + $1->nodeType + "' si '" + $3->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             delete $1; delete $3;
                             $$=new OtherNode("int"); 
                         }
                         | expression POWER expression 
                         { 
                             if(($1->nodeType != "int" && $1->nodeType != "float") || ($3->nodeType != "int" && $3->nodeType != "float"))
                             {
                                  string msg = "Eroare semantica: Operatorul 'POWER' (**) necesita 'int' sau 'float', dar a primit '" + $1->nodeType + "' si '" + $3->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             string resType = $1->nodeType;
                             delete $1; delete $3;
                             $$=new OtherNode(resType);
                         }
                         | expression REPEAT_STR expression 
                         { 
                             if($1->nodeType != "string" || $3->nodeType != "int")
                             {
                                  string msg = "Eroare semantica: Operatorul 'REPEAT_STR' (##) necesita 'string' si 'int', dar a primit '" + $1->nodeType + "' si '" + $3->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             delete $1; delete $3;
                             $$=new OtherNode("string"); 
                         }
                         | expression COMP expression 
                         { 
                             if($1->nodeType != $3->nodeType)
                             {
                                  string msg = "Eroare semantica: Operatorul 'COMP' (<=>) necesita aceleasi tipuri, dar a primit '" + $1->nodeType + "' si '" + $3->nodeType + "'";
                                  yyerror(msg.c_str());
                             }
                             delete $1; delete $3;
                             $$=new OtherNode("int"); 
                         }

                         | variable LPAREN arg_list RPAREN 
                         { 
                             IdNode* funcId = dynamic_cast<IdNode*>($1);
                             string returnType = "error"; 

                             if(funcId)
                             {
                                 SymbolInfo* funcSym=currentScope->lookup(funcId->getName());
                                 if(!funcSym || funcSym->kind != "function")
                                 {
                                     string err = "Eroare semantica: Functia '" + funcId->getName() + "' nu este definita.";
                                     yyerror(err.c_str());
                                 } 
                                 else
                                 {
                                     returnType = funcSym->type;

                                     if(funcSym->parameters.size() != $3->size())
                                     {
                                         string err = "Eroare semantica: Numar incorect de parametri la apelul functiei '" + funcId->getName() + "'. Asteptat: " + to_string(funcSym->parameters.size()) + ", Primit: " + to_string($3->size());
                                         yyerror(err.c_str());
                                     }
                                     else
                                     {
                                         for(size_t i=0;i<funcSym->parameters.size(); ++i)
                                         {
                                             if(funcSym->parameters[i].second != $3->at(i))
                                             {
                                                 string err = "Eroare semantica: Tip incorect la parametrul " + to_string(i+1) + " al functiei '" + funcId->getName() + "': asteptat '" + funcSym->parameters[i].second + "', primit '" + $3->at(i) + "'";
                                                 yyerror(err.c_str());
                                             }
                                         }
                                     }
                                 }
                             }
                             else
                             {
                                 if($1->nodeType != "error") {
                                     returnType = $1->nodeType;
                                 }
                             }

                             delete $3;
                             $$=new OtherNode(returnType);
                             delete $1; 
                          }
                         | variable { $$=$1; }
                         | LPAREN expression RPAREN { $$=$2; }
                         
                         | INT_VAL    { $$=new LiteralNode("int", *$1); delete $1; }
                         | FLOAT_VAL  { $$=new LiteralNode("float", *$1); delete $1; }
                         | STRING_VAL { $$=new LiteralNode("string", *$1); delete $1; }
                         | CHAR_VAL   { $$=new LiteralNode("char", *$1); delete $1; }
                         ;

expression : semicolon_expression { $$=$1; }
           | non_semicolon_expression { $$=$1; }
           ;

arg_list : args { $$ = $1; }
         | { $$ = new vector<string>(); }
         ;

args : args COMMA expression 
     { 
        $$ = $1; 
        $$->push_back($3->nodeType);
        delete $3; 
     } 
     | expression 
     { 
        $$ = new vector<string>(); 
        $$->push_back($1->nodeType);
        delete $1; 
     } 
     ;

/* =============================
   FUNCTII SI CLASE
   ============================= */

func_decl : DECL ID LPAREN 
          { 
             currentScope=new SymbolTable("function_" + *$2, currentScope);
             currentParams.clear();
          }
          param_list RPAREN AS return_type LBRACE 
          {
             SymbolInfo funcSymbol(*$2, *$8, "function");
             funcSymbol.parameters=currentParams;
             currentScope->parentScope->addSymbol(funcSymbol);
             currentParams.clear();
          }
          full_statement_list RBRACE 
          {
             currentScope->Print(tableFile);
             SymbolTable* parent=currentScope->parentScope;
             delete currentScope;
             currentScope=parent;
             if($11) { for(auto n : *$11) if(n) delete n; delete $11; }
             delete $2; delete $8;
          }
          ;

param_list : param_list COMMA param
           | param
           | 
           ;

param : DECL ID AS var_type
      {
          currentScope->addSymbol(SymbolInfo(*$2, *$4, "parameter", "local"));
          currentParams.push_back(make_pair(*$2, *$4));
          delete $2; delete $4;
      }
      ;

class_decl : CLASS ID inheritance_spec
           {
               SymbolInfo classSym(*$2, "class", "class");
               currentScope->addSymbol(classSym);

               SymbolTable* classScope = new SymbolTable("class_" + *$2, currentScope);

               SymbolInfo* storedSym = currentScope->lookup(*$2);
               if(storedSym)
               {
                   storedSym->classScope = classScope;
               }

               currentScope = classScope;
           }
           LBRACE class_body RBRACE SEMICOLON
           {
               currentScope->Print(tableFile);
               SymbolTable* parent = currentScope->parentScope;

               currentScope=parent;
               delete $2;
           }
           ;

inheritance_spec : COLON access_modifier ID 
                 | 
                 ;

class_body : class_member_list
           |
           ;

class_member_list : class_member_list class_member
                  | class_member
                  ;

class_member : access_modifier COLON
             | var_declaration
             | func_decl
             | constructor_decl
             | destructor_decl
             ;

access_modifier : PUBLIC | PRIVATE | PROTECTED ;

constructor_decl : ID LPAREN 
                 {
                    currentScope=new SymbolTable("constructor_" + *$1, currentScope);
                 }
                 param_list RPAREN LBRACE
                 {
                    currentScope->parentScope->addSymbol(SymbolInfo(*$1, "constructor", "constructor"));
                 }
                 full_statement_list RBRACE
                 {
                    currentScope->Print(tableFile);
                    SymbolTable* parent=currentScope->parentScope;
                    delete currentScope;
                    currentScope=parent;
                    if($8) { for(auto n : *$8) if(n) delete n; delete $8; }
                 }
                 ;

destructor_decl : TILDE ID LPAREN RPAREN LBRACE statement_list RBRACE 
                { 
                    SymbolInfo destr("~" + *$2, "void", "destructor", "class");
                    currentScope->addSymbol(destr);
                    if($6) { for(auto n : *$6) if(n) delete n; delete $6; }
                    delete $2; 
                }
                ;

main_function: DECL MAIN LPAREN RPAREN AS TYPE_INT 
             {
                 currentScope->addSymbol(SymbolInfo("main", "int", "function"));
                 currentScope=new SymbolTable("function_main", currentScope);
             }
             LBRACE statement_list RBRACE 
             {
                 currentScope->Print(tableFile);

                 if($9 != nullptr)
                 {
                     for(ASTNode* node : *$9)
                     {
                         if(node != nullptr)
                         {
                            node->eval(currentScope);
                         }
                     }

                     for(ASTNode* node : *$9)
                        if(node)
                            delete node;
                     delete $9;
                 }

                 SymbolTable* parent=currentScope->parentScope;
                 delete currentScope;
                 currentScope=parent;
             }
             ;

/* =============================
   INSTRUCTIUNI & LISTE
   ============================= */

statement_list : statement_list statement 
               {
                   $$=$1;
                   if($2 != nullptr)
                   {
                       $$->push_back($2);
                   }
               }
               | statement_list var_declaration 
               { 
                   yyerror("Eroare sintactica: Declaratiile de variabile nu sunt permise in acest bloc.");
                   $$=$1;
               }
               | 
               {
                   $$=new std::vector<ASTNode*>();
               }
               ;

full_statement_list : full_statement_list statement_or_decl 
                    {
                        $$=$1;
                        if($2 != nullptr)
                        {
                            $$->push_back($2);
                        }
                    }
                    | 
                    {
                        $$=new std::vector<ASTNode*>();
                    }
                    ;

statement_or_decl : var_declaration { $$=nullptr; }
                  | statement { $$=$1; }
                  ;

statement : if_statement { $$=nullptr; }
          | while_statement { $$=nullptr; }
          | for_statement { $$=nullptr; }
          | do_statement { $$=nullptr; }
          | switch_statement { $$=nullptr; }
          | return_statement SEMICOLON { $$=nullptr; }
          | break_continue_statement SEMICOLON { $$=nullptr; }
          | block { $$=nullptr; }
          | SEMICOLON { $$=nullptr; }
          
          | print_statement SEMICOLON { $$=$1; }
          
          | variable LPAREN arg_list RPAREN SEMICOLON 
          { 
              IdNode* funcId = dynamic_cast<IdNode*>($1);
              if(funcId)
              {
                  SymbolInfo* funcSym = currentScope->lookup(funcId->getName());
                  
                  if(!funcSym || funcSym->kind != "function")
                  {
                      string err = "Eroare semantica: Functia '" + funcId->getName() + "' nu este definita.";
                      yyerror(err.c_str());
                  } 
                  else
                  {
                      if(funcSym->parameters.size() != $3->size())
                      {
                          string err = "Eroare semantica: Numar incorect de parametri la apelul functiei '" + funcId->getName() + "'. Asteptat: " + to_string(funcSym->parameters.size()) + ", Primit: " + to_string($3->size());
                          yyerror(err.c_str());
                      }
                      else
                      {
                          for(size_t i=0; i<funcSym->parameters.size(); ++i)
                          {
                              string expectedType = funcSym->parameters[i].second;
                              string receivedType = $3->at(i);

                              if(expectedType != receivedType)
                              {
                                  string err = "Eroare semantica: Tip incorect la parametrul " + to_string(i+1) + " al functiei '" + funcId->getName() + "': asteptat '" + expectedType + "', primit '" + receivedType + "'";
                                  yyerror(err.c_str());
                              }
                          }
                      }
                  }
              }
              
              delete $3; 
              delete $1; 
              $$=nullptr;
          }

          | REPEAT LPAREN expression RPAREN block { delete $3; $$=nullptr; }
          | UNLESS LPAREN expression RPAREN block { delete $3; $$=nullptr; }
          | CHANCE LPAREN expression RPAREN block { delete $3; $$=nullptr; }
          
          | SWAP LPAREN variable COMMA variable RPAREN SEMICOLON { delete $3; delete $5; $$=nullptr; }

          | semicolon_expression SEMICOLON { $$=$1; }
          ;

print_statement : PRINT LPAREN expression RPAREN { $$=new PrintNode($3); };

return_statement : RETURN expression { delete $2; }
                 | RETURN 
                 ;

break_continue_statement : BREAK
                         | CONTINUE 
                         ;

block : LBRACE statement_list RBRACE 
        { 
            if($2)
            {
                for(auto n : *$2)
                    if(n)
                        delete n;
                delete $2;
            }
        } 
        ;

if_statement : IF LPAREN boolean_expression RPAREN statement %prec LOWER_THAN_ELSE { delete $3; if($5) delete $5; }
             | IF LPAREN boolean_expression RPAREN statement ELSE statement { delete $3; if($5) delete $5; if($7) delete $7; }
             ;

switch_statement : SWITCH LPAREN expression RPAREN LBRACE case_list RBRACE { delete $3; }
                 ;

case_list : case_list case_item 
          |
          ;
case_item : CASE expression COLON statement_list 
            { 
                delete $2; 
                if($4) { for(auto n:*$4) if(n) delete n; delete $4; } 
            }
          | DEFAULT COLON statement_list 
            { 
                if($3) { for(auto n:*$3) if(n) delete n; delete $3; } 
            }
          ;

while_statement : WHILE LPAREN boolean_expression RPAREN statement { delete $3; if($5) delete $5; }
                ;

do_statement : DO statement WHILE LPAREN boolean_expression RPAREN SEMICOLON { delete $5; if($2) delete $2; }
             ;

for_statement : FOR LPAREN for_init SEMICOLON for_cond SEMICOLON for_step RPAREN statement 
              { 
                  if($9) delete $9; 
              }
              ;

for_init : semicolon_expression { if($1) delete $1; }
         | 
         ;

for_cond : non_semicolon_expression { delete $1; }
         | 
         ;

for_step : semicolon_expression { if($1) delete $1; }
         | 
         ;

%%

void yyerror(const char *s) 
{
    std::cout << "Eroare de sintaxa/semantica la linia " << yylineno << ": " << s << std::endl;
}

int main(int argc, char** argv) 
{
    if(argc > 1)
    {
        yyin=fopen(argv[1], "r");
        if(!yyin) 
        {
            std::cerr << "Nu pot deschide fisierul: " << argv[1] << std::endl;
            return 1;
        }
    }
    
    yyparse();
    return 0;
}