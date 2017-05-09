#ifndef CARRE
#define CARRE

#include "rectangle.h"


class Carre : public Rectangle{
	public:
		Carre();
		Carre(int _x,int _y, int _cote, int _angled, int _R,int _V,int _B,int _transparence, int _z);
		Carre(string definition);
		~Carre();
};

class CarreS : public RectangleS{
	public:
		CarreS();
		CarreS(string definition);
		CarreS(int _x,int _y, int _cote, int _angled, int _R,int _V,int _B,int _transparence, int _z);
		~CarreS();
};

#endif