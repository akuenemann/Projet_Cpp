#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "point.h"

Point::Point(int _x, int _y, int _R, int _V, int _B,
             int _transparence, int _z):CarreS::CarreS(_x, _y, 1, 0, _R, _V, _B, _transparence, _z){}

Point::Point():CarreS::CarreS(){}

Point::Point(string definition) {
    istringstream def(definition);
    string element;

    getline(def, element, ':');

    getline(def, element, ',');
    x = stoi(element);

    getline(def, element, ',');
    y = stoi(element);

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

Point::~Point(){}