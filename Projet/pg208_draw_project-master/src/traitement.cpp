#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

#include "traitement.h"



void getCouleur(string color, int* R, int* V, int* B){
	switch(color){
	case "ROUGE": {	*R = 255;
				  	*V = 0;
				  	*B = 0; }
				  
	case "NOIR": {	*R = 0;
				  	*V = 0;
				  	*B = 0; }
				  	
	case "BLANC": {	*R = 255;
				  	*V = 255;
				  	*B = 255; }
				  	
	case "VERT": {	*R = 0;
				  	*V = 255;
				  	*B = 0; }
				  	
	case "BLEU": {	*R = 0;
				  	*V = 0;
				  	*B = 255; }
				  	
	case "JAUNE": {	*R = 255;
				  	*V = 255;
				  	*B = 0; }
				  	
	case "MAGENTA": {*R = 255;
				  	*V = 0;
				  	*B = 255; }
				  	
	case "CYAN": {	*R = 0;
				  	*V = 255;
				  	*B = 255; }
				  	
	case "GRIS": {	*R = 150;
				  	*V = 150;
				  	*B = 150; }

	}
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
	
	while(getline( infile, str_temp, result)){
		ss << str_temp;
		if(result.find("RECTANGLE") != str_temp.npos){
			getline(ss, result, ':');
			//ss >> poubelle;
			getline(ss, result, ',');
			int x = (int) result.substr(1);
			
			getline(ss, result, ',');
			int y = (int) result.substr(1);
			
			getline(ss, result, ',');
			int longueur = (int) result.substr(1);
			
			getline(ss, result, ',');
			int largeur = (int) result.substr(1);
			
			angled = 0;
			
			getline(ss, result, ',');
			string couleur = result.substr(1);
			getCouleur(couleur, &R, &V, &B);
			
			getline(ss, result, ',');
			int transp = (int) result.substr(1);
			
			int z = i;
			
			Rectangle* rect = new Rectangle(x, y, longueur, largeur, angled, R, V, B, transp, z);
			
			v.resize(i++);
			v.push_back(*rect);
			
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
	}
		tab[i] = STRING;
		//cout << STRING << endl;
	}
}

Traitement::~Traitement(){}


Traitement::tri(){}

Traitement::dessiner(){
	for(int i = 0 ; i < v.size() ; i++){
		v[i].dessiner();	
	}

}


