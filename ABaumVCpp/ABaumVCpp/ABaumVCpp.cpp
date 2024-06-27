#include <iostream>
#include <string>

#include "Evaluator.h"

using namespace std;


/*
 * Liest den Eingabe-String bzw. die Eingabe-Strings ein.
 * Diese werden zu einem String zusammengehaengt und dieser dann ausgewertet.
 * Das erste Zeichen des String gibt dabei den Modus an: 
 * '<' = Prefix, '|' = Infix (Standard), '>' = Postfix.
 *
 * Parameter: argc Anzahl der Argumente
 *            argv Kommandozeilen-Argumente
 */
void main(int argc, char* argv[]) 
{
    string exp("");
 
	// Hilfsausgabe: Kommandozeilenargumente
	/* 
	cout << "argc = " << argc << endl;
	for (int i = 0; i < argc; i++)
	   cout << "argv[" << i << "] = " << argv[i] << endl; 
    */
	
	if (argc > 1) exp = argv[1];
    for (int i = 1; i < argc; i++) 
	{
		exp += " ";
		exp += argv[i];
	}
    if (exp.length() == 0) 
		cout << "Arguments needed!" << endl;
    else 
	{
        char mode = argv[1][0];
        if (mode == '<' || mode == '|' || mode == '>') 
			exp = exp.substr(1);
        else 
			mode = '|'; // Standard: Infix
        
		Evaluator e;
		e.evaluate(exp, mode);
    }
}