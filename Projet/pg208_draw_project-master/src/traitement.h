#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Traitement{
	private:
		vector<Forme> v;
		
	public:
		Traitement();
		Traitement(const char* list_obj);
		~Traitement();
		tri();
		dessiner();
};
