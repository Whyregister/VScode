#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main (int argc, int argv[])
{
    Mat img(300,400,CV_8UC3);

    imshow("dd",img);

    waitKey();
    Mat img1 = img.diag(-1);

    imshow("gg",img1);
    waitKey();

}