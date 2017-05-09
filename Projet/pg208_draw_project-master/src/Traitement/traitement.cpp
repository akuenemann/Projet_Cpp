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
	v.clear();
    ifstream  infile;
	string str_temp;
	infile.open(list_obj);
	int i = 0;

	while(getline( infile, str_temp)){
        if( str_temp.find(" ") != -1 ) {
            str_temp.erase(remove(str_temp.begin(), str_temp.end(), ' '));
        }
        if (str_temp.find("##") != str_temp.npos){}
        else if(str_temp.find("RECTANGLES") != str_temp.npos){
            RectangleS* rectangleS = new RectangleS(str_temp);

            v.push_back(rectangleS);

            i++;
        }
        else if(str_temp.find("CERCLES") == 0){
            CercleS* cercleS = new CercleS(str_temp);

            v.push_back(cercleS);

            i++;
        }
        else if(str_temp.find("CARRES") != str_temp.npos){
            CarreS* carreS = new CarreS(str_temp);

            v.push_back(carreS);

            i++;
        }
		else if(str_temp.find("RECTANGLE") != str_temp.npos){
            Rectangle* rect = new Rectangle(str_temp);

			v.push_back(rect);

			i++;
			
		}
		else if(str_temp.find("CARRE") != str_temp.npos){
            Carre* carre = new Carre(str_temp);

            v.push_back(carre);

            i++;
		}
		else if(str_temp.find("POINT") != str_temp.npos){
            Point* point = new Point(str_temp);

            v.push_back(point);

            i++;
		}
		else if(str_temp.find("CERCLE") != str_temp.npos){
            Cercle* cercle = new Cercle(str_temp);

            v.push_back(cercle);

            i++;
		}
		else if(str_temp.find("ARC") != str_temp.npos){
            Arc* arc = new Arc(str_temp);

            v.push_back(arc);

            i++;
		}
		else if(str_temp.find("LIGNE") != str_temp.npos){
            Ligne* ligne = new Ligne(str_temp);

            v.push_back(ligne);

            i++;
		}
        else if(str_temp.find("TRIANGLE") != str_temp.npos){
            Triangle* triangle = new Triangle(str_temp);

            v.push_back(triangle);

            i++;
        }


	}
}

Traitement::~Traitement(){}



bool wayToSort(Forme*i, Forme*j) { return i->getz() < j->getz(); }

void Traitement::tri(){
    sort(v.begin(), v.end(), wayToSort);
}




void  Traitement::resize(int echelle){
    for(int i = 0 ; i < v.size() ; i++){
        v[i]->resize(echelle);
    }
}

void Traitement::dessiner(CImage* img){
	for(int i = 0 ; i < v.size() ; i++){
		v[i]->dessiner(img);
        delete(v[i]);
	}

}


