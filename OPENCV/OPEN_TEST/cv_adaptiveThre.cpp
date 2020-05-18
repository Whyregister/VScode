#include <opencv2/opencv.hpp>
using namespace cv;


int main()
{
    Mat imgsrc = imread("walk2.png");
    Mat imgadp;
    int ker_size = 5;
    adaptiveThreshold(imgsrc,imgadp,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,ker_size,2);
    namedWindow("adp",WINDOW_FREERATIO);
	imshow("adp",imgadp);
    waitKey();   
    return 1;
}