#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class Forme{
	Forme(int _x, int _y, int _R, int _V, int _B, int _transparence, int _z);{...}
	protected:
		int x, y;
		int R,V,B;
		int transparence;
		int z;
}