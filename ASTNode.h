#ifndef AST_H
#define AST_H

#include <string>
#include <iostream>
#include <cmath>
#include "SymbolTable.h"

using namespace std;

class Wrapper 
{
public:
    enum Type { INT, FLOAT, BOOL, STRING, VOID_TYPE };
    Type type;
    
    int iVal;
    float fVal;
    bool bVal;
    string sVal;

    Wrapper() : type(VOID_TYPE), iVal(0), fVal(0.0), bVal(false) {}
    
    Wrapper(int v) : type(INT), iVal(v), fVal(0.0), bVal(false) {}
    Wrapper(float v) : type(FLOAT), fVal(v), iVal(0), bVal(false) {}
    Wrapper(bool v) : type(BOOL), bVal(v), iVal(0), fVal(0.0) {}
    Wrapper(string v) : type(STRING), sVal(v), iVal(0), fVal(0.0), bVal(false) {}

    string toString()
    {
        if(type == INT) return to_string(iVal);
        if(type == FLOAT) return to_string(fVal);
        if(type == BOOL) return bVal ? "true" : "false";
        if(type == STRING) return sVal;
        return "";
    }
};


class ASTNode 
{
public:
    string nodeType;
    
    ASTNode(string t) : nodeType(t) {}
    virtual ~ASTNode() {}
    virtual Wrapper eval(SymbolTable* st)=0;
};

class LiteralNode : public ASTNode
{
private:
    Wrapper val;

public:
    LiteralNode(string type, string textVal) : ASTNode(type)
    {
        if(type == "int") val = Wrapper(stoi(textVal));
        else if(type == "float") val = Wrapper(stof(textVal));
        else if(type == "bool") val = Wrapper(textVal == "true");
        else if(type == "string")
        {
            if(textVal.size()>=2)
                val=Wrapper(textVal.substr(1, textVal.size() - 2));
            else 
                val=Wrapper(textVal);
        }
    }
    
    Wrapper eval(SymbolTable* st) override
    {
        return val;
    }
};


class IdNode : public ASTNode
{
    string name;
public:
    IdNode(string n, string t) : ASTNode(t), name(n) {}

    Wrapper eval(SymbolTable* st) override
    {
        SymbolInfo* info = st->lookup(name);
        if(!info)
        {
            cerr << "Runtime Error: Variable " << name << " not found!" << endl;
            exit(-1);
        }
        
        if(info->type == "int" || info->type == "const int") return Wrapper(stoi(info->value));
        if(info->type == "float" || info->type == "const float") return Wrapper(stof(info->value));
        if(info->type == "bool" || info->type == "const bool") return Wrapper(info->value == "true");
        if(info->type == "string" || info->type == "const string") return Wrapper(info->value);
        
        return Wrapper();
    }
    
    string getName()
    {
        return name;
    }
};

class BinaryNode : public ASTNode
{
private:
    ASTNode *left, *right;
    string op;
public:
    BinaryNode(ASTNode* l, ASTNode* r, string o, string resType) : left(l), right(r), op(o), ASTNode(resType) {}

    ~BinaryNode()
    {
        delete left;
        delete right;
    }

    Wrapper eval(SymbolTable* st) override
    {
        Wrapper v1 = left->eval(st);
        Wrapper v2 = right->eval(st);

        if(op == "+")
        {
            if(v1.type == Wrapper::INT && v2.type == Wrapper::INT) return Wrapper(v1.iVal + v2.iVal);
            if(v1.type == Wrapper::FLOAT && v2.type == Wrapper::FLOAT) return Wrapper(v1.fVal + v2.fVal);
            if(v1.type == Wrapper::STRING && v2.type == Wrapper::STRING) return Wrapper(v1.sVal + v2.sVal);
        }
        if(op == "-")
        {
            if(v1.type == Wrapper::INT) return Wrapper(v1.iVal - v2.iVal);
            if(v1.type == Wrapper::FLOAT) return Wrapper(v1.fVal - v2.fVal);
        }
        if(op == "*")
        {
            if(v1.type == Wrapper::INT) return Wrapper(v1.iVal * v2.iVal);
            if(v1.type == Wrapper::FLOAT) return Wrapper(v1.fVal * v2.fVal);
        }
        if(op == "/")
        {
            if(v1.type == Wrapper::INT)
            {
                if(v2.iVal == 0)
                {
                    cerr << "Runtime Error: Division by zero!" << endl;
                    exit(-1);
                }
                return Wrapper(v1.iVal / v2.iVal);
            }
            if(v1.type == Wrapper::FLOAT)
            {
                if(v2.fVal == 0.0f)
                {
                    cerr << "Runtime Error: Division by zero!" << endl;
                    return Wrapper(0.0f);
                }
                return Wrapper(v1.fVal / v2.fVal);
            }
        }
        if(op == "%")
        {
            if(v1.type == Wrapper::INT)
             {
                if(v2.iVal == 0)
                {
                    cerr << "Runtime Error: Modulo by zero!" << endl;
                    return Wrapper(0);
                }
                return Wrapper(v1.iVal % v2.iVal);
            }
        }

        if(op == "<")
        {
            if(v1.type == Wrapper::INT) return Wrapper(v1.iVal < v2.iVal);
            if(v1.type == Wrapper::FLOAT) return Wrapper(v1.fVal < v2.fVal);
        }
        if(op == ">")
        {
            if(v1.type == Wrapper::INT) return Wrapper(v1.iVal > v2.iVal);
            if(v1.type == Wrapper::FLOAT) return Wrapper(v1.fVal > v2.fVal);
        }
        if(op == "<=")
        {
            if(v1.type == Wrapper::INT) return Wrapper(v1.iVal <= v2.iVal);
            if(v1.type == Wrapper::FLOAT) return Wrapper(v1.fVal <= v2.fVal);
        }
        if(op == ">=")
        {
            if(v1.type == Wrapper::INT) return Wrapper(v1.iVal >= v2.iVal);
            if(v1.type == Wrapper::FLOAT) return Wrapper(v1.fVal >= v2.fVal);
        }
        if(op == "==")
        {
            if(v1.type == Wrapper::INT) return Wrapper(v1.iVal == v2.iVal);
            if(v1.type == Wrapper::FLOAT) return Wrapper(v1.fVal == v2.fVal);
            if(v1.type == Wrapper::BOOL) return Wrapper(v1.bVal == v2.bVal);
            if(v1.type == Wrapper::STRING) return Wrapper(v1.sVal == v2.sVal);
        }
        if(op == "!=")
        {
            if(v1.type == Wrapper::INT) return Wrapper(v1.iVal != v2.iVal);
            if(v1.type == Wrapper::FLOAT) return Wrapper(v1.fVal != v2.fVal);
            if(v1.type == Wrapper::BOOL) return Wrapper(v1.bVal != v2.bVal);
            if(v1.type == Wrapper::STRING) return Wrapper(v1.sVal != v2.sVal);
        }

        if(op == "&&")
        {
            if(v1.type == Wrapper::BOOL)
            {
                return Wrapper(v1.bVal && v2.bVal);
            } 
        }
        if(op == "||")
        {
            if(v1.type == Wrapper::BOOL)
            {
                return Wrapper(v1.bVal || v2.bVal);
            } 
        }

        exit(-1);
    }
};

class UnaryNode : public ASTNode 
{
private:
    ASTNode* operand;
    string op;
public:
    UnaryNode(ASTNode* child, string o, string resType) : ASTNode(resType), operand(child), op(o) {}

    ~UnaryNode()
    { 
        delete operand;
    }

    Wrapper eval(SymbolTable* st) override 
    {
        Wrapper val = operand->eval(st);

        if(op == "-")
        {
            if(val.type == Wrapper::INT)
            {
                return Wrapper(-val.iVal);
            }
            if(val.type == Wrapper::FLOAT)
            {
                return Wrapper(-val.fVal);
            }
        }
        if(op == "!")
        {
            if(val.type == Wrapper::BOOL) return Wrapper(!val.bVal);
        }

        exit(-1);
    }
};

class AssignNode : public ASTNode
{
    string idName;
    ASTNode* expr;
public:
    AssignNode(string name, ASTNode* e, string t) : ASTNode(t), idName(name), expr(e) {}

    ~AssignNode()
    {
        delete expr;
    }

    Wrapper eval(SymbolTable* st) override
    {
        Wrapper val = expr->eval(st);
        st->updateValue(idName, val.toString());
        return val;
    }
};


class PrintNode : public ASTNode
{
    ASTNode* expr;
public:
    PrintNode(ASTNode* e) : ASTNode("void"), expr(e) {}

    ~PrintNode()
    { 
        delete expr;
    }

    Wrapper eval(SymbolTable* st) override 
    {
        Wrapper val = expr->eval(st);
        cout << val.toString() << endl;
        return val;
    }
};


class OtherNode : public ASTNode
{
public:
    OtherNode(string t) : ASTNode(t) {}

    Wrapper eval(SymbolTable* st) override 
    {
        if(nodeType == "int") return Wrapper(0);
        if(nodeType == "float") return Wrapper(0.0f);
        if(nodeType == "bool") return Wrapper(false);
        if(nodeType == "string") return Wrapper(string(""));
        return Wrapper();
    }
};

#endif