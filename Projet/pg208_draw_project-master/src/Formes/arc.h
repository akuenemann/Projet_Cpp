#ifndef ARC
#define ARC

#include "cercle.h"

class Arc : public Cercle{
	private:
		int angle1;
		int angle2;
		
	public:
		Arc();
		Arc(int _x,int _y,int _rayon,int _angle1,int _angle2,int _R,int _V,int _B,int _transparence, int _z);
		Arc(string definition);
		~Arc();

		void dessiner(CImage* image);
		void resize(int echelle);
};

#endif