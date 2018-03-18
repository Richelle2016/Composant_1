#include <iostream>

#include "FileInterfaceAPI.h"

using namespace std;

int main(int argc, char* argv[]) {
	cout << "test" << endl;
	FileInterface f("colors.json"); // attention au path du projet
	f.verification();
	return 0;
}