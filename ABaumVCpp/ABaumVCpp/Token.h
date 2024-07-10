#pragma once

#include <string>
#include "Order.h"

using namespace std;

/*
 * Abstrakte Basisklasse für Tokens/Knoten in einem arithmetischen Ausdrucksbaum
 */
class Token 
{
public:
    char type;      // Typ des Tokens/Knotens (z.B. Operator, Zahl)
    int ord;        // Reihenfolge für die Visualisierung

    /*
     * Gibt den Typ des Tokens/Knotens zurück.
     *
     * Return: der Typ des Tokens/Knotens
     */
    char getType() { return type; }

    virtual int eval() = 0;

    virtual string prefix() = 0;

    virtual string infix() = 0;

    virtual string postfix() = 0;

    /*
     * Gibt den linken Unterbaum zurück.
     *
     * Return: Zeiger auf den linken Unterbaum (standardmäßig NULL)
     */
    virtual Token* left() { return NULL; }

    /*
     * Gibt den rechten Unterbaum zurück.
     *
     * Return: Zeiger auf den rechten Unterbaum (standardmäßig NULL)
     */
    virtual Token* right() { return NULL; }

    virtual int nodes() { return 1; }

    virtual int depth() { return 1; }

    virtual int depth(char mode) { return 1; }

    int getOrd() { return ord; }
    
    void setOrd(int o) { ord = o; }

    void order(Order *o);
};

