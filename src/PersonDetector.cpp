#include "PersonDetector.h"


PersonDetector::PersonDetector(const map<String, Mat> &m, const string&filename):m{m}, of{filename}, hog() 
{

	hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());


}


vector <Rect> PersonDetector::detect(const Mat& img)
{

	vector<Rect> found;
	hog.detectMultiScale(img, found, 0.6, Size(4,4), Size(), 1.08, 2, false);
	return found;

}

void PersonDetector::run(){

	String folder = "results/";
    //write header for text file ...
	of << setw(5) << "" << "Date" << setw(22) << " " << "Filename" << setw(10) << " " << "Number of People Detected" << endl;

	utils::fs::createDirectory(folder);
	for (auto it= m.begin(); it!=m.end(); ++it){

		// detect person in img
		vector<Rect> rects = detect(it->second);
		int num_of_people = rects.size();

		string text = to_string(num_of_people) + " detected";
		addText(it->second, text);
		drawRect(it->second, rects);
		String filename = get_FileName(it->first);

		imwrite(folder+filename, it->second);
		write_to_file(filename, num_of_people);

	}

	of.close();
        
}


void PersonDetector::addText(Mat &img, string text){
	putText(img, text, 
	Point(img.cols/2, 100), 
	FONT_HERSHEY_DUPLEX,
	1.8,
	CV_RGB(0, 255, 0), //font color
	2);
}


void PersonDetector::drawRect(Mat &img, const vector<Rect>& rects)
{
	
	for (auto&r : rects){

	rectangle(img, r.tl(), r.br(), cv::Scalar(0, 255, 0), 2);
   	}
        
}




void PersonDetector::write_to_file(const string&filename, int num_of_people){

	of << get_time_and_date() << setw(10) << " "  <<  filename << setw(15) << " " << num_of_people <<  endl; 
}


