#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
int main ()
{
    Mat imgSrc = imread("1.png");
    if(imgSrc.empty())
    {
        return 1;
    }
    Mat imgCany,des;
    //边缘提取
    Canny(imgSrc,imgCany,100,200);
    //des为有色空间
    cvtColor(imgCany,des,COLOR_GRAY2BGR);
    /**直线坐标集*/
    std::vector<Vec4f> Posline;
    //霍夫直线变换提取坐标；
    HoughLinesP(imgCany,Posline,1,CV_PI/180.0,10,0,6);
    //画直线；
    for(size_t i = 0 ; i < Posline.size() ;i++)
    {
        Vec4f lineP = Posline[i];
        line(imgSrc,Point(lineP[0],lineP[1]),Point(lineP[2],lineP[3]),Scalar(37,160,0),1,LINE_AA);
    }
    //输出比较；
    imshow("Cannyimg",imgCany);
    imshow("des",imgSrc);
    waitKey();
    return 0;
}