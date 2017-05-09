#ifndef CERCLE
#define CERCLE

#include "forme.h"

class Cercle : public Forme{
	protected:
		int rayon;

	public:
		Cercle();
		Cercle(int _x,int _y,int _rayon, int _R,int _V,int _B,int _transparence, int _z);
		Cercle(string definition);
		~Cercle();

		void dessiner(CImage* image);
		void resize(int echelle);
};

class CercleS : public Cercle{
	public:
		CercleS();
		CercleS(int _x,int _y,int _rayon, int _R,int _V,int _B,int _transparence, int _z);
		CercleS(string definition);
		~CercleS();

		void dessiner(CImage* image);


};

#endif