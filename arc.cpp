#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#include "arc.h"

Arc::Arc():Cercle::Cercle(){
	angle1 = 0;
	angle2 = 0;
}

Arc::Arc(int _x,int _y,int _rayon,int _angle1,int _angle2,int _R,int _V,int _B,int _transparence, int _z):Cercle::Cercle(_x, _y, _rayon, _R, _V, _B, _transparence, _z){
	angle1 = _angle1;
	angle2 = _angle2;

}

void Arc::dessiner(CImage* image){
	float cos1 = cos(angle1*3.14/180.0f);
	float cos2 = cos(angle2*3.14/180.0f);
	
	float sin1 = sin(angle1*3.14/180.0f);
	float sin2 = sin(angle2*3.14/180.0f);
	
	float maxs = (sin1>sin2)?sin1:sin2;
	float mins = (sin1<sin2)?sin1:sin2;
	
	float maxc = (cos1>cos2)?cos1:cos2;
	float minc = (cos1<cos2)?cos1:cos2;
	
	for(int i = (x - rayon - epaisseur) ; i <= (x+rayon + epaisseur) ; i++){
		for(int j = (y - rayon - epaisseur) ; j <= (y+rayon+epaisseur) ; j++){
			int cerc = ((i-x)*(i-x)+(j-y)*(j-y));
			int boucle = abs(cerc - rayon*rayon);
			if( boucle < rayon*epaisseur){
				if(((i-x) > (minc*rayon)) && ((j-y) > (mins*rayon))){
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
		
		
void resize(int echelle){}
