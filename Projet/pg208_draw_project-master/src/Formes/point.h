#ifndef POINT
#define POINT

#include "carre.h"

class Point : public CarreS{
    public:
        Point();
        Point(int _x, int _y, int _R, int _V, int _B, int _transparence, int _z);
        ~Point();
};

#endif