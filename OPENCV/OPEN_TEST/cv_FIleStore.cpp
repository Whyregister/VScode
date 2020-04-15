#include <opencv2/opencv.hpp>
#include <iostream>
#include <conio.h>
using namespace cv;

int main()
{
    FileStorage fs("hh.txt",FileStorage::WRITE);

    Mat Ons = Mat::ones(3,2,CV_32F);


    fs << "Ons" << Ons;
    fs.release();

    FileStorage fs2("hh.txt",FileStorage::READ);
    fs2["Ons"] >> Ons;

    std::cout << Ons << std::endl;
    fs2.release();
    getch();
    return 0;
}