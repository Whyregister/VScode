#include <iostream>

#include <opencv2/opencv.hpp>

#include <vector>

#include <conio.h>

using namespace cv;

int main ()
{
    Mat a;

    a = imread("1.png",IMREAD_ANYCOLOR);

    std:: cout << a << std::endl;

    Vec3b Peix = a.at<Vec3b>(0,0);

    std:: cout << Peix << std::endl; 

    getch();
    return 0;
}