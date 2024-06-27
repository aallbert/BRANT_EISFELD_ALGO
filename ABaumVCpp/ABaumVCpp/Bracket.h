#pragma once

#include <iostream>
#include <string>
#include "Token.h"

/*
 * Token zur Darstellung einer Klammer.
 */
class Bracket : public Token 
{

public:

    /*
     * Erzeugt einen neuen Klammer-Token.
     * 
     * Parameter: t Typ der Klammer: '(' oder ')'
     */
    Bracket(char t) { type = t; /* cout << "Bracket added: " << t << endl; */}

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Return: 0
     */
    int eval() { return 0; }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Return: leerer String
     */
    string prefix() { return ""; }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Return: leerer String
     */
    string infix() { return ""; }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Return: leerer String
     */
    string postfix() { return ""; }

    /*
     * Dummy-Methode, tut nichts.
     * 
     * Parameter: o Dummy-Parameter
     */
    void order(Order o) {}
};