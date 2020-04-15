#include <opencv2/opencv.hpp>
#include <iostream>
#include <conio.h>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
	cv::Mat src;
    cout << src <<endl;
	src.create(600,800,CV_8UC3);
	for ( int i = 0 ; i < src.rows ; i++)
	{	cv::Vec3b * p = src.ptr<cv::Vec3b>(i);
		for ( int j = 0 ; j < src.cols ; j++)
		{
			p[j][0] = j % 255;
			p[j][1] = j % 255;
			p[j][2] = 0;
		}
	}


	cv::imshow("src",src);
	cv::Mat roi = src(cv::Rect(33,33,33,33));
	cv::waitKey();
	cv::imshow("src",roi);
	cv::waitKey();
	//getch();
	
	return 0;
}

