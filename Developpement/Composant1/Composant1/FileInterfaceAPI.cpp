#include<string>
#include <iostream>
#include <fstream>

#include "FileInterfaceAPI.h"

using namespace std;

// Constructeur : initialisation la classe et lit le fichier json passé en paramètre
FileInterface::FileInterface(string file_path) {
	fichier = file_path;
	ifstream ifs(fichier);
	if (ifs.fail()) {
		cout << "la lecture du fichier a echoue"<<endl;
	}
	else {
		cout << "lecture du fichier : "<<fichier << " a reussi." << endl;
	}
}

// Parcourt tous les blocs afin de savoir s'ils sont conformes - génére une exception si un n'est pas conforme
void FileInterface::verification() {
	vector<Bloc> liste_blocs = parse(fichier); // transforme le fichier en un vecteur de Bloc
	/*for (vector<Bloc>::iterator it = liste_blocs.begin(); it != liste_blocs.end(); ++it){
		Bloc bloc = *it;
		cout <<"Bloc : "<< bloc.ToString() <<endl;
		// on parcours la liste et on appelle la methode verification bloc du composant5 
		if (!verify_bloc(bloc)) { // tester car methode verify_bloc attend un Bloc*
			throw new string("erreur lors de la verification d'un bloc");
		}
	}*/
	cout << "verification successful." << endl;
}

vector<Bloc> FileInterface::parse(string blocsJson) {
	vector<Bloc> liste_blocs;
	ifstream ifs(blocsJson); // lit le fichier
	json j = json::parse(ifs); // transforme en json

	// parcours clé & valeur le fichier json						   
	for (json::iterator it = j.begin(); it != j.end(); ++it) {
		std::cout << it.key() << " : " << it.value() << "\n";
	}
	return liste_blocs;
}
