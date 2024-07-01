#pragma once

#include <iostream>
#include <string>
#include <map>
#include "Token.h"

/*
 * Baumknoten und Token zur Darstellung einer Zahl.
 */
class Num : public Token 
{
    
	int number;
    std::string intToChar(int i) {
        if (abs(i) != i || abs(i) > 9) return "-";
        return (std::string){(char)(48 + i)};
    }

public:

    Num() {} // DIESEN LEEREN STANDARDKONSTRUKTOR NICHT LOESCHEN
	Num(int i) {  
        cout << "Number added: " << i << endl; 
        number = i;
        type = *"n";
    }
    
    int eval() 
	{

        return number;
    }
    
    string prefix() 
	{
        return intToChar(number); // remove this line
    }
    string infix() 
	{
        return intToChar(number); // remove this line
    }

	string postfix() 
	{
        return intToChar(number); // remove this line
    }
    
    /*
     * Nummeriert den Baum ausgehend vom aktuellen Knoten unter Verwendung eines Zaehlers 
	 * in Infix-Reihenfolge durch (wichtig fuer die Visualisierung).
     * 
     * Parameter: o der Zaehler
     */
    void order(Order o) 
	{ 
		 setOrd(++o.counter); 
	}

};