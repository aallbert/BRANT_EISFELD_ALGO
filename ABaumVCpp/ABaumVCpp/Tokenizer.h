#include <string>
#include <vector>

#include "Num.h"
#include "Bracket.h"
#include "Op.h"


using namespace std;

class Tokenizer 
{
 
    string src;

public:
    Tokenizer(string s) 
	{
        src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht 
					   // ueber die String-Grenze zu laufen
    }
    
    vector<Token*>* tokenize() 
	{
        vector<Token*>* tokens = new vector<Token*>();
	    vector<Token*>::iterator i = tokens->begin();

		/*

		Beispiel für das Einfügen von Knoten:

		i = tokens->insert(i, new Op(c));
		i = tokens->insert(i, new Num(c));
		usw. 
		
		*/
		
		// to implement ...

        cout << "Die Methode Tokenizer.tokenize ist noch nicht implementiert!" << endl; // remove this line
        // tokens->add(new Num()); // remove this line

        return tokens;
    }
    
};