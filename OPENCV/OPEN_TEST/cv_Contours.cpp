#include <opencv2/opencv.hpp>
#include <vector>
using namespace cv;
int main()
{
    Mat imgsrc = imread("1.png");
    Mat imgcanny;
    std::vector<std::vector<Point>>  contours;
    std::vector<Vec4i>  points;
    
    Canny(imgsrc,imgcanny,100,200);

    findContours(imgcanny,contours,points,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));
    
    
    Mat des = Mat::zeros(imgsrc.size(),CV_8UC3);
    for ( size_t i = 0;i < contours.size();i++)
    {
        drawContours(des,contours,i,Scalar(0,0,255),1,8,points,0,Point(0,0));
    }
    imshow("canny",imgcanny);
    waitKey();
    imshow("des",des);
    waitKey();
    return 0;
}