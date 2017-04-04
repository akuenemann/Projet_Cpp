#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "rectangle.h"

class Carre : public Rectangle{
	public:
		Carre();
		Carre(int _x1,int _y1,int _x2,int _y2,int _R,int _V,int _B,int _transparence):Forme(_x1, _y1,_R,_V,_B,_transparence,_z);
		~Carre();

		void tracerCarre();
		void resizeCarre(int echelle);
};

class CarreS : public Carre{
	void tracerCarreS();
};
