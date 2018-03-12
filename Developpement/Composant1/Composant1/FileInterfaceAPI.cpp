#include<string>
#include <iostream>
#include <fstream>

#include "FileInterfaceAPI.h"

using namespace std;

FileInterface::FileInterface(string file_path) {
	//this->fichier = file_path;
	ifstream ifs(file_path);
	json j = json::parse(ifs);
	cout <<j.at("saddlebrown")<< endl;
}
