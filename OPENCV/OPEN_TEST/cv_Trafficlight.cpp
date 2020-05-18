//红绿灯识别
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
using namespace cv;
using namespace std;
int color_light = 0;
int stop = 0;
int run = 0;

int Trafficlight(Mat src_color)
{
	Mat moutput;
	cvtColor(src_color, moutput, COLOR_BGR2GRAY);
	vector<Vec3f> pcircles;
	HoughCircles(moutput, pcircles, HOUGH_GRADIENT, 1, 10, 100, 100, 0, 0);
	if(pcircles.size() <= 0)
	return 0;

	for (size_t i = 0; i < pcircles.size(); i++) 
    {
    Vec3f cc = pcircles[i];
    int b = src_color.at<Vec3b>(cc[1], cc[0])[0];
    int g = src_color.at<Vec3b>(cc[1], cc[0])[1];
    int r = src_color.at<Vec3b>(cc[1], cc[0])[2];
    if (b < 30 && g < 30 && r>225) 
		{
			return 1;//red;
		}
	else
    	if (r >200 && g > 200 && b<30)//根据黄色的rgb值定
			{
				return 2;//yellow;
			}
		else
			if (r < 50 && b < 50 && g>225)
       		{
				return 3;//green
			}
	}
	
	
}


int main(int argc, char** argv)
{
	Mat src = imread("7.png");
	if (src.empty())
	{
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("intput", WINDOW_AUTOSIZE);
	imshow("intput", src);

	color_light =  Trafficlight(src);

	if (color_light == 1) 
	{
		putText(src, "STOP", Point(50, 50), FONT_HERSHEY_SIMPLEX, 2.0, Scalar(0, 0, 255), 3, 8);
		imshow("OUTPUT", src);
	}
	else
	if (color_light == 2) 
	{
		putText(src, "WAIT", Point(50, 50), FONT_HERSHEY_SIMPLEX, 2.0, Scalar(0, 0, 255), 3, 8);
		imshow("OUTPUT", src);
	}
	else
	if (color_light == 3)
	{
		putText(src, "GO ON", Point(50, 50), FONT_HERSHEY_SIMPLEX, 2.0, Scalar(0, 0, 255), 3, 8);
		imshow("OUTPUT", src);
	}

	waitKey(0);
	return 0;
}