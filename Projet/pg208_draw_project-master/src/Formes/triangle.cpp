#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "triangle.h"

Triangle::Triangle() {
    x1 = 0;
    x2 = 0;
    y1 = 0;
    y2 = 0;
}

Triangle::Triangle(int _x,int _y, int _x1, int _y1, int _x2, int _y2, int _R,int _V,int _B,int _transparence, int _z)
        : Forme::Forme(_x, _y, _R, _V, _B, _transparence, _z) {
    x1 = _x1;
    x2 = _x2;
    y1 = _y1;
    y2 = _y2;
    x = _x;
    y = _y;
    R = _R;
    V = _V;
    B = _B;
    transparence = _transparence;
    z = _z;
}

Triangle::Triangle(string definition) {
    istringstream def(definition);
    string element;

    getline(def, element, ':');

    getline(def, element, ',');
    x = stoi(element);

    getline(def, element, ',');
    y = stoi(element);

    getline(def, element, ',');
    x1 = stoi(element);

    getline(def, element, ',');
    y1 = stoi(element);

    getline(def, element, ',');
    x2 = stoi(element);

    getline(def, element, ',');
    y2 = stoi(element);

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

Triangle::~Triangle() {}


void Triangle::dessiner(CImage *image) {

    Ligne* l1 = new Ligne(x , y, x1, y1, R, V, B, transparence, z);
    Ligne* l2 = new Ligne(x , y, x2, y2, R, V, B, transparence, z);
    Ligne* l3 = new Ligne(x1, y1, x2, y2, R, V, B, transparence, z);

    l1->dessiner(image);
    l2->dessiner(image);
    l3->dessiner(image);

    delete(l1);
    delete(l2);
    delete(l3);
}


void Triangle::resize(int echelle) {
    epaisseur = epaisseur * echelle;
}

TriangleS::TriangleS():Triangle::Triangle(){}
TriangleS::TriangleS(int _x,int _y, int _x1, int _y1, int _x2, int _y2, int _R,int _V,int _B,int _transparence, int _z):Triangle::Triangle( x,y,_x1,_y1,_x2,_y2,_R,_V,_B,_transparence,_z){}
TriangleS::~TriangleS(){}

void TriangleS::dessiner(CImage *image){


}

