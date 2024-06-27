#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stack>

#include "Token.h"
#include "Tokenizer.h"
#include "Vis.h"
#include "Num.h"

using namespace std;

/*
 * Auswertung von arithmetischen Baeumen
 */
class Evaluator 
{

public:
	/*
     * Wertet einen arithmetischen Ausdruck aus. Dazu wird der Ausdruck erst in Tokens zerlegt.
     * Diese werden dann in einen arithmetischen Binärbaum umgewandelt, der dann ausgewertet und 
	 * grafisch dargestellt werden kann.
     *
     * Parameter: exp der arithmetische Ausdruck
     * Parameter: mode: '<': Prefix, '|': Infix, '>': Postfix
     */
    void evaluate(string exp, char mode) 
	{

        // String in Tokens zerlegen
        Tokenizer *t = new Tokenizer(exp);

        // Aus den Tokens den arithmetischen Binärbaum aufbauen
        Token *e = parse(t->tokenize(), mode);

        // Testbaum, falls Tokenizer und/oder Parser noch nicht fertig:
        /*
        e = new Op('+',
                   new Op('*',
                          new Num(2),
                          new Num(3)),
                   new Op('-',
                          new Op('/',
                                 new Num(6),
                                 new Num(2)),
                          new Num(1)));
       */
       // Prefix:  + * 2 3 - / 6 2 1 = 8
       // Infix:   ((2 * 3) + ((6 / 2) - 1)) = 8
       // Postfix: 2 3 * 6 2 / 1 - + = 8
       // #Knoten: 9
       // Tiefe:   4

        // Ausgabe des arithmetischen Ausdrucks
        cout << "Prefix:  " << e->prefix() << " = " << e->eval() << endl;
        cout << "Infix:   " << e->infix() << " = " << e->eval() << endl;
        cout << "Postfix: " << e->postfix() << " = " << e->eval() << endl;
        cout << "#Knoten: " << e->nodes() << endl;
        cout << "Tiefe:   " << e->depth() << endl;

        // Grafische Darstellung des arithmetischen Binärbaums
		Vis *v = new Vis(e, Vis::REGULAR); // Layout 1: gleiche Abstände zwischen Knoten
        //Vis v = new Vis(e, Vis::BINARY); // Layout 2: binäre Unterteilung
        
		// Text-/Grafikfenster sichtbar machen
		// ...

    }

private: 

	/*
     * Ruft die entsprechende Parse-Methode (Prefix, Infix oder Postfix) auf.
     *
     * Parameter: tok der tokenisierte arithmetische Ausdruck
     * Parameter: mode '<': Prefix, '|': Infix, '>': Postfix
     * Return:: der arithmetische Binärbaum
     */
	Token* parse(vector<Token*> *tok, char mode) 
	{
		vector<Token*>::iterator i = tok->begin();
		switch (mode) 
		{
            case '<': return parsePrefix(i);
            case '>': return parsePostfix(i);
            default : return parseInfix(i);
        }
    }

	Token* parsePrefix(vector<Token*>::iterator i) 
	{

        // to implement ...

        cout << "Die Methode Evaluator.parsePrefix ist noch nicht implementiert!" << endl;

        return new Num(); // remove this line
    }

    Token* parsePostfix(vector<Token*>::iterator i)
	{
		stack<Token*> *s = new stack<Token*>();

        // to implement ...

        cout << "Die Methode Evaluator.parsePostfix ist noch nicht implementiert!" << endl;
		
		return new Num(); // remove this line
    }

    Token* parseInfix(vector<Token*>::iterator) 
	{
        stack<Token*> *s = new stack<Token*>();

        // to implement ...

        cout << "Die Methode Evaluator.parseInfix ist noch nicht implementiert!" << endl;
		
		return new Num(); // remove this line
    }

};