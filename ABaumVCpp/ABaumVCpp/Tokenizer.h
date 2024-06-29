#include <string>
#include <vector>
#include <algorithm>

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

		Beispiel f�r das Einf�gen von Knoten:

		i = tokens->insert(i, new Op(c));
		i = tokens->insert(i, new Num(c));
		usw. 
		
		*/
		
		// to implement ...
		std::vector<int> numBuffer;

		bool numMode = 0;
		for (int k = 0; k < src.length(); k++) {
			char ele = src[k];
			std::cout << ele << std::endl;
			if (contains(nums, ele)) 
			{
				numMode = 1;
				numBuffer.push_back(int(ele) - 48);
			}
			else if (contains(operators, ele)) 
			{
				if (numMode == 1) 
				{
					Num* n = new Num(getComposedInt(numBuffer));
					numMode = -1;
					numBuffer.clear();
					i = tokens->insert(i, n);
					++i;
				}
				Op* o = new Op(ele);
				i = tokens->insert(i, o);
				++i;
			}
			else if (ele == '(' || ele == ')') 
			{
				if (numMode == 1) 
				{
					Num* n = new Num(getComposedInt(numBuffer));
					numMode = -1;
					numBuffer.clear();
					i = tokens->insert(i, n);
					++i;
				}

				Bracket* b = new Bracket(ele);
				i = tokens->insert(i, b);
				++i;
			}
			else 
			{
				std::cout << "not relevant" << std::endl;
			}
		}

        // cout << "Die Methode Tokenizer.tokenize ist noch nicht implementiert!" << endl; // remove this line
        // tokens->add(new Num()); // remove this line

        return tokens;
    }
    private:
		// Array with numbers as characters
    	std::vector<char> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    	// Array with mathematical operators
    	std::vector<char> operators = {'+', '-', '*', '/'};

		
		template <class T> bool contains(std::vector<T> listLike, T ele) {
			return std::find(std::begin(listLike), std::end(listLike), ele) != std::end(listLike); 
		}

		int getComposedInt(std::vector<int> numBuffer) {
			int numToAdd = 0;
			int power = 0;
			std::reverse(numBuffer.begin(), numBuffer.end());
			for (int num : numBuffer) {
				numToAdd += num * pow(10, power);	
				power++;
			}
			return numToAdd;
		}
		
};