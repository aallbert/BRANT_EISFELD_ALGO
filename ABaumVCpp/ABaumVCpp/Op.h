#pragma once

#include <iostream>
#include <string>
#include "Token.h"
#include <format>

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
                 return this->le->eval() * this->ri->eval();
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

    int nodes() 
	{

        // to implement ...

        cout << "Die Methode Op.nodes ist noch nicht implementiert!" << endl;

        return 1; // remove this line
    }

    int depth() 
	{

        // to implement ...
                
        cout << "Die Methode Op.depth ist noch nicht implementiert!" << endl;

        return 1; // remove this line
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