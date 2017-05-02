#ifndef FORME
#define FORME
#include "../Image/CImage.h"

class Forme{
	protected:
		int x, y;
		int R,V,B;
		int transparence;
		int z;
		int epaisseur;

	public:
		Forme();
		Forme(int _x, int _y, int _R, int _V, int _B, int _transparence, int _z);
		~Forme();

		virtual void dessiner(CImage* img) = 0;

};

#endif