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
     * Diese werden dann in einen arithmetischen Bin�rbaum umgewandelt, der dann ausgewertet und 
	 * grafisch dargestellt werden kann.
     *
     * Parameter: exp der arithmetische Ausdruck
     * Parameter: mode: '<': Prefix, '|': Infix, '>': Postfix
     */
    void evaluate(string exp, char mode) 
	{

        // String in Tokens zerlegen
        Tokenizer *t = new Tokenizer(exp);
         std::cout << "Tokenizer erfolgreich" << std::endl;

        // Aus den Tokens den arithmetischen Bin�rbaum aufbauen

        Token *e = parse(t->tokenize(), mode);
        // jToken *e1 = new Op('-', new Num(4), new Num(5));
        std::cout << "Ergebnis: " << e->eval() << std::endl;
        Vis visualizer = Vis(e, 2);
        //visualizer.drawTreeBin(e);
        visualizer.drawTreeBin(e);
        return;

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

        // Grafische Darstellung des arithmetischen Bin�rbaums
		Vis *v = new Vis(e, Vis::REGULAR); // Layout 1: gleiche Abst�nde zwischen Knoten
        //Vis v = new Vis(e, Vis::BINARY); // Layout 2: bin�re Unterteilung
        
		// Text-/Grafikfenster sichtbar machen
		// ...

    }

private: 

	/*
     * Ruft die entsprechende Parse-Methode (Prefix, Infix oder Postfix) auf.
     *
     * Parameter: tok der tokenisierte arithmetische Ausdruck
     * Parameter: mode '<': Prefix, '|': Infix, '>': Postfix
     * Return:: der arithmetische Bin�rbaum
     */
	Token* parse(vector<Token*> *tok, char mode) 
	{
		vector<Token*>::iterator i = tok->begin();
		vector<Token*>::iterator end = tok->end();

		switch (mode) 
		{
            case '<': return parsePrefix(i, end);
            case '>': return parsePostfix(i, end);
            default : return parseInfix(i, end);
        }
    }

	Token* parsePrefix(vector<Token*>::iterator i, vector<Token*>::iterator end) 
	{
        // TODO, klappt nicht für den Test Case
        stack<Token*> *s = new stack<Token*>();
        std::vector<Token*> *argBuffer = new vector<Token*>();

        int tokenCounter = 0;

        while (i != end) {
            if (tokenCounter < 2) {
                if (!contains({'+', '-', '*', '/'}, (*i)->type)) {
                    tokenCounter++;
                }
                tokenCounter = 0;
                s->push(*i);
            }
            if (tokenCounter == 2) {
                for (int k = 0; k < 3; k++) {
                    Token* t = s->top();
                    s->pop();
                    argBuffer->push_back(t);
                }
                s->push(new Op(argBuffer->at(2)->type, argBuffer->at(1), argBuffer->at(0)));
                argBuffer->clear();
                tokenCounter--;
            }
            i++;
        }
        std::cout << s->size() << std::endl;
        return s->top();
   }

    Token* parsePostfix(vector<Token*>::iterator i, vector<Token*>::iterator end)
	{
		stack<Token*> *s = new stack<Token*>();
        while (i != end) {
            if ((*i)->type == 'n') {
                s->push(*i);
            } else {
                char op = (*i)->type;
                if (op == '+' ||op == '-' ||op == '*' ||op == '/') {
                    auto i1 = s->top();
                    s->pop();
                    auto i2 = s->top();
                    s->pop();
                    s->push(new Op(op, i2, i1));
                }
            }
            i++;
        }

        cout << s->size() << endl;
    
		return s->top(); 
    }

    Token* parseInfix(vector<Token*>::iterator i, vector<Token*>::iterator end) 
	{
        stack<Token*> *s = new stack<Token*>();
        std::vector<Token*> *argBuffer = new vector<Token*>();

        while (i != end) {
            if ((*i)->type != ')') {
                s->push(*i);
            } else {
                for (int k = 0; k < 3; k++) {
                    Token* t = s->top();
                    s->pop();
                    argBuffer->push_back(t);
                }
                // pop opening bracket
                s->pop();
                s->push(new Op(argBuffer->at(1)->type, argBuffer->at(2), argBuffer->at(0)));
                argBuffer->clear();
            }
            i++;
        }
        std::cout << s->size() << std::endl;
        return s->top();

    }
    private:

		template <class T> bool contains(std::vector<T> listLike, T ele) {
			return std::find(std::begin(listLike), std::end(listLike), ele) != std::end(listLike); 
		}

};