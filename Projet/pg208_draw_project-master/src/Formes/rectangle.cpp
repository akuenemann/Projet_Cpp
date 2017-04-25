#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <c++/4.8.3/cmath>

using namespace std;

#include "rectangle.h"

Rectangle::Rectangle() {
    angled = 0;
    longueur = 0;
    largeur = 0;
}

Rectangle::Rectangle(int _x, int _y, int _longueur, int _largeur, int _angled, int _R, int _V, int _B,
                     int _transparence, int _z) : Forme::Forme(_x, _y, _R, _V, _B, _transparence, _z) {
    angled = _angled;
    longueur = _longueur;
    largeur = _largeur;
    x = _x;
    y = _y;
    R = _R;
    V = _V;
    B = _B;
    transparence = _transparence;
    z = _z;
}

Rectangle::~Rectangle() {}


void Rectangle::dessiner(CImage *image) {

    int a = longueur * sin(angled * 3.14f / 180.0f);
    int b = largeur  * sin(angled * 3.14f / 180.0f);
    int c = largeur  * cos(angled * 3.14f / 180.0f);
    int d = longueur * cos(angled * 3.14f / 180.0f);

    Ligne* l1 = new Ligne(x, y, x + d, y - a, R, V, B, transparence, z);
    Ligne* l2 = new Ligne(x, y, x + b, y + c, R, V, B, transparence, z);
    Ligne* l3 = new Ligne(x + d, y - a, x + b + d, y - a + c, R, V, B, transparence, z);
    Ligne* l4 = new Ligne(x + b, y + c, x + b + d, y - a + c, R, V, B, transparence, z);

    l1->dessiner(image);
    l2->dessiner(image);
    l3->dessiner(image);
    l4->dessiner(image);

    delete(l1);
    delete(l2);
    delete(l3);
    delete(l4);
}


void Rectangle::resize(int echelle) {
    longueur = longueur * echelle;
    largeur = largeur * echelle;
    epaisseur = epaisseur * echelle;
}

RectangleS::RectangleS():Rectangle::Rectangle(){}
RectangleS::RectangleS(int _x,int _y, int _longueur, int _largeur, int _angled, int _R,int _V,int _B,int _transparence, int _z):Rectangle::Rectangle(_x, _y, _longueur, _largeur, _angled, _R, _V, _B, _transparence, _z){}
RectangleS::~RectangleS(){}

void RectangleS::dessiner(CImage *image){
    int a = longueur * sin(angled * 3.14f / 180.0f);
    int b = largeur  * sin(angled * 3.14f / 180.0f);
    int c = largeur  * cos(angled * 3.14f / 180.0f);
    int d = longueur * cos(angled * 3.14f / 180.0f);



    if(b == 0){
        for(int i = 0 ; i < largeur ; i++) {
            Ligne *l = new Ligne(x, y + i, x + d, y + i - a, R, V, B, transparence, z);
            l->dessiner(image);
            delete (l);
        }
    }
    else if(c == 0){
        for(int i = 0 ; i < largeur ; i++) {
            Ligne *l = new Ligne(x+i, y, x + i + d, y - a, R, V, B, transparence, z);
            l->dessiner(image);
            delete (l);
        }

    }
    else{
        float coef = (float) (c / (float) b);
        int offset = y - coef*x;
        for(int i = 0 ; i < largeur ; i++){
            Ligne* l = new Ligne((int) (((float)(y+i-offset)/coef)), y+i, (int) (((float)(y+i-offset)/coef)) + d, y+i - a, R, V, B, transparence, z);
            l->dessiner(image);
            delete(l);
        }
    }



}

