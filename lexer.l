%{
    #include <iostream>
    #include <string>
    #include <vector>
    #include "parser.tab.h"
    using namespace std;
%}

%option noyywrap
%option yylineno

%%

"//".* ;
"/*"([^*]|("*"+[^*/]))*"*"+"/" ;
[ \t\n\r]+ ;

    /* CUVINTE CHEIE STANDARD */
"int"             { return TYPE_INT; }
"float"           { return TYPE_FLOAT; }
"string"          { return TYPE_STRING; }
"bool"            { return TYPE_BOOL; }
"void"            { return TYPE_VOID; }
"char"            { return TYPE_CHAR; }

"class"           { return CLASS; }
"public"          { return PUBLIC; }
"private"         { return PRIVATE; }
"protected"       { return PROTECTED; }

"if"              { return IF; }
"else"            { return ELSE; }
"while"           { return WHILE; }
"for"             { return FOR; }
"do"              { return DO; }
"switch"          { return SWITCH; }
"case"            { return CASE; }
"default"         { return DEFAULT; }
"break"           { return BREAK; }
"continue"        { return CONTINUE; }
"main"            { return MAIN; }
"Main"            { return MAIN;}

"return"          { return RETURN; }
"Print"           { return PRINT; }
"true"            { return TRUE; }
"false"           { return FALSE; }
"const"           { return CONST; }

"decl"            { return DECL; }
"as"              { return AS; }

"unless"          { return UNLESS; }
"repeat"          { return REPEAT; }
"swap"            { return SWAP; }
"chance"          { return CHANCE; }

"**"|"pow"        { return POWER; }
"##"|"strrep"     { return REPEAT_STR; }
"??"|"rand"       { return RANDOM; }
"<=>"|"comp"      { return COMP; }
"~="|"approx"     { return APPROX; }

"&&"|"and"        { return AND; }
"||"|"or"         { return OR; }
"!"|"not"         { return NOT; }

"->"|"access"     { return ARROW; }
"++"|"inc"        { return INC; }
"--"|"dec"        { return DEC; }
"+="|"add_assign" { return ADD_ASSIGN; }
"-="|"sub_assign" { return SUB_ASSIGN; }
"=="|"eq"         { return EQ; }
"!="|"neq"        { return NEQ; }
"<="|"le"         { return LE; }
">="|"ge"         { return GE; }

"+"|"plus"      { return PLUS; }
"-"|"minus"     { return MINUS; }
"*"|"mul"       { return MUL; }
"/"|"div"       { return DIV; }
"%"|"mod"       { return MOD; }
"="|"assign"    { return ASSIGN; }
"<"|"lt"        { return LT; }
">"|"gt"        { return GT; }
"&"|"ref"       { return AMPER; }
"~"|"tilde"     { return TILDE; }

"("|"lparen"    { return LPAREN; }
")"|"rparen"    { return RPAREN; }
"{"|"lbrace"    { return LBRACE; }
"}"|"rbrace"    { return RBRACE; }
"["|"lbracket"  { return LBRACKET; }
"]"|"rbracket"  { return RBRACKET; }
";"|"semicolon" { return SEMICOLON; }
","|"comma"     { return COMMA; }
"."|"dot"       { return DOT; }
":"|"colon"     { return COLON; }

    /* VALORI */
    /* numere */
0|[1-9][0-9]* { 
    yylval.stringVal = new string(yytext);
    return INT_VAL;
}

    /* floaturi*/
[0-9]+"."[0-9]+ { 
    yylval.stringVal = new string(yytext);
    return FLOAT_VAL;
}

    /* stringuri, ca sa accepte si  */

\"(\\.|[^"\\])*\" {
    yylval.stringVal = new string(yytext);
    return STRING_VAL;
}

    /* char-uri, sa poti avea '\n' */ 
\'([^'\\]|\\.)\' {
    yylval.stringVal = new string(yytext);
    return CHAR_VAL;
}

    /* id-uri */
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.stringVal = new string(yytext);
    return ID;
}

. { cout << "Eroare lexicala: " << yytext << endl; }

%%