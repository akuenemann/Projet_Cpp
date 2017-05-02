#ifndef LIGNE
#define LIGNE

#include "forme.h"

class Ligne : public Forme{
	private:
		int x2, y2;

	public:
		Ligne();
		Ligne(int _x1,int _y1,int _x2,int _y2,int _R,int _V,int _B,int _transparence, int _z);
		~Ligne();

		void dessiner(CImage* image);
		void resize(int echelle);
		void set_coord(int xi, int yi, int xf, int yf );
};

#endif