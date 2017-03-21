#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>

//enum genre {homme, femme};
//enum situation {celibataire, marie, couple};

using namespace std;

class Personne
{
	private:
	//Attribut
	string genre;
	string name;
	string surname;
	int birth;
	int age;
	string situation;
	
	public:
	//Constructeur & Destructeur
	Personne(string le_genre, string nom, string prenom, int annee, string la_situation);
	Personne(const char* filename);
	~Personne();
	
	//Méthode
	string recup_genre();
	string recup_name();
	string recup_surname();
	int recup_birth();
	int recup_age();
	string recup_situation();
	void afficheInformations();
	bool loadFromFile(const char* filename);
	bool saveToFile(const char* filename);
};




