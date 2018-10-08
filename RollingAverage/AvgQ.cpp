/* 
	Creates a queue that also gives the average of its contained values
*/

#include "AvgQ.h"

using namespace std;


AvgQ::AvgQ(int len) {
	size = 0;
	length = len;
	// back = backLen;
	avg = 0.0;
}
double AvgQ::addVal(double newVal) {
	double removed = 0.0;
	int oldSize = size;

	if (size == length) {
		removed = window.front();
		window.pop();
	}
	else {
		size++;
	}

		window.push(newVal);
		avg = (avg * oldSize - removed + newVal) / size;

	return removed;
}