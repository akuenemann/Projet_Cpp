#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

#include "forme.h"

Forme::Forme(){
  x = 0;
  y = 0;
  R = 0;
  V = 0;
  B = 0;
  transparence = 0;
  z = 0;
  epaisseur = 1;
}

Forme::Forme(int _x, int _y, int _R, int _V, int _B, int _transparence, int _z){
  x = _x;
  y = _y;
  R = _R;
  V = _V;
  B = _B;
  transparence = _transparence;
  z = _z;
  epaisseur = 1;
}

Forme::~Forme(){}


int Forme::getz() {
  return z;
}