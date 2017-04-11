#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "../Image/CImage.h"
#include "ligne.h"

using namespace std;


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
  int miny = (y<=y2)?y:y2;
  int Maxy = (x>=x2)?x:x2;
  int a = (y2-y)/(x2-x);
  int b = y-a*x;

  for (int i = miny; i<=Maxy; i++){
    for (int j = minx; j<=Maxx; j++){
      if (j == a*i+b){
        CPixel* pix = image->getPixel(j,i);
        int rouge = (pix->Red()*(100-transparence)+transparence*R)/100;
        int vert = (pix->Green()*(100-transparence)+transparence*V)/100;
        int bleu = (pix->Blue()*(100-transparence)+transparence*B)/100;
        pix->RGB(rouge,vert,bleu);
      }
    }
  }
}



void Ligne::resize(int echelle){

}
