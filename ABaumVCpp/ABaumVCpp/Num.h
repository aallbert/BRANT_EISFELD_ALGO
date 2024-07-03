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
        return to_string(number); // remove this line
    }
    string infix() 
	{
        return to_string(number); // remove this line
    }

	string postfix() 
	{
        return to_string(number); // remove this line
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