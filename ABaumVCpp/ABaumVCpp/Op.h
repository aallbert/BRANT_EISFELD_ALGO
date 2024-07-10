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
    Token *le, *ri; // Linker und rechter Unterbaum

public: 
    /*
     * Erzeugt einen neuen Operator-Knoten.
     * 
     * Parameter:
     * - t: der Typ des Knotens ('+', '-', '*' oder '/')
     * - l: der linke Unterbaum
     * - r: der rechte Unterbaum
     */
    Op(char t, Token *l, Token *r) 
    {
        type = t;
        le = l;
        ri = r;
    }
    
    /*
     * Erzeugt einen neuen Operator-Token ohne Unterbäume.
     * 
     * Parameter:
     * - t: der Typ des Tokens ('+', '-', '*' oder '/')
     */
    Op(char t) 
    {
        type = t;
        le = NULL;
        ri = NULL;
        // cout << "Operator added: " << t << endl;
    }

    /*
     * Gibt den linken Unterbaum zurück.
     *
     * Return: Zeiger auf den linken Unterbaum
     */
    Token* left() override { return le; }

    /*
     * Gibt den rechten Unterbaum zurück.
     *
     * Return: Zeiger auf den rechten Unterbaum
     */
    Token* right() override { return ri; }

    /*
     * Bewertet den Ausdruck, der durch diesen Knoten dargestellt wird.
     *
     * Return: das Ergebnis der Auswertung als int
     * 
     * Reinhold Brant
     */
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
        case '-':
            return this->le->eval() - this->ri->eval();
        case '*':
            return this->le->eval() * this->ri->eval();
        case '/':
            return (double)((double)this->le->eval() / this->ri->eval());
        default:
            return 1;
        }
    }
    
    /*
     * Gibt die Prefix-Darstellung des Ausdrucks zurück.
     *
     * Return: der Ausdruck in Prefix-Notation als String
     * 
     * Reinhold Brant
     */
    string prefix() 
    {
        std::string prefixStr = "";
        string d1, d2;
        char type = this->type;    
        d1 = this->le->prefix();
        d2 = this->ri->prefix();
        return prefixStr + type + " " + d1 + " " + d2; 
    }

    /*
     * Gibt die Infix-Darstellung des Ausdrucks zurück.
     *
     * Return: der Ausdruck in Infix-Notation als String
     * 
     * Albert Eisfeld
     */
    string infix() 
    {
        std::string infixStr = "(";
        std::string d1, d2;
        char type = this->type;    
        d1 = this->le->infix();
        d2 = this->ri->infix();
        return infixStr + d1 + type + d2 + ')';     
    }

    /*
     * Gibt die Postfix-Darstellung des Ausdrucks zurück.
     *
     * Return: der Ausdruck in Postfix-Notation als String
     * 
     * Albert Eisfeld
     */
    string postfix() 
    {
        std::string postfixStr= "";
        std::string d1, d2;
        char type = this->type;    
        d1 = this->le->postfix();
        d2 = this->ri->postfix();
        return postfixStr + d1 + " " + d2 + " " + type; 
    }

    /*
     * Gibt die Anzahl der Knoten im Baum zurück.
     *
     * Return: die Anzahl der Knoten
     * 
     * Reinhold Brant
     */
    int nodes() override 
    {
        return 1 + this->le->nodes() + this->ri->nodes(); 
    }

    /*
     * Gibt die Tiefe des Baums zurück.
     *
     * Return: die Tiefe des Baums
     * 
     * Albert Eisfeld
     */
    int depth() override 
    {
        if (this->le == nullptr || this->ri == nullptr) return 0;
        return 1 + biggerInt(this->le->depth(), this->ri->depth());
    }

    /*
     * Nummeriert den Baum ausgehend vom aktuellen Knoten unter Verwendung eines Zählers 
     * in Infix-Reihenfolge durch (wichtig für die Visualisierung).
     * 
     * Parameter: 
     * - o: der Zähler (als Zeiger auf ein Order-Objekt)
     */
    void order(Order *o) 
    {
        le->order(o);
        setOrd(++o->counter);
        ri->order(o);
    }
};
