#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

#include "point.h"

Point::Point(int _x, int _y, int _R, int _V, int _B,
             int _transparence, int _z):CarreS::CarreS(_x, _y, 1, 0, _R, _V, _B, _transparence, _z){}

Point::Point():CarreS::CarreS(){}

Point::~Point(){}