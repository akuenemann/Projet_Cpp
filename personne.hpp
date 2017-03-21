#include <iostream>

using namespace std;

class Personne{
	protected :
		string genre;
		string prenom;
		string nom;
		unsigned char age;
		string statut;

	public :
		Personne(string genre, string prenom, string nom, unsigned char anneeNaissance, string statut);
		Personne(const char* filename);
		~Personne();
		
		string getGenre();
		string getNom();
		string getPrenom();
		int getAnneeNaissance();
		string getStatut();
		unsigned char getAge();

		void afficheInformations();
		
		void setAge(unsigned char data);
		void setStatut(string data);
		void setNom(string data);
		void setPrenom(string data);
		void setGenre(string data);
		
		bool loadFromFile(const char* filename);
		bool saveToFile(const char *filename);	
	
};

class ExtPersonne : public Personne{

	public :
		ExtPersonne(string genre, string prenom, string nom, unsigned char anneeNaissance, string statut);
		~ExtPersonne();

		void afficheInformations_ext();
	
};

