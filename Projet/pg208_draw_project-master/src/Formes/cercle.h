#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "arc.h"

class Cercle : public Arc{
	public:
		Cercle();
		Cercle(int _x,int _y,int _rayon,int _angle1,int angle2,int _R,int _V,int _B,int _transparence, int _z):Forme(_x, _y,_R,_V,_B,_transparence,_z);
		~Cercle();

		void tracerCercle();
		void resizeCercle(int echelle);
};

class CercleS : public Cercle{
	public:
		void colorierCercleS();
};
