#include "Token.h"
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
        drawTreeReg(t, 0, 0);
    }
    
    /*
     * Zeichnet einen Baum mit gleichmaessigem Abstand zwischen Knoten.
     * 
     * Parameter: t darzustellender Baum
     * Parameter: depth aktuelle Tiefenebene im Baum
     * Parameter: xorig x-Position des Vaterknotens
     */
    void drawTreeReg(Token *t, int depth, int xorig) 
	{
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
	void drawTreeBin(Token *t, int depth, string history, int xorig) 
	{
        char type = t->type; 

        if (type == '+' || type == '-' || type == '*' || type == '/') {
            int newXOrig = xorig / pow(2, depth);
            std::cout << std::setw(newXOrig) << type << std::endl;
            history += 'o';
            drawTreeBin(t->left(), depth + 1, history += 'l', newXOrig);
            drawTreeBin(t->right(), depth + 1, history += 'r', newXOrig);

        } else {
            int padding = history[history.length() - 1] == 'l' ? - 5 : 5;
            int paddingFull = 0;
            if (history[history.length() - 1] == 'l') {
                paddingFull = xorig + padding;
            } else if (history[history.length() - 1] == 'r') {
                paddingFull = 2 * padding;
            } else {
               paddingFull = 2 * xorig; 
            } 

            for (int i = 0; i < paddingFull ; i++) {
                std::cout << " ";
            }
            std::cout << type << " " << history;
            if (padding == 5) std::cout << std::endl << std::endl << std::endl;
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