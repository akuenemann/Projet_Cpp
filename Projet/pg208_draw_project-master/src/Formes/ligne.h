#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "forme.h"
#include "../Image/CImage.h"

using namespace std;

class Ligne : public Forme{
	private:
		int x2, y2;

	public:
		Ligne();
		Ligne(int _x1,int _y1,int _x2,int _y2,int _R,int _V,int _B,int _transparence, int _z);
		~Ligne();

		void dessiner(CImage* image);
		void resize(int echelle);
};
