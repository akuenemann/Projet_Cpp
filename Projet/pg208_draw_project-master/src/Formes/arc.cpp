#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int quartier(int angle){
	if(angle <= 90){
		return 1;
	}
	else if(angle <= 180){
		return 2;
	}
	else if(angle <= 270){
		return 3;
	}
	else{
		return 4;
	}

}

#include "arc.h"

Arc::Arc():Cercle::Cercle(){
	angle1 = 0;
	angle2 = 0;
}

Arc::Arc(int _x,int _y,int _rayon,int _angle1,int _angle2,int _R,int _V,int _B,int _transparence, int _z):Cercle::Cercle(_x, _y, _rayon, _R, _V, _B, _transparence, _z){
	angle1 = _angle1;
	angle2 = _angle2;

}

Arc::Arc(string definition) {
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
	angle1 = stoi(element);

	getline(def, element, ',');
	angle2 = stoi(element);

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


Arc::~Arc(){}

void Arc::dessiner(CImage* image){

	angle1 = angle1%361;
	angle2 = angle2%361;	
	
	float sin1 = sin(angle1*3.14/180.0f);
	float sin2 = sin(angle2*3.14/180.0f);
	
	int quartier1 = quartier(angle1);
	int quartier2 = quartier(angle2);
	
	int min1 = y;
	int max1 = (y+rayon+epaisseur);
	
	int min2 = y;
	int max2 = (y+rayon+epaisseur);
	
	int min3 = (y-rayon-epaisseur);
	int max3 = y;
	
	int min4 = (y-rayon-epaisseur);
	int max4 = y;
	
	if(quartier1 == 1){
		min1 += (sin1)*rayon;
	}
	else if(quartier1 == 2){
		max2 -= (1-sin1)*rayon;
	}
	else if(quartier1 == 3){
		max3 += (sin1)*rayon; //sin negatif
	}
	else{
		min4 += (1+sin1)*rayon;
	}
	
	if(quartier2 == 1){
		max1 -= (1-sin2)*rayon;
	}
	else if(quartier2 == 2){
		min2 += (sin2)*rayon;
	}
	else if(quartier2 == 3){
		min3 += (1+sin2)*rayon;
	}
	else{
		max4 += (sin2)*rayon;
	}

	
	
	
	int q1, q2, q3, q4;
	int bq1 = 0;
	int bq2 = 0;
	int bq3 = 0;
	int bq4 = 0;
	
	if(quartier1 == 1 && quartier2 == 1){
		if(angle1 > angle2){
			q1 = 1;
			q2 = 1;
			q3 = 1;
			q4 = 1;
			bq1 = 1;
		}
		else{
			q1 = 1;
			q2 = 0;
			q3 = 0;
			q4 = 0;
		}
	}
	else if(quartier1 == 1 && quartier2 == 2){
		q1 = 1;
		q2 = 1;
		q3 = 0;
		q4 = 0;
	}
	else if(quartier1 == 1 && quartier2 == 3){
		q1 = 1;
		q2 = 1;
		q3 = 1;
		q4 = 0;
	}
	else if(quartier1 == 1 && quartier2 == 4){
		q1 = 1;
		q2 = 1;
		q3 = 1;
		q4 = 1;
	}

	
	else if(quartier1 == 2 && quartier2 == 2){
		if(angle1 > angle2){
			q1 = 1;
			q2 = 1;
			q3 = 1;
			q4 = 1;
			bq2 = 1;
		}
		else{
			q1 = 0;
			q2 = 1;
			q3 = 0;
			q4 = 0;
		}
	}
	else if(quartier1 == 2 && quartier2 == 3){
		q1 = 0;
		q2 = 1;
		q3 = 1;
		q4 = 0;
	}
	else if(quartier1 == 2 && quartier2 == 4){
		q1 = 0;
		q2 = 1;
		q3 = 1;
		q4 = 1;
	}
	else if(quartier1 == 2 && quartier2 == 1){
		q1 = 1;
		q2 = 1;
		q3 = 1;
		q4 = 1;
	}
	
	
	else if(quartier1 == 3 && quartier2 == 3){
		if(angle1 > angle2){
			q1 = 1;
			q2 = 1;
			q3 = 1;
			q4 = 1;
			bq3 = 1;
		}
		else{
			q1 = 0;
			q2 = 0;
			q3 = 1;
			q4 = 0;
		}
	}
	else if(quartier1 == 3 && quartier2 == 4){
		q1 = 0;
		q2 = 0;
		q3 = 1;
		q4 = 1;
	}
	else if(quartier1 == 3 && quartier2 == 1){
		q1 = 1;
		q2 = 0;
		q3 = 1;
		q4 = 1;
	}
	else if(quartier1 == 3 && quartier2 == 2){
		q1 = 1;
		q2 = 1;
		q3 = 1;
		q4 = 1;
	}
	
	else if(quartier1 == 4 && quartier2 == 4){
		if(angle1 > angle2){
			q1 = 1;
			q2 = 1;
			q3 = 1;
			q4 = 1;
			bq4 = 1;
		}
		else{
			q1 = 0;
			q2 = 0;
			q3 = 0;
			q4 = 1;
		}
	}
	else if(quartier1 == 4 && quartier2 == 1){
		q1 = 1;
		q2 = 0;
		q3 = 0;
		q4 = 1;
	}
	else if(quartier1 == 4 && quartier2 == 2){
		q1 = 1;
		q2 = 1;
		q3 = 0;
		q4 = 1;
	}
	else if(quartier1 == 4 && quartier2 == 3){
		q1 = 1;
		q2 = 1;
		q3 = 1;
		q4 = 1;
	}

	
	//Quartier 1
	if(q1){
	if(bq1 == 1 && angle1 > angle2){
		for(int i = (x) ; i <= (x+rayon + epaisseur) ; i++){
			for(int j = y+sin1*rayon ; j <= y+rayon+epaisseur ; j++){
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
			for(int j = y ; j <= y+sin2*rayon ; j++){
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
	else{
	for(int i = (x) ; i <= (x+rayon + epaisseur) ; i++){
		for(int j = min1 ; j <= max1 ; j++){
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
	}
	
	//Quartier 2
	if(q2){
	if(bq2 == 1 && angle1 > angle2){
		for(int i = (x-rayon - epaisseur) ; i <= (x) ; i++){
			for(int j = y ; j <= y+sin1*rayon ; j++){
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
			for(int j = y+sin2*rayon ; j <= y+rayon+epaisseur ; j++){
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
	else{
	for(int i = (x-rayon - epaisseur) ; i <= (x) ; i++){
		for(int j = min2 ; j <= max2 ; j++){
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
	}
	
	//Quartier 3
	if(q3){
	if(bq3 == 1 && angle1 > angle2){
	for(int i = (x-rayon - epaisseur) ; i <= (x) ; i++){
		for(int j = y+sin2*rayon ; j <= y ; j++){
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
		for(int j = y-rayon-epaisseur ; j <= y-rayon-epaisseur+(1+sin1)*rayon ; j++){
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
	else{
	for(int i = (x-rayon - epaisseur) ; i <= (x) ; i++){
		for(int j = min3 ; j <= max3 ; j++){
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
	}

	//Quartier 4
	if(q4){
	if(bq4 == 1 && angle1 > angle2){
		for(int i = (x) ; i <= (x + rayon + epaisseur) ; i++){
		for(int j = y+sin1*rayon ; j <= y ; j++){
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
		for(int j = y-rayon-epaisseur ; j <= y-rayon-epaisseur+(1+sin2)*rayon ; j++){
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
	else{
	for(int i = (x) ; i <= (x + rayon + epaisseur) ; i++){
		for(int j = min4 ; j <= max4 ; j++){
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
	}
}
		
		
void Arc::resize(int echelle){
	epaisseur = epaisseur*echelle;
	rayon = rayon*echelle;

}
