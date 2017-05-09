#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#include "../Traitement/couleur.h"
#include "carre.h"

	Carre::Carre():Rectangle::Rectangle(){}
	Carre::Carre(int _x,int _y, int _cote, int _angled, int _R,int _V,int _B,int _transparence, int _z):Rectangle::Rectangle(_x, _y, _cote, _cote, _angled, _R, _V, _B, _transparence, _z){}
	Carre::Carre(string definition){
		istringstream def(definition);
		string element;

		getline(def,element,':');

		getline(def,element,',');
		x = stoi(element);

		getline(def,element,',');
		y = stoi(element);

		getline(def,element,',');
		longueur = stoi(element);
		largeur = longueur;

		getline(def,element,',');
		angled = stoi(element);

		getline(def,element,',');
		R = stoi(element);

		getline(def,element,',');
		V = stoi(element);

		getline(def,element,',');
		B = stoi(element);

		getline(def,element,',');
		transparence = stoi(element);

		getline(def,element,';');
		z = stoi(element);


		/*vector<int> RVB = getCouleur(element);
		R = RVB[0];
		V = RVB[1];
		B = RVB[2];*/
	}
	Carre::~Carre(){}



	CarreS::CarreS(){}

	CarreS::CarreS(string definition){
		istringstream def(definition);
		string element;

		getline(def,element,':');

		getline(def,element,',');
		x = stoi(element);

		getline(def,element,',');
		y = stoi(element);

		getline(def,element,',');
		longueur = stoi(element);
		largeur = longueur;

		getline(def,element,',');
		angled = stoi(element);

		getline(def,element,',');
		R = stoi(element);

		getline(def,element,',');
		V = stoi(element);

		getline(def,element,',');
		B = stoi(element);

		getline(def,element,',');
		transparence = stoi(element);

		getline(def,element,';');
		z = stoi(element);
	}

	CarreS::CarreS(int _x,int _y, int _cote, int _angled, int _R,int _V,int _B,int _transparence, int _z):RectangleS::RectangleS(_x, _y, _cote, _cote, _angled, _R, _V, _B, _transparence, _z){}
	CarreS::~CarreS(){}

