#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "ligne.h"

using namespace std;

class Rectangle : public Ligne{
	protected:
		int longueur;
		int largeur;
		int angled;

	public:
		Rectangle();
		Rectangle(int _x,int _y,int _longueur,int _largeur,int _R,int _V,int _B,int _transparence,int _angled, int _z):Forme(_x, _y,_R,_V,_B,_transparence,_z);
		~Rectangle();

		void tracerRectangle();
		void resizeRectangle(int echelle);
};


class RectangleS : public Rectangle{
	public:
		void colorierRectangleS();
};
