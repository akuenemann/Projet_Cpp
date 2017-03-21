#include <iostream>
#include "personne.hpp"

using namespace std;

Personne::Personne(string data1, string data2, string data3, unsigned char data4, string data5){
	genre = data1;
	prenom = data2;
	nom = data3;
	age = data4;
	statut = data5;
}

Personne::Personne(const char *filename){
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
	ifstream  infile;
	char *tab[] = {"genre", "prenom", "nom", "age", "statut"}
	infile.open(filename);
	for(int i = 0 ; i < 5 ; i++){ //eof = end of file
		getline( infile ,STRING);
		tab[i] = STRING;
	}
	genre = tab[0];
	prenom = tab[1];
	nom = tab[2];
	age = tab[3];
	statut = tab[4];
	infile.close();
	return 0;
}

bool Personne::saveToFile(const char *filename){
	string STRING;
	ifstream  infile;
	char *tab[] = {"genre", "prenom", "nom", "age", "statut"}
	infile.open(filename);
	for(int i = 0 ; i < 5 ; i++){ //eof = end of file
		getline( infile ,STRING);
		tab[i] = STRING;
	}
	genre = tab[0];
	prenom = tab[1];
	nom = tab[2];
	age = tab[3];
	statut = tab[4];
	infile.close();
	return 0;
}

int main(){
	Personne *p1 = new Personne("Mr", "John", "Doe", 43, "célibataire");
	Personne *p2 = new Personne("Mme", "Jane", "Doe", 42, "en couple");
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
	delete p1;
	return 0;
}
