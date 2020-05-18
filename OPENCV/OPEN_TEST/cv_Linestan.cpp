#include <iostream>
#include <conio.h>
#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
    Mat imgSrc = imread("zhixian.png");
    if(imgSrc.empty())
    {
        return 1;
    }
    Mat imgCany,imgGray;
    //转化为灰度图像
    cvtColor(imgSrc,imgGray,COLOR_BGR2GRAY);
    //二值化
    threshold(imgGray,imgGray,0,255,THRESH_OTSU);
    imshow("Gray",imgGray);
    //边缘提取
    Canny(imgGray,imgCany,100,200);
    imshow("Canny",imgCany);

    /**直线坐标集*/
    std::vector<Vec4f> Posline;
    //霍夫直线变换提取坐标；
    HoughLinesP(imgCany,Posline,1,CV_PI/180.0,50,20,30);
    // //画直线； 
    // float tan1,tan2,tan3;
    // tan1 = (Posline[0][0] - Posline[0][2])/(Posline[0][1]-Posline[0][3] );
    // tan2 = (Posline[1][0] - Posline[1][2])/(Posline[1][1]-Posline[1][3] );
    // tan3 = (Posline[2][0] - Posline[2][2])/(Posline[2][1]-Posline[2][3] );
    // std::cout << tan1 << std::endl;
    // std::cout << tan2 << std::endl;
    // std::cout << tan3 << std::endl;
    // std::cout << Posline[0] << std::endl;
    std::cout << Posline.size() << std::endl;
    Mat des(imgSrc.size(),imgSrc.type(),Scalar(0,0,0));
    for( size_t i = 0; i < Posline.size() ;i++)
    {
        Vec4f lines = Posline[i];
        line(des,Point(lines[0],lines[1]),Point(lines[2],lines[3]),Scalar(255,0,0));
    }
    imshow("des",des);
    waitKey();
    getch();
    return 0;
}
