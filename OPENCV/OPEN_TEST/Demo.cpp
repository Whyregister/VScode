#include <iostream>

#include <opencv2/opencv.hpp>

#include <conio.h>

using namespace cv;

int main ()
{
    Mat src = Mat::eye(5,5,CV_8UC1);
    std::cout << src <<std::endl;
    getch();
    return 0;
}