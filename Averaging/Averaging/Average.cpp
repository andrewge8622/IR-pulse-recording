#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;
using namespace cv;

int main(int, char**)
{
	clock_t initial;
	VideoCapture cap(1); // open the default camera
	if (!cap.isOpened())  // check if we succeeded
		return -1;

	std:ofstream output("log.txt");

	Mat stream;
	namedWindow("stream", 1);

	initial = clock();

	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		float timeStamp = ((float)(clock() - initial)) / CLOCKS_PER_SEC;
		int average = (int)cv::mean(frame).val[0];
		cv::putText(frame, "some text: " + std::to_string(timeStamp), cv::Point(5, 50), FONT_HERSHEY_COMPLEX_SMALL, 1.0, cv::Scalar(255, 255, 255), 1);
		output << timeStamp << ", " << average << endl;

		imshow("stream", frame);

		if (waitKey(30) >= 0) break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	output.close();
	cap.release();
	return 0;
}

