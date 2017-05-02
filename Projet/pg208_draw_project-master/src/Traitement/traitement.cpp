#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>

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



void getCouleur(string color, int* R, int* V, int* B){
	if (color == "ROUGE"){
		*R = 255;
		*V = 0;
		*B = 0; }

	else if (color == "VERT"){
		*R = 0;
		*V = 255;
		*B = 0; }

	else if (color == "BLEU"){
		*R = 0;
		*V = 0;
		*B = 255; }

	else if (color == "CYAN"){
		*R = 0;
		*V = 255;
		*B = 255; }

	else if (color == "MAGENTA"){
		*R = 255;
		*V = 0;
		*B = 255; }

	else if (color == "JAUNE"){
		*R = 255;
		*V = 255;
		*B = 0; }

	else if (color == "BLANC"){
		*R = 255;
		*V = 255;
		*B = 255; }

	else if (color == "NOIR"){
		*R = 0;
		*V = 0;
		*B = 0; }

	else if (color == "GRIS"){
		*R = 150;
		*V = 150;
		*B = 150; }

}

Traitement::Traitement(){
	v.clear();
}

Traitement::Traitement(const char* list_obj){
	ifstream  infile; 
	string str_temp;
	stringstream ss;
	string result;
	infile.open(list_obj);
	int i = 0;
	int R = 0;
	int V = 0;
	int B = 0;
	
	while(getline( infile, str_temp)){
		ss << str_temp;
		//if(result.find("RECTANGLE") != str_temp.npos){
			getline(ss, result, ':');
			//ss >> poubelle;
			getline(ss, result, ',');
			int x;
			stringstream(result.substr(1)) >> x;
			
			getline(ss, result, ',');
			int y;
			stringstream(result.substr(1)) >> y;
			
			getline(ss, result, ',');
			int longueur;
			stringstream(result.substr(1)) >> longueur;
			
			getline(ss, result, ',');
			int largeur;
			stringstream(result.substr(1)) >> largeur;
			
			int angled = 0;
			
			getline(ss, result, ',');
			string couleur = result.substr(1);
			getCouleur(couleur, &R, &V, &B);
			
			getline(ss, result, ',');
			int transp;
			stringstream(result.substr(1)) >> transp;
			
			int z = i;
			
			Rectangle* rect = new Rectangle(x, y, longueur, largeur, angled, R, V, B, transp, z);
			
			v.resize(i++);
			v.push_back(*rect);
			
		//}
		/*else if(str_temp.find("CARRE") != str_temp.npos){
		
		}
		else if(str_temp.find("POINT") != str_temp.npos){
		
		}
		else if(str_temp.find("CERCLE") != str_temp.npos){
		
		}
		else if(str_temp.find("ARC") != str_temp.npos){
		
		}
		else if(str_temp.find("LIGNE") != str_temp.npos){
		
		}*/
	}
}

Traitement::~Traitement(){}


/*void Traitement::tri(){}

void Traitement::dessiner(CImage* img){
	for(int i = 0 ; i < v.size() ; i++){
		v[i].dessiner(img);
	}

}*/


