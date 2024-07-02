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
int main(int argc, char* argv[]) 
{
    string exp("");
 
	cout << "argc = " << argc << endl;
	for (int i = 0; i < argc; i++)
	   cout << "argv[" << i << "] = " << argv[i] << endl; 
	
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
		// REINHOLD: '<' = Prefix, '|' = Infix (Standard), '>' = Postfix sind tatsächlich schwer (glaube ich)
		// weil der Befehl "programm.exe >2+2" nicht den Baum mit 2+2 erzeugt, sondern programm.exe in eine neue Datei
		// 2+2 schreiben würde..deswegen fuers erste die chars fuer die modi geaendert
        if (mode == '<' || mode == '|' || mode == '>') 
			exp = exp.substr(1);
        else 
			mode = '|'; // Standard: Infix
        
		Evaluator e;
		std::cout << std::endl << "mode" << mode << std::endl;
		e.evaluate(exp, mode);
    }
}