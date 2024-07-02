#pragma once

#include <iostream>
#include <string>
#include "Token.h"
#include "Num.h"    

using namespace std;

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

    ~Op(){};

    Token* left() override {  return le; }
    Token* right() override { return ri; }

    int eval() 
	{
        cout << "TESTING EVAL()" << endl;
        if (le != NULL && ri != NULL){
            Op leftSubtree = Op(le->type, le->left(), le->right());
            Op rightSubtree = Op(ri->type, ri->left(), ri->right());
            switch (type) 
            {
                case '+':
                    cout << "Testitntn " << le->type << this->type << ri->type << endl; 
                    return leftSubtree.eval() + rightSubtree.eval();
                    break;
                case '-':
                    return leftSubtree.eval() - rightSubtree.eval(); 
                    break;
                case '*':
                    return leftSubtree.eval() * rightSubtree.eval(); 
                    break;
                case '/':
                    return leftSubtree.eval() / rightSubtree.eval();
                    break;
                default:
                    cout << "Operator Typ nicht erkannt!" << endl; 
                    break;    
                }
            }
        cout << "ZAHLENKNOTEN" << endl;
        return  dynamic_cast<Num*>((Token*)this)->eval();;
    }
    
    string prefix() 
	{

        // to implement ...
        
        cout << "Die Methode Op.prefix ist noch nicht implementiert!" << endl;

        return ""; // remove this line
    }
    string infix() 
	{

        // to implement ...
        
        cout << "Die Methode Op.infix ist noch nicht implementiert!" << endl;

        return ""; // remove this line
    }
    string postfix() 
	{

        // to implement ...
                
        cout << "Die Methode Op.postfix ist noch nicht implementiert!" << endl;

        return ""; // remove this line
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