#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "ligne.h"

using namespace std;

class Rectangle : public Ligne{
	protected:
		Ligne* bord[4];

	public:
		Rectangle();
		Rectangle(int _x,int _y,int _R,int _V,int _B,int _transparence):Forme(_x, _y,_R,_V,_B,_transparence,_z);
		~Rectangle();

		void tracerRectangle();
		void resizeRectangle(int echelle);
};


class RectangleS : public Rectangle{
	public:
		void colorierRectangleS();
};
