#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "personne.hpp"

using namespace std;

Personne::Personne(string data1, string data2, string data3, unsigned char data4, string data5){
	genre = data1;
	prenom = data2;
	nom = data3;
	age = data4;
	statut = data5;
}

Personne::Personne(const char* filename){
	loadFromFile(filename);
}

Personne::~Personne(){}

string Personne::getGenre(){
	return genre;
}

string Personne::getNom(){
	return nom;
}

string Personne::getPrenom(){
	return prenom;
}

int Personne::getAnneeNaissance(){
	int annee = 2017;
	return annee - (int) (age);
}

string Personne::getStatut(){
	return statut;
}

unsigned char Personne::getAge(){
	return age;
}

void Personne::afficheInformations(){
	if(genre == "Mr"){ 
		cout << genre << " " << prenom << " " << nom << " est né en " << getAnneeNaissance() << " (" << (int) age << " ans), il est " << statut << endl;
	}
	else{
		cout << genre << " " << prenom << " " << nom << " est né en " << getAnneeNaissance() << " (" << (int) age << " ans), elle est " << statut << endl;
	}
}
	
void Personne::setAge(unsigned char data){
	age = data;
}

void Personne::setStatut(string data){
	statut = data;
}

void Personne::setNom(string data){
	nom = data;
}

void Personne::setPrenom(string data){
	prenom = data;
}

void Personne::setGenre(string data){
	genre = data;
}

bool Personne::loadFromFile(const char* filename){
	string STRING;
	ifstream  infile; // input file stream pour lire
	string tab[] = {"genre", "prenom", "nom", "age", "statut"};
	infile.open(filename);
	for(int i = 0 ; i < 5 ; i++){ //eof = end of file
		getline( infile ,STRING);
		tab[i] = STRING;
		//cout << STRING << endl;
	}
	genre = tab[0];
	prenom = tab[1];
	nom = tab[2];
	age = (unsigned char) (stoi(tab[3]));
	statut = tab[4];
	infile.close();
	return 0;
}

bool Personne::saveToFile(const char *filename){
	ofstream  toto;
	toto.open(filename);
	toto << genre << endl;	
	toto << prenom << endl;
	toto << nom << endl;
	toto << (int) age << endl;
	toto << statut << endl;
	toto.close();
	return 0;
}

//******************************ExtPersonne

ExtPersonne::ExtPersonne(string data1, string data2, string data3, unsigned char data4, string data5)
 : Personne( data1, data2, data3, data4, data5 ) {

}

ExtPersonne::~ExtPersonne(){}



void ExtPersonne::afficheInformations_ext(){

	string stat;
	string nom_m = nom;
	transform ( nom_m.begin() ,  nom_m.end() ,  nom_m.begin() , ::toupper);
	if(age < 12){
		stat = "ENFANT";
	}
	else if(age < 18){
		stat = "ADOLESCENT";
	}
	else if(age < 65){
		stat = "ACTIF";
	}
	else{
		stat = "RETRAITE";
	}
	cout << "[" << stat << " : " << prenom.substr(0, 1) << "." << nom_m << "-" << (getAnneeNaissance()%100) << "]"; // ou prenom.at(0)
	
	afficheInformations();
}


int main(){

	ExtPersonne *p1 = new ExtPersonne("Mr", "John", "Doe", 43, "célibataire");
	Personne *p2 = new Personne("Mme", "Jane", "Doe", 42, "en couple");
	
	
	/*
	int a1 = p1->getAge();
	string s2 = p2->getStatut();
	cout << "Avant : " << endl;
	p1->afficheInformations();
	p2->afficheInformations();
	cout << "Maintenant :" << endl;
	p1->setAge( 57);
	p2->setPrenom("Joceline");
	p1->afficheInformations();
	p2->afficheInformations();	
	delete p2;
	delete p1;*/
	
	/*
	p1->saveToFile("personne_01.txt");
	p2->saveToFile("personne_02.txt");
	p1->saveToFile("personne_03.txt");
	p2->saveToFile("personne_04.txt");
	p1->saveToFile("personne_05.txt");
	p2->saveToFile("personne_06.txt");
	*/
	p1->afficheInformations_ext();
	
	
	/*
	char max = 6;
	for(int i = 1 ; i <= (int) max ; i++){
		char toto[16];
		sprintf(toto, "personne_%2.2d.txt", i);
		Personne *p = new Personne(toto);
		p->afficheInformations();
		delete p;
	
	}
	*/
	/*
	const char max = 6;
	Personne *tab[max];
	for(int i = 1 ; i <= (int) max ; i++){
		char toto[16];
		sprintf(toto, "personne_%2.2d.txt", i);
		tab[i] = new Personne(toto);
		tab[i]->afficheInformations();
	}

	for(int j = 1 ; j < (int) max ; j++){
		delete tab[j];
	}
	*/
	
	// Il aurait fallu utiliser un vecteur (pour avoir un tableau de taille variable) et utiliser if stream puis isopen pour verifier que le fichier etait bien ouvert et donc ne pas se retrouver à fermer des fichiers non ouverts
	
	delete p2;
	delete p1;
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
