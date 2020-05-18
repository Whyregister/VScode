#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage;
    srcImage = imread("walk3.g");        //加载图像文件

    //判断图像是否加载成功
    if(srcImage.empty())
    {
        cout << "图像加载失败!" << endl;
        return -1;
    }
    else
        cout << "图像加载成功!" << endl << endl;

    namedWindow("原图像", WINDOW_AUTOSIZE);
    imshow("原图像", srcImage);

    Mat midImage, dstImage;
    Canny(srcImage, midImage, 100, 300 , 3);        //首先对图像进行边缘检测
    cvtColor(midImage, dstImage, COLOR_GRAY2BGR);

    //进行霍夫变换
    vector<Vec4i> lines;
    HoughLinesP(midImage, lines, 1, CV_PI/180, 50, 50,10);
    for(size_t i = 0; i < lines.size(); i++)
    {
        line(dstImage, Point(lines[i][0], lines[i][1]), Point(lines[i][2], lines[i][3]),Scalar(0, 0, 255), 3, LINE_AA);
    }

    namedWindow("霍夫线变换", WINDOW_AUTOSIZE);
    imshow("霍夫线变换", dstImage);
    waitKey(0);
    return 0;
}