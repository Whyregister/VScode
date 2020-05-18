#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
int main ()
{
    //加载图像
    Mat imgSrc = imread("walk3.jpg");
    if(imgSrc.empty())
    {
        return 1;
    }
    //灰度图像
    Mat imgGray;
    cvtColor(imgSrc,imgGray,COLOR_BGR2GRAY);
    //中值滤波；
    Mat imgProcess;
    medianBlur(imgGray,imgProcess,1);
    Mat imgCany;

    //开闭操作持续降噪；
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(imgProcess, imgProcess, MORPH_OPEN, element);
    morphologyEx(imgProcess, imgProcess, MORPH_CLOSE, element);

    //边缘提取
    Canny(imgProcess,imgCany,100,200,5);
        
    /**直线坐标集*/
    std::vector<Vec4f> Posline;
    //霍夫直线变换提取坐标；
    HoughLinesP(imgCany,Posline,1,CV_PI/180.0,10,30,10);
    //画直线； 
    Mat des(imgSrc.size(),CV_8UC3,Scalar(0,0,0));
    for(size_t i = 0 ; i < Posline.size() ;i++)
    {
        Vec4f lineP = Posline[i];
        line(des,Point(lineP[0],lineP[1]),Point(lineP[2],lineP[3]),Scalar(37,160,0),1,LINE_AA);
    }
    
    //输出比较；
    imshow("Gray",imgGray);
    imshow("Cannyimg",imgCany);
    imshow("des",des);
    imshow("img",imgProcess);
    std::cout << Posline.size() << std::endl;
    waitKey();
    return 0;
}