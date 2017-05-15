#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "cercle.h"


Cercle::Cercle():Forme::Forme(){
	rayon = 0;
}

Cercle::Cercle(int _x,int _y,int _rayon,int _R,int _V,int _B,int _transparence, int _z):Forme::Forme(_x, _y, _R, _V, _B, _transparence, _z){
	rayon = _rayon;
}

Cercle::Cercle(string definition) {
	istringstream def(definition);
	string element;

	getline(def, element, ':');

	getline(def, element, ',');
	x = stoi(element);

	getline(def, element, ',');
	y = stoi(element);

	getline(def, element, ',');
	rayon = stoi(element);

	getline(def, element, ',');
	R = stoi(element);

	getline(def, element, ',');
	V = stoi(element);

	getline(def, element, ',');
	B = stoi(element);

	getline(def, element, ',');
	transparence = stoi(element);

	getline(def, element, ';');
	z = stoi(element);
}

Cercle::~Cercle(){}

void Cercle::dessiner(CImage* image){
	for(int i = (x - rayon - epaisseur) ; i <= (x+rayon + epaisseur) ; i++){
		for(int j = (y - rayon - epaisseur) ; j <= (y+rayon+epaisseur) ; j++){
			int cerc = ((i-x)*(i-x)+(j-y)*(j-y));
			int boucle = abs(cerc - rayon*rayon);
			if( boucle < rayon*epaisseur){
				CPixel* pix = image->getPixel(i,j);
				int rouge   = (pix->Red()*(100-transparence)+transparence*R)/100;
				int vert    = (pix->Green()*(100-transparence)+transparence*V)/100;
				int bleu    = (pix->Blue()*(100-transparence)+transparence*B)/100;
				pix->RGB(rouge,vert,bleu);
			}
			
		}
		
	} 

}

void Cercle::resize(int echelle){
	epaisseur = epaisseur*echelle;
	rayon     = rayon*echelle;
	x = x*echelle;
	y = y*echelle;

}



CercleS::CercleS():Cercle::Cercle(){}

CercleS::CercleS(string definition):Cercle::Cercle(definition){}

CercleS::CercleS(int _x,int _y,int _rayon, int _R,int _V,int _B,int _transparence, int _z):Cercle::Cercle(_x, _y, _rayon, _R, _V, _B, _transparence, _z){}

CercleS::~CercleS(){}

void CercleS::dessiner(CImage* image){
	for(int i = (x - rayon - epaisseur) ; i <= (x+rayon + epaisseur) ; i++){
		for(int j = (y - rayon - epaisseur) ; j <= (y+rayon+epaisseur) ; j++){
			int cerc = ((i-x)*(i-x)+(j-y)*(j-y));
			if( cerc < rayon*rayon){
				CPixel* pix = image->getPixel(i,j);
				int rouge   = (pix->Red()*(100-transparence)+transparence*R)/100;
				int vert    = (pix->Green()*(100-transparence)+transparence*V)/100;
				int bleu    = (pix->Blue()*(100-transparence)+transparence*B)/100;
				pix->RGB(rouge,vert,bleu);
			}
			
		}
		
	}

}









