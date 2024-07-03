#pragma once

#include <iostream>
#include <string>
#include "Token.h"
#include "helperFile.h"

/*
 * Baumknoten und Token zur Darstellung eines Operators.
 */
class Op : public Token 
{

    Token *le, *ri;

public: 

    /*
     * Erzeugt einen neuen Operator-Knoten.
     * 
     * Parameter: t der Typ des Knotens: '+', '-', '*' oder '/'
     * Parameter: l der linke Unterbaum
     * Parameter: r der rechte Unterbaum
     */
    Op(char t, Token *l, Token *r) 
	{
        type = t;
        le = l;
        ri = r;
    }
    
    /*
     * Erzeugt einen neuen Operator-Token.
     * 
     * Parameter: t der Typ des Tokens: '+', '-', '*' oder '/'
     */
    Op(char t) 
	{
        type = t;
        le = NULL;
        ri = NULL;
		// cout << "Operator added: " << t << endl;
    }

    Token* left() override {  return le; }
    Token* right() override { return ri; }

    int eval() 
	{
            char type = this->type;    
            if (type == 'n') {
                Num* numToken = dynamic_cast<Num*>(this);
                return numToken->eval();
            }
            switch (type)
            {
            case '+':
                return this->le->eval() + this->ri->eval();
                break;
            case '-':
                return this->le->eval() - this->ri->eval();
                break;
            case '*':
                return (this->le->eval()) * (this->ri->eval());
                break;
            case '/':
                return (double)((double)this->le->eval() / this->ri->eval());
                break;
            default:
                return 1;
                break;
            }
    }
    
    string prefix() 
	{
        std::string prefixStr = "";
        string d1, d2;
        char type = this->type;    
        d1 = this->le->prefix();
        d2 = this->ri->prefix();
        return prefixStr + type + " " + d1 + " " + d2; 
    }

    string infix() 
	{

        std::string infixStr = "(";
        std::string d1, d2;
        char type = this->type;    
        d1 = this->le->infix();
        d2 = this->ri->infix();
        return infixStr + d1 + type + d2 + ')'; 
             
    }

    string postfix() 
	{

        std::string postfixStr= "";
        std::string d1, d2;
        char type = this->type;    
        d1 = this->le->postfix();
        d2 = this->ri->postfix();
        return postfixStr + d1 + " " + d2 + " " + type; 
    }

    int nodes() override 
	{
        return 1 + this->le->nodes() + this->ri->nodes(); 
    }

    int depth() override 
	{
        if (this->le == nullptr || this->ri == nullptr) return 0;
        return 1 + biggerInt(this->le->depth(), this->ri->depth());
    }

    /*
     * Nummeriert den Baum ausgehend vom aktuellen Knoten unter Verwendung eines Zaehlers 
	 * in Infix-Reihenfolge durch (wichtig fuer die Visualisierung).
     * 
     * Parameter: o der Zaehler
     */
    void order(Order *o) 
	{
        le->order(o);
        setOrd(++o->counter);
        ri->order(o);
    }

};