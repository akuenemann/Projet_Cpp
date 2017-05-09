#ifndef TRIANGLE
#define TRIANGLE

#include "ligne.h"


class Triangle : public Forme{
	protected:
		int x1;
		int x2;
		int y1;
		int y2;
	public:
		Triangle();
		Triangle(int _x,int _y, int _x1, int _y1, int _x2, int _y2, int _R,int _V,int _B,int _transparence, int _z);
		Triangle(string definition);
		~Triangle();

		void dessiner(CImage* image);
		void resize(int echelle);
};


class TriangleS : public Triangle{
	public:
		TriangleS();
		TriangleS(int _x,int _y, int _x1, int _y1, int _x2, int _y2, int _R,int _V,int _B,int _transparence, int _z);
		~TriangleS();
		void dessiner(CImage *image);
};

#endif