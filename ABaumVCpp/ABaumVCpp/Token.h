#pragma once

#include <string>
#include "Order.h"

using namespace std;

class Token 
{
public:

	char type;						// Typ des Tokens / Knotens
    int ord;						// Reihenfolge fuer die Visualisierung

    char getType() { return type; } // Typ des Knotens
    virtual int eval() = 0;			// Auswertung
	virtual string prefix() = 0;	// Prefix-Darstellung
    virtual string infix() = 0;		// Infix-Darstellung
    virtual string postfix() = 0;	// Postfix-Darstellung
    Token* left() { return NULL; }	// Linker Unterbaum
    Token* right() { return NULL; } // Rechter Unterbaum
    int nodes() { return 1; }		// Anzahl der Knoten des Baums
    int depth() { return 1; }		// Tiefe des Baums

    /*
     * Gibt die Reihenfolge des Knotens in der Infix-Darstellung zurueck (wichtig fuer die Visualisierung).
     * 
     * Return: die Nummer des Knotens
     */
    int getOrd() { return ord; }

    /*
     * Setzt die Nummer des Knotens in der Infix-Darstellung (wichtig fuer die Visualisierung).
     * 
     * Parameter: o die Nummer des Knotens
     */
    void setOrd(int o) { ord = o; }

    /*
     * Nummeriert den Baum ausgehend vom aktuellen Knoten unter Verwendung eines Zaehlers
	 * in Infix-Reihenfolge durch (wichtig fuer die Visualisierung).
     * 
     * Parameter: o der Zaehler
     */
    void order(Order *o);
    
};
