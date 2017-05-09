#ifndef RECTANGLE
#define RECTANGLE


#include "ligne.h"


class Rectangle : public Forme{
	protected:
		int angled;
		int longueur;
		int largeur;
	public:
		Rectangle();
		Rectangle(int _x,int _y, int _longueur, int _largeur, int _angled, int _R,int _V,int _B,int _transparence, int _z);
		Rectangle(string definition);
		~Rectangle();

		void dessiner(CImage* image);
		void resize(int echelle);
};


class RectangleS : public Rectangle{
	public:
		RectangleS();
		RectangleS(int _x,int _y, int _longueur, int _largeur, int _angled, int _R,int _V,int _B,int _transparence, int _z);
		RectangleS(string definition);
		~RectangleS();
		void dessiner(CImage *image);
};

#endif