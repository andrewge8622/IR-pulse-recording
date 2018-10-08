/*
Uses average value of queue to decide whether to mark a timepoint as a pulse or not.
*/

#include <iostream>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include "AvgQ.h"
using namespace std;

int main(int argc, char** argv) {
	double pulseTime;
	double lastPulse;
	int windowLength = stoi(argv[1]);
	double BPM;
	ifstream inFile;
	ofstream outFile;

	AvgQ window(windowLength);

	string fileName;
	cout << "enter an input file name: ";
	cin >> fileName;

	inFile.open(fileName);
	if (!inFile) {
		cerr << "Unable to open file " << fileName << " for reading" << endl;
		exit(1);
	}

	cout << "enter an output file name: ";
	cin >> fileName;
	outFile.open(fileName);
	if (!outFile) {
		cerr << "Unable to open file " << fileName << " for writing" << endl;
		exit(1);
	}

	inFile >> lastPulse; // set first pulse 

	while (inFile >> pulseTime) {
		BPM = 60 / (pulseTime - lastPulse);
		window.addVal(BPM);
		lastPulse = pulseTime;

		// cout << lastPulse << ", " << window.average() << endl;
		outFile << lastPulse << ", " << window.average() << endl;

	}

	inFile.close();

	return 0;
}