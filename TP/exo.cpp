#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

#include "exo.h"

using namespace std;

Personne::Personne(string le_genre, string nom, string prenom, int annee, string la_situation)
{
	genre = le_genre;
	name = nom;
	surname = prenom;
	birth = annee;
	age = 2017-recup_birth();
	situation = la_situation;
}

Personne::Personne(const char* filename)
{
	string STRING;
	ifstream infile;
	infile.open(filename);
	while (!infile.eof)
	{
		getline(infile, STRING);
		
	}
}

Personne::~Personne()
{
	
}

string Personne::recup_genre()
{
	return genre;
}

string Personne::recup_name()
{
	return name;
}

string Personne::recup_surname()
{
	return surname;
}

int Personne::recup_birth()
{
	return birth;
}

int Personne::recup_age()
{
	return age;
}

string Personne::recup_situation()
{
	return situation;
}

void Personne::afficheInformations()
{
	cout << recup_genre() << " ";
	cout << recup_name() << " ";
	cout << recup_surname() << " est né(e) en ";
	cout << recup_birth() << " (";
	cout << recup_age() << "), il(elle) est ";
	cout << recup_situation() << endl;
}


int main()
{
	Personne* personne1 = new Personne("Mr","Toto","ABA",1968,"célibataire");
	Personne* personne2 = new Personne("Mme","Tata","LOL",2000,"Mariée");
	
	personne1->afficheInformations();
	personne2->afficheInformations();
	
	delete personne1;
	delete personne2;
	
	return 0;
}