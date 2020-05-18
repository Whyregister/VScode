#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace cv;
using namespace std;

Mat img,adp,blurr,canny,hou,final;
int max_value = 255;
int odd_ker = 60;//or 70-97 for gaussian//20-40 for mean
int ker_size = 2*odd_ker + 3;
int d = 80;
int c = d-80;
int i = 13;
int thres_inter = 50;
int lmin = 50;
int dmax = 10;
int mincluster_size = 4;
int maxcluster_diff = 10;
vector<vector<int> > cluster;//集群
vector<vector<int> > cluster_point;

void hough(int ,void*)
{
    img = imread("walk3.jpg",0);
	ker_size = 2*odd_ker + 1;
	c = d-80;
	//adaptive thresholding ，自适应阈值
	adaptiveThreshold(img,adp,max_value,ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,ker_size,c);
	imshow("adaptiveThreshold_gaussian",adp);
	//filter of blur to remove noise dil,erode +blurs	
	//blur
	medianBlur(adp,blurr,(2*i+1));
	imshow("blur",blurr);
	//edge detection
	//Canny(blurr,canny,100,300,3);
    Sobel(blurr,canny,-1,1,0,3);
    convertScaleAbs(canny,canny);
	imshow("canny",canny);

	vector<Vec4i> linesP;
	HoughLinesP(canny,linesP,1,CV_PI/180,thres_inter,lmin,dmax );

	for( size_t i = 0; i < linesP.size(); i++ )
    {
        Vec4i l = linesP[i];
        line(img, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,0,34), 3, LINE_AA);
    }
	cout<<"no. of houghlines = "<<linesP.size()<<endl;
	imshow("hough",img);
	waitKey(0);
}

int main()
{	
	namedWindow("adaptiveThreshold",WINDOW_FREERATIO);
	namedWindow("blur",WINDOW_FREERATIO);
	namedWindow("canny",WINDOW_FREERATIO);
	namedWindow("hough",WINDOW_FREERATIO);
	createTrackbar("max_value","adaptiveThreshold",&max_value,255,hough);
	createTrackbar("odd_ker","adaptiveThreshold",&odd_ker,600,hough);
	createTrackbar("d","adaptiveThreshold",&d,333,hough);
	createTrackbar("i","blur",&i,50,hough);
	createTrackbar("thres_inter","hough",&thres_inter,200,hough);
	createTrackbar("lmin","hough",&lmin,100,hough);
	createTrackbar("dmax","hough",&dmax,50,hough);
	hough(max_value,0);
	return 0;
}