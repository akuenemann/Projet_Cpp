#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "cercle.h"

class Arc : public Cercle{
	private:
		int angle1;
		int angle2;
		
	public:
		Arc();
		Arc(int _x,int _y,int _rayon,int _angle1,int _angle2,int _R,int _V,int _B,int _transparence, int _z);

		void dessiner(CImage* image);
		void resize(int echelle);
};


