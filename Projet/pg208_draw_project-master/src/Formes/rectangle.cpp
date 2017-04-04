#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "rectangle.h"

Rectangle::Rectangle(){
  longueur = 0;
  largeur = 0;
  angled = 0;
}

Rectangle::Rectangle(int _x,int _y,int _longueur,int _largeur,int _R,int _V,int _B,int _transparence,int _angled, int _z):Forme(_x, _y,_R,_V,_B,_transparence,_z){
  longueur = _longueur;
  largeur = _largeur;
  angled = _angled;
}

~Rectangle(){}



void tracerRectangle(){
  a = longueur*sin(angled);
  b = largeur*sin(angled);
  c = largeur*cos(angled);
  d = longueur*cos(angled);
  for (int i = y-a; i<=y+c; i++){
    for (int j = x; j<=x+b+d; j++){
      if (j ==  *i +)
    }
  }
}


void resizeRectangle(int echelle){
  x = echelle * x;
  y = echelle * y;
  epaisseur = echelle * epaisseur;
  longueur = echelle * longueur;
  largeur = echelle * largeur;
  angled = echelle * angled;
}
