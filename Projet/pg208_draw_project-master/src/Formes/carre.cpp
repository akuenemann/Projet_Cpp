#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "carre.h"

	Carre::Carre():Rectangle::Rectangle(){}
	Carre::Carre(int _x,int _y, int _cote, int _angled, int _R,int _V,int _B,int _transparence, int _z):Rectangle::Rectangle(_x, _y, _cote, _cote, _angled, _R, _V, _B, _transparence, _z){}
	Carre::~Carre(){}



	CarreS::CarreS(){}
	CarreS::CarreS(int _x,int _y, int _cote, int _angled, int _R,int _V,int _B,int _transparence, int _z):RectangleS::RectangleS(_x, _y, _cote, _cote, _angled, _R, _V, _B, _transparence, _z){}
	CarreS::~CarreS(){}

