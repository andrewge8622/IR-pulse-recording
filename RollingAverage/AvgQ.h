// Header file for Average Queue implementation
#ifndef AVGQ
#define AVGQ

#include <queue>

class AvgQ {
	std::queue<double> window;
	int size;
	double avg;
	int length;
	//int back;
public:
	AvgQ(int);
	double addVal(double);
	int windowSize() { return size; }
	double average() { return avg; }
};

#endif
