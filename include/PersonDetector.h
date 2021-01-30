#pragma once
#include <iostream>
#include <map>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/filesystem.hpp>
#include "utility.h"
#include <fstream>
#include <string>

using namespace std;
using namespace cv;
class PersonDetector{

	map<String, Mat> m;
	HOGDescriptor hog;
	ofstream of;
	void addText(Mat &img, string text);
    void drawRect(Mat &img, const vector<Rect>& rects);
    void write_to_file(const string&filename, int num_of_people);
 	

	public:
		PersonDetector(const map<String, Mat> &m, const string&filename);
		vector <Rect> detect(const Mat& img);
		void run();
};
