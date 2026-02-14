#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class SymbolInfo
{
    public: 
        string name, type, kind, scope, value;
        bool hasValue;

        vector<pair<string, string>> parameters;

        class SymbolTable* classScope;

        string extraInfo;

        SymbolInfo() : hasValue(false), classScope(nullptr) {}
        SymbolInfo( string n , string t, string k, string s="", string v="0") : name(n), type(t), kind(k), scope(s), value(v), hasValue(false), classScope(nullptr) {}
};

class SymbolTable
{
    public:
        string scopeName;
        SymbolTable* parentScope;
        map<string, SymbolInfo> symbols;

        SymbolTable(string name, SymbolTable* parent = nullptr) : scopeName(name), parentScope(parent) {}

        bool addSymbol(SymbolInfo symbol)
        {
            if(symbols.find(symbol.name) != symbols.end())
            {
                return false;
            }
            symbols[symbol.name] = symbol;
            return true;
        }

        SymbolInfo* lookup(string name)
        {
            if(symbols.find(name) != symbols.end())
            {
                return &symbols[name];
            }
            if(parentScope != nullptr)
            {
                return parentScope->lookup(name);
            }
            return nullptr;
        }

        SymbolInfo* lookupLocal(string name)
        {
            if(symbols.find(name) != symbols.end())
            {
                return &symbols[name];
            }
            return nullptr;
        }

        void updateValue(string name, string newVal)
        {
            SymbolInfo* s = lookup(name);
            if(s)
            {
                s->value = newVal;
                s->hasValue = true;
            }
        }

        bool checkClassMember(string className, string memberName, string& memberType)
        {
            SymbolInfo* classInfo = lookup(className);
            if(!classInfo || classInfo->kind != "class")
            { 
                return false;
            }
            if(classInfo->classScope == nullptr)
            {
                return false;
            } 

            SymbolInfo* member = classInfo->classScope->lookupLocal(memberName);
            if(member)
            {
                memberType = member->type;
                return true;
            }
            return false;
        }

        void Print(ofstream& fout)
        {
            fout<<"Scope: "<<scopeName<<endl;

            if(parentScope)
                fout<<"Parent scope: "<<parentScope->scopeName<<endl;
            else
                fout<<"Parent scope: NULL\n";

            fout<<"Symbols defined:\n";
            for(auto const& [key,val] : symbols)
            {
                fout<<"Name: "<<val.name;
                fout<<" | Kind: "<<val.kind;
                if(val.kind=="function")
                {
                    fout<<" | Return type: "<<val.type;

                    fout<<" | Parameters: ";
                    for(int i=0; i < val.parameters.size(); i++)
                    {
                        fout<<val.parameters[i].second<<" "<<val.parameters[i].first;
                        if(i<val.parameters.size() - 1)
                            fout<<", ";
                    }
                }
                else
                {
                    fout<<" | Type: "<<val.type;
                }
                
                if(val.kind=="variable" || val.kind=="parameter")
                {
                    if(!val.scope.empty())
                        fout<<" | Scope: "<<val.scope;

                    if(val.hasValue)
                        fout<<" | Value: "<<val.value;
                }

                if(!val.extraInfo.empty())
                {
                    fout<<" | Info: "<<val.extraInfo;
                }
                fout<<'\n';

            }
            fout<<"--------------------------------------------\n";
            
            for(auto const& [key,val] : symbols)
            {
                if(val.kind == "class" && val.classScope != nullptr)
                {
                    val.classScope->Print(fout);
                }
            }
        }


        ~SymbolTable()
        { 
            for(auto& [key,val] : symbols)
            {
                if(val.classScope != nullptr)
                {
                    delete val.classScope;
                }
            }
        }
};

#endif