#include <iostream>

#include <opencv2/opencv.hpp>

#include <conio.h>

using namespace cv;

int main ()
{
    Mat m1 = Mat::ones(10,10,CV_16F);
    Mat m2 = Mat::ones(10,10,CV_16F);
    
    std::cout << compareHist(m1,m2,-1) << std::endl;

    getch();
    return 0;
}