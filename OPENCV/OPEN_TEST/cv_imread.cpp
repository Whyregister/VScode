#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main()
{
    Mat src1 = imread("4.jpg",-1);
    Mat src2 = imread("4.jpg",0);
    Mat src3 = imread("4.jpg",2);
    Mat src4 = imread("4.jpg",3);
    Mat src5 = imread("4.jpg",4);

    imshow("src1",src1);
    imshow("src2",src2);
    imshow("src3",src3);
    imshow("src4",src4);
    imshow("src5",src5);

    waitKey();

    return 0;
}