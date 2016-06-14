#include <iostream>
#include <sstream>
#include <time.h>
#include "stdafx.h"
#include "Log.h"
#include "ArmMovements.h"
#define SPACESIZE 10
#define SCALESIZE 1
#define HUE 60

string hstate[] = { "unknown", "nottracked", "Open", "Closed", "Lasso" };
string hconf[] = { "low", "high" };

string str(pair<int, int> p) {
	stringstream ss;
	ss << hstate[p.first] << ":" << hconf[p.second];
	return ss.str();
}

string str(pair<int, int> left, pair<int, int>right) {
	stringstream ss;
	ss << str(left) << " " << str(right);
	return ss.str();
}

void doArm(cv::Mat &srcImg, Log log){
	ArmMovements arm;
	//arm.drawArmMove(image); 
	arm.drawCurvedArmMove(srcImg);
	arm.drawLine(srcImg, arm.yx, HUE);
}

void main() {
	Log log;
	try {
			cv::Mat line_img = cv::Mat::zeros(cv::Size(640, 480), CV_8UC3);		
			threshold(line_img, line_img, 150, 255, CV_THRESH_BINARY);
			doArm(line_img, log);
			//cv::imshow("complete image", src_img);
			cv::imshow("line image", line_img);
		//	cv::imwrite("comp.jpg", src_img);
			auto key = cv::waitKey(200000);
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		string s;
		cin >> s;
	}
}
