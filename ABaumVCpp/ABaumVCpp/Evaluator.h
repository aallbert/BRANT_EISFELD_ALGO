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
            std::cout << "J:" << tok->eval() << std::endl;
        }
        // Aus den Tokens den arithmetischen Bin�rbaum aufbauen
        Token *e = parse(t->tokenize(), mode);
        // jToken *e1 = new Op('-', new Num(4), new Num(5));
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
            case 'P': return parsePrefix(i, end);
            case 'p': return parsePostfix(i, end);
            default : return parseInfix(i, end);
        }
    }

	Token* parsePrefix(vector<Token*>::iterator i, vector<Token*>::iterator end) 
	{

   if (i == end) {
        return nullptr;
    }

    Token* current = *i;
    i++;  // Iterator vorwärts bewegen
    std::cout << current->eval() << std::endl;

    if (current->getType() == 'n') {
        // Es ist eine Zahl
        return current;
    } else if (contains({'+', '-', '*', '/'}, current->getType())) {
        // Es ist ein Operator
        char type = current->getType();
        Token* leftOperand = parsePrefix(i, end);
        Token* rightOperand = parsePrefix(i, end);
        return new Op(type, leftOperand, rightOperand);
    }

    return nullptr;
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
                if (op == '+' ||op == '-' ||op == '*' ||op == '/') {
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
            i++;
        }

        cout << "Stacklen: " << s->size() << endl;
    
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
                s->push(new Op(argBuffer->at(1)->type, argBuffer->at(0), argBuffer->at(2)));
                argBuffer->clear();
            }
            i++;
        }
        std::cout << s->size() << std::endl;
        return s->top();

        cout << "Die Methode Evaluator.parseInfix ist noch nicht implementiert!" << endl;
		
		return new Num(); // remove this line
    }
    private:

		template <class T> bool contains(std::vector<T> listLike, T ele) {
			return std::find(std::begin(listLike), std::end(listLike), ele) != std::end(listLike); 
		}

};