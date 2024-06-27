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
        vector<Token*>* tokens;
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
		for (char ele : src) {
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
					Num n = addNewNum(numBuffer);
					numMode = -1;
					tokens->push_back(&n);
				}
				Op o = Op(ele);
				tokens->push_back(&o);

			}
			else if (ele == '(' || ele == ')') 
			{
				Bracket b = Bracket(ele);
				tokens->push_back(&b);
			}
		}

        cout << "Die Methode Tokenizer.tokenize ist noch nicht implementiert!" << endl; // remove this line
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

		Num addNewNum(std::vector<int> numBuffer) {
			int numToAdd = 0;
			int power = 0;
			std::reverse(numBuffer.begin(), numBuffer.end());
			for (int num : numBuffer) {
				numToAdd += num * pow(10, power);	
				power++;
			}
			std::cout << numToAdd << std::endl;
			Num newNum = Num(numToAdd);
			return newNum;
		}
		
};