#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utils/filesystem.hpp>
#include <string>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <map>
#include <boost/algorithm/string.hpp>
#include "PersonDetector.h"


using namespace cv;
using namespace std;

std::map<String, Mat>  load_images(const String &path){
	vector<String> files;

	map<String, Mat> m;
	glob(path, files);

	for (size_t i=0; i < files.size(); ++i)
	{

		Mat img = imread(files[i]);

		if (img.empty()){

			cout << files[i] << "is invalid" << endl;
		}
		
		m.insert(pair<String,Mat>(files[i], img));
	}

	return m;
	

}

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
        printf("usage: ./main <path to image directory> \n");
        return -1;
    }

	if (!utils::fs::exists(argv[1])){

		printf("invalid directory \n");
		return -1;
	}


	map<String, Mat> m = load_images(argv[1]);
	PersonDetector detector(m, "results.txt");


	detector.run();
	
	
    return 0;
}
