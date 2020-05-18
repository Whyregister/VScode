#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
int main()
{
    Mat imgsrc = imread("walk3.jpg");
    if(imgsrc.empty())
    {
        return 12;
    }
    //高斯模糊
    Mat imgBlur;
    GaussianBlur(imgsrc,imgBlur,Size(3,3),0,0);

    //转灰度
    Mat imgGray;
    cvtColor(imgBlur,imgGray,COLOR_BGR2GRAY);
    //Sobel求梯度
    Mat imgSobelx,imgSobely;
    Sobel(imgGray,imgSobelx,CV_16S,1,0,3);
    Sobel(imgGray,imgSobely,CV_16S,0,1,3);
    convertScaleAbs(imgSobelx,imgSobelx);
    convertScaleAbs(imgSobely,imgSobely);
    imshow("x",imgSobelx);
    imshow("y",imgSobely);
    imshow("src",imgsrc);
    imshow("Gray",imgGray);
    waitKey();
    return 0;
}