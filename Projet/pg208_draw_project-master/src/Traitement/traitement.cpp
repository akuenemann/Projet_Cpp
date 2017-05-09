#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

#include "traitement.h"

#include "../Formes/forme.h"
#include "../Formes/arc.h"
#include "../Formes/carre.h"
#include "../Formes/cercle.h"
#include "../Formes/ligne.h"
#include "../Formes/point.h"
#include "../Formes/rectangle.h"
#include "../Formes/triangle.h"





Traitement::Traitement(){
	v.clear();
}

Traitement::Traitement(const char* list_obj){
    cout << list_obj << endl;
	v.clear();
    ifstream  infile;
	string str_temp;
	infile.open(list_obj);
	int i = 0;
    if (infile.is_open()) {
        cout << "Fichier ouvert" << endl;
    }
    else{
        cout << "Erreur ouverture fichier" << endl;
    }

	//while(getline( infile, str_temp)){
    getline(infile, str_temp);
        cout << str_temp << endl;
		if(str_temp.find("RECTANGLE") != str_temp.npos){

            str_temp.erase(remove(str_temp.begin(), str_temp.end(), ' '));
			Rectangle* rect = new Rectangle(str_temp);

			v.push_back(rect);

			i++;
			
		}
		else if(str_temp.find("CARRE") != str_temp.npos){
		
		}
		else if(str_temp.find("POINT") != str_temp.npos){
		
		}
		else if(str_temp.find("CERCLE") != str_temp.npos){
		
		}
		else if(str_temp.find("ARC") != str_temp.npos){
		
		}
		else if(str_temp.find("LIGNE") != str_temp.npos){
		
		}
	//}
}

Traitement::~Traitement(){}


void Traitement::tri(){}

void Traitement::dessiner(CImage* img){
	for(int i = 0 ; i < v.size() ; i++){
		v[i]->dessiner(img);
        delete(v[i]);
	}

}


