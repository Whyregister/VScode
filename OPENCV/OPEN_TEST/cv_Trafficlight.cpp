//红绿灯识别
#include<opencv2/opencv.hpp>
#include<iostream>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgcodecs/legacy/constants_c.h>
#include<vector>
using namespace cv;
using namespace std;
int red_light = 0;
int green_light = 0;
int yellow_light = 0;
int stop = 0;
int run = 0;
int main(int argc, char** argv)
{
	Mat dst;
	Mat src = imread("11.png");
	if (src.empty())
	{
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("intput", CV_WINDOW_AUTOSIZE);
	imshow("intput", src);

	Mat moutput;
	medianBlur(src, moutput, 3);
	cvtColor(moutput, moutput, CV_BGR2GRAY);


	vector<Vec3f> pcircles;
	HoughCircles(moutput, pcircles, CV_HOUGH_GRADIENT, 1, 10, 100, 100, 0, 0);
	src.copyTo(dst);
	for (size_t i = 0; i < pcircles.size(); i++) 
    {
    
    Vec3f cc = pcircles[i];
    circle(dst, Point2f(cc[0], cc[1]), cc[2], Scalar(255, 0, 0), 2, LINE_AA);
    circle(dst, Point2f(cc[0], cc[1]), 2, Scalar(255, 0, 0), 2, LINE_AA);
    int b = src.at<Vec3b>(cc[1], cc[0])[0];
    int g = src.at<Vec3b>(cc[1], cc[0])[1];
    int r = src.at<Vec3b>(cc[1], cc[0])[2];

    printf("%d,%d,%d\n", b,g,r);

    if (b == 0 && g == 0) 
        red_light = 1;
    if (r >170 && g > 170)//根据黄色的rgb值定
        yellow_light = 1;
    if (r == 0 && b == 0)
        green_light = 1;
    }

	if (red_light == 1) {
		putText(dst, "STOP", Point(50, 50), FONT_HERSHEY_SIMPLEX, 2.0, Scalar(0, 0, 255), 3, 8);
		imshow("OUTPUT", dst);
	}

	if (yellow_light == 1) {
		putText(dst, "WAIT", Point(50, 50), FONT_HERSHEY_SIMPLEX, 2.0, Scalar(0, 0, 255), 3, 8);
		imshow("OUTPUT", dst);
	}

	if (green_light == 1) {
		putText(dst, "GO ON", Point(50, 50), FONT_HERSHEY_SIMPLEX, 2.0, Scalar(0, 0, 255), 3, 8);
		imshow("OUTPUT", dst);
	}

	waitKey(0);
	return 0;
}