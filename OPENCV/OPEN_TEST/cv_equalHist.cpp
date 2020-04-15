#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;
int main ()
{
    Mat src = imread("4.jpg");
    // Mat imgHSV;
    // cvtColor(src,imgHSV,COLOR_HSV2BGR);
    //imshow("imgHSV",imgHSV);
    //waitKey();

    vector<Mat> imgHSVsplit;
    split(src,imgHSVsplit);
    equalizeHist(imgHSVsplit[0],imgHSVsplit[0]);
    equalizeHist(imgHSVsplit[1],imgHSVsplit[1]);
    equalizeHist(imgHSVsplit[2],imgHSVsplit[2]);
    Mat imgInput;
    merge(imgHSVsplit,imgInput);
    imshow("imgInput",imgInput);

    waitKey();
    return 0;
}