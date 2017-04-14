#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "../Image/CImage.h"
#include "ligne.h"

using namespace std;

void swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

Ligne::Ligne(){
  x2 = 0;
  y2 = 0;
}

Ligne::Ligne(int _x1,int _y1,int _x2,int _y2,int _R,int _V,int _B,int _transparence,int _z):Forme::Forme(_x1, _y1,_R,_V,_B,_transparence,_z){
  x2 = _x2;
  y2 = _y2;
}
Ligne::~Ligne(){}


void Ligne::dessiner(CImage* image){
	int minx = (x<=x2)?x:x2;
	int Maxx = (x>=x2)?x:x2;

	bool s = false;

	if ( x2 == x ){
		int miny = (y<=y2)?y:y2;
		int maxy = (y>=y2)?y:y2;
		for (int y_courant = miny ; y_courant < maxy ; y_courant++){
			for(int i = 0 ; i <= epaisseur ; i++){
				CPixel* pix = image->getPixel(x+i,y_courant);
				int rouge = (pix->Red()*(100-transparence)+transparence*R)/100;
				int vert = (pix->Green()*(100-transparence)+transparence*V)/100;
				int bleu = (pix->Blue()*(100-transparence)+transparence*B)/100;
				pix->RGB(rouge,vert,bleu);
			}
		}
	}
	else if (y2 == y){
		int minx   = (x<=x2)?x:x2;
		int maxx   = (x>=x2)?x:x2;
		for (int x_courant = minx ; x_courant < maxx ; x_courant++){
			for (int i  = 0; i <= epaisseur ; i++){
					CPixel* pix = image->getPixel(x_courant,y-i);
					int rouge   = (pix->Red()*(100-transparence)+transparence*R)/100;
					int vert    = (pix->Green()*(100-transparence)+transparence*V)/100;
					int bleu    = (pix->Blue()*(100-transparence)+transparence*B)/100;
					pix->RGB(rouge,vert,bleu);
			}
		}
	}
	else{
		if ( (y2 - y)/(x2 - x) < 1){
			swap(&x, &y);
			swap(&x2, &y2);
			s = true;
		}

		float coef = (y2 - y)/(x2 - x);
		float offset = y - coef * x;
		int minx   = (x<=x2)?x:x2;
		int maxx   = (x>=x2)?x:x2;

		int y_courant = 0;
		for (int x_courant = minx ; x_courant < maxx ; x_courant++){
			y_courant = coef*x_courant + offset;
			if(!s){
				for (int i  = 0; i <=  abs((int) coef*epaisseur); i++){
					for(int j = 0 ; j <= abs((int)coef*epaisseur) ; j++){
						CPixel* pix = image->getPixel(x_courant+i,y_courant-j);
						int rouge   = (pix->Red()*(100-transparence)+transparence*R)/100;
						int vert    = (pix->Green()*(100-transparence)+transparence*V)/100;
						int bleu    = (pix->Blue()*(100-transparence)+transparence*B)/100;
						pix->RGB(rouge,vert,bleu);
					}
				}
			}
			else{
				for (int i  = 0; i <= abs((int)coef*epaisseur); i++){
					for(int j = 0 ; j <= abs((int)coef*epaisseur) ; j++){
						CPixel* pix = image->getPixel(y_courant+i,x_courant-j);
						int rouge = (pix->Red()*(100-transparence)+transparence*R)/100;
						int vert = (pix->Green()*(100-transparence)+transparence*V)/100;
						int bleu = (pix->Blue()*(100-transparence)+transparence*B)/100;
						pix->RGB(rouge,vert,bleu);
					}
				}
			}
		}
	}
}



void Ligne::resize(int echelle){
	epaisseur = echelle;
}
