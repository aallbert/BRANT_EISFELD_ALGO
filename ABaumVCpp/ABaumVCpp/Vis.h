#include "Token.h"
#include "helperFile.h"
#include <iomanip>

/*
 * Visualisierung eines arithmetischen Bin�rbaums
 */
class Vis
{
    Token *tree;
    int spacing;
    int width;
    int height;

public:
	
    static const int REGULAR = 1; // Darstellung mit gleichen Abst�nden zwischen Knoten
    static const int BINARY = 2;  // Darstellung mit fortlaufend halbierten Abst�nden

    /*
     * Erzeugt das Text-/Grafikfenster.
     * 
     * Parameter: t darzustellender Baum
     * Parameter: s Spacing: Vis.REGULAR oder Vis.BINARY
     */
    Vis(Token *t, int s) 
	{
        tree = t;
        spacing = s;
    
		// ...
    }
    
    /*
     * Zeichnet einen Baumknoten.
     * 
     * Parameter: x x-Position (Mittelpunkt des Knotens)
     * Parameter: y y-Position (Mittelpunkt des Knotens)
     * Parameter: node darzustellender Baumknoten
     */
    void drawSingleNode(int x, int y, Token *node) 
	{

		// ...
	}
    
    /*
     * Zeichnet einen Baum mit gleichmaessigem Abstand zwischen Knoten.
     * 
     * Parameter: t darzustellender Baum
     */
    void drawTreeReg(Token *t) 
	{
        drawTreeReg(t, 0, 100);
    }
    
    /*
     * Zeichnet einen Baum mit gleichmaessigem Abstand zwischen Knoten.
     * 
     * Parameter: t darzustellender Baum
     * Parameter: depth aktuelle Tiefenebene im Baum
     * Parameter: xorig x-Position des Vaterknotens
     */
    void drawTreeReg(Token *t, int depth, int xorig) 
    // Nicht wirklich implementiert, muss überarbeitet werden
	{
      if (t == nullptr) {
        return;
    }

    char type = t->getType();
    int spacing = 5;  // Adjust spacing based on the depth

    if (type == '+' || type == '-' || type == '*' || type == '/') {
        cout << setw(xorig) << type << endl;
        drawTreeReg(t->left(), depth + 1,  xorig - spacing);
        drawTreeReg(t->right(), depth + 1,  xorig + spacing);
    } else {
        for (int i = 0; i < xorig; ++i) {
            cout << " ";
        }
        Num* numToken = dynamic_cast<Num*>(t);
        if (numToken) {
            cout << numToken->eval();
        } else {
            cout << type;
        }
    }
		// ...
	}
    
    /*
     * Zeichnet einen Baum mit fortlaufend halbierten Abstaenden.
     * 
     * Parameter: t darzustellender Baum
     */
    void drawTreeBin(Token *t) 
	{
        drawTreeBin(t, 0, "", 100);
    }

    /*
     * Zeichnet einen Baum mit fortlaufend halbierten Abstaenden.
     * 
     * Parameter: t darzustellender Baum
     * Parameter: depth aktuelle Tiefenebene im Baum
     * Parameter: history Pfad bestehend aus "l" und "r" von der Wurzel zum aktuellen Knoten
     * Parameter: xorig x-Position des Vaterknotens
     */
void drawTreeBin(Token *t, int depth, string history, int xorig) {
    if (t == nullptr) {
        return;
    }

    char type = t->getType();
    int spacing = 80 / customPow(2, depth + 1);  // Adjust spacing based on the depth

    if (type == '+' || type == '-' || type == '*' || type == '/') {
        cout << setw(xorig) << type << endl;
        drawTreeBin(t->left(), depth + 1, history + 'l', xorig - spacing);
        drawTreeBin(t->right(), depth + 1, history + 'r', xorig + spacing);
    } else {
        int padding = history.back() == 'l' ? -spacing / 2 : spacing / 2;
        int position = xorig + padding;
        for (int i = 0; i < position; ++i) {
            cout << " ";
        }
        Num* numToken = dynamic_cast<Num*>(t);
        if (numToken) {
            cout << numToken->eval();
        } else {
            cout << type;
        }
        cout << " " << history << std::endl;
    }
}	

    /*
     * Zeichnen des Baums und Anzeige des Grafikfensters
     */
    void paint() 
	{

		if (spacing == REGULAR) 
		{
            Order* o = new Order(); // Zaehler
            tree->order(o); // Baum in Infix-Reihenfolge nummerieren
            drawTreeReg(tree);
        } else 
			drawTreeBin(tree);
    }

};