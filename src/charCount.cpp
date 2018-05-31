/*Proj2. CharCountCPP
  CSC 700-34 Prof. Phillips
  Student: Shawn Yang
*/
//commented out next line for compatability purpose
//#include <stdafx.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
	ifstream inFile;
	ofstream outFile;
	char charIn;
	char symbol;
	int index;
	int charCounts[256] = { 0 };
	int charCounter = 0;
	if (argc < 3) {
		cout << "Please specify locations of input and output files."<<endl;
	}
	//step 0: open input and output files
	try {
		inFile.open(argv[1]);
		outFile.open(argv[2]);
		cout << "Files " <<argv[1]<<" ,"<<argv[2]<<", openned successfully."<<endl;
	} catch (const std::exception &e) {
		cout << "Unable to open file(s)."<<endl;
	}

	//step 1: get 1 char at a time from inFile
	while (inFile >> charIn) {
		index = (int)charIn; //step 2
		charCounts[index]++; //step 3
	}
	//step 4: exit while loop until there is nothing left in inFile

	//step 5: printAry
	for (int i = 0; i < 256; i++) {
		if (charCounts[i] > 0) {
			symbol = (char)i;
			outFile << "Char" << ++charCounter << " "<<symbol << " #" << charCounts[i] << endl;
		}
	}
	inFile.close();
	outFile.close();
	cout << "Output to file successfully, Files closed."<<endl;
    return 0;
}

