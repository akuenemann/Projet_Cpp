#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "forme.h"

class Cercle : public Forme{
	protected:
		int rayon;

	public:
		Cercle();
		Cercle(int _x,int _y,int _rayon, int _R,int _V,int _B,int _transparence, int _z);
		~Cercle();

		void dessiner(CImage* image);
		void resize(int echelle);
};

class CercleS : public Cercle{
	public:
		CercleS();
		CercleS(int _x,int _y,int _rayon, int _R,int _V,int _B,int _transparence, int _z);
		~CercleS();
		void dessiner(CImage* image);


};
