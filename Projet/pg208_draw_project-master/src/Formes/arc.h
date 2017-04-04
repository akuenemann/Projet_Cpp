#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "forme.h"

class Arc : public Forme{
	protected:
		int rayon;
		int angle1;
		int angle2;

	public:
		Arc();
		Arc(int _x,int _y,int _rayon,int _angle1,int angle2,int _R,int _V,int _B,int _transparence, int _z):Forme(_x, _y,_R,_V,_B,_transparence,_z);
		~Arc();

		void tracerArc();
		void resizeArc(int echelle);
};
