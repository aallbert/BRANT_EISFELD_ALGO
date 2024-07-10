#ifndef TOKENIZER
#define TOKENIZER
#include <string>
#include <vector>
#include <algorithm>

#include "Num.h"
#include "Bracket.h"
#include "Op.h"
#include "helperFile.h"

using namespace std;

/*
 * Klasse zur Zerlegung eines arithmetischen Ausdrucks in Tokens
 */
class Tokenizer 
{
    string src; // Der arithmetische Ausdruck als String

public:
    /*
     * Konstruktor: Initialisiert den Tokenizer mit einem Ausdruck.
     *
     * Parameter:
     * - s: der arithmetische Ausdruck als String
     */
    Tokenizer(string s) 
    {
        src = s + " "; // Das Leerzeichen dient dazu, beim Lesen von Zahlen nicht 
                       // über die String-Grenze zu laufen
    }
    
    /*
     * Zerlegt den arithmetischen Ausdruck in Tokens.
     *
     * Return: Ein Vektor von Zeigern auf Tokens
     */
    vector<Token*>* tokenize() 
    {
        vector<Token*>* tokens = new vector<Token*>();
        vector<Token*>::iterator i = tokens->begin();

        std::vector<int> numBuffer;
        bool numMode = 0;

        for (int k = 0; k < src.length(); k++) {
            char ele = src[k];
            if (contains(nums, ele)) 
            {
                numMode = 1;
                numBuffer.push_back(int(ele) - 48); // ASCII zu int
            }
            else if (contains(operators, ele)) 
            {
                if (numMode == 1) 
                {
                    Num* n = new Num(getComposedInt(numBuffer));
                    numMode = 0;
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
                    numMode = 0;
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
                if (numMode == 1) 
                {
                    Num* n = new Num(getComposedInt(numBuffer));
                    numMode = 0;
                    numBuffer.clear();
                    i = tokens->insert(i, n);
                    ++i;
                }
            }
        }

        return tokens;
    }

private:
    // Array mit Zahlen als Zeichen
    std::vector<char> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    // Array mit mathematischen Operatoren
    std::vector<char> operators = {'+', '-', '*', '/'};

    /*
     * Hilfsmethode, um zu prüfen, ob ein Element in einem Vektor enthalten ist.
     *
     * Parameter: 
     * - listLike: Vektor der Elemente
     * - ele: Element, nach dem gesucht wird
     * 
     * Return: true, wenn das Element enthalten ist, sonst false
     */
    template <class T> bool contains(std::vector<T> listLike, T ele) {
        return std::find(std::begin(listLike), std::end(listLike), ele) != std::end(listLike); 
    }

    /*
     * Hilfsmethode, um aus einem Vektor von Ziffern eine Zahl zu erstellen.
     *
     * Parameter:
     * - numBuffer: Vektor von Ziffern (als int)
     * 
     * Return: Die zusammengesetzte Zahl (als int)
     */
    int getComposedInt(std::vector<int> numBuffer) {
        int numToAdd = 0;
        int power = 0;
        std::reverse(numBuffer.begin(), numBuffer.end());
        for (int num : numBuffer) {
            numToAdd += num * customPow(10, power);    
            power++;
        }
        return numToAdd;
    }
};

#endif
