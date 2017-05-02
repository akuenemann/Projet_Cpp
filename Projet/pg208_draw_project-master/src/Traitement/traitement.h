#ifndef TRAITEMENT
#define TRAITEMENT

#include <vector>

#include "../Formes/forme.h"

class Traitement{
	private:
		vector<Forme> v;
		
	public:
		Traitement();
		Traitement(const char* list_obj);
		~Traitement();
		void tri();
		void dessiner(CImage* img);
};

#endif