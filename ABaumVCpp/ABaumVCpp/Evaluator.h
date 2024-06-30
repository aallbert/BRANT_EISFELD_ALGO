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
        std::vector<Token*>* tokens = t->tokenize();
        for (Token* tok : *tokens) {
            std::cout << tok->type << std::endl;
        }
        // Aus den Tokens den arithmetischen Bin�rbaum aufbauen
        Token *e = parse(t->tokenize(), mode);
        std::cout << e << std::endl;
        std::cout << e << std::endl;
        std::cout << e->right() << std::endl;
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
            case 'P': return parsePrefix(i, end);
            case 'p': return parsePostfix(i, end);
            default : return parseInfix(i);
        }
    }

	Token* parsePrefix(vector<Token*>::iterator i, vector<Token*>::iterator end) 
	{


        cout << "P:" << (*i)->type << endl;
        cout << "P_:" << (*i) << " " << (*end) << endl;
        if (i == end) return (*i);
        // to implement ...
        if (contains({'+', '-', '/', '*'}, (*i)->type)) {
            char type = (*i)->type;
            ++i;
            Token* left = parsePrefix(i, end);
            Token* right = parsePrefix(i, end);
            return new Op(type, left, right);
        } else {
            return (*i);
        } 
    }

    Token* parsePostfix(vector<Token*>::iterator i, vector<Token*>::iterator end)
	{
		stack<Token*> *s = new stack<Token*>();
        std::cout << "___________" << std::endl;
        while (i != end) {
            std::cout << (*i)->type << std::endl;
            std::cout << *i << std::endl;
            if ((*i)->type == 'n') {
                s->push(*i);
            } else {
                char op = (*i)->type;
                if (op == '+') {
                    std::cout << "in" << std::endl;
                    auto i1 = s->top();
                    std::cout << i1 << std::endl;
                    s->pop();
                    auto i2 = s->top();
                    std::cout << i2 << std::endl;
                    s->pop();
                    s->push(new Op(op, i1, i2));
                }
            }
            ++i;
        }

        cout << "Die Methode Evaluator.parsePostfix ist noch nicht implementiert!" << endl;
		
		return s->top(); 
    }

    Token* parseInfix(vector<Token*>::iterator) 
	{
        stack<Token*> *s = new stack<Token*>();

        // to implement ...

        cout << "Die Methode Evaluator.parseInfix ist noch nicht implementiert!" << endl;
		
		return new Num(); // remove this line
    }
    private:

		template <class T> bool contains(std::vector<T> listLike, T ele) {
			return std::find(std::begin(listLike), std::end(listLike), ele) != std::end(listLike); 
		}

};