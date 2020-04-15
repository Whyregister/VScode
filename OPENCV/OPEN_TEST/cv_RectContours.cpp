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

    std::vector<std::vector<Point>> contours_ploy(contours.size());
    std::vector<Rect> ploy_rects(contours.size());

    for(size_t i = 0;i < contours.size() ; i++)
    {
        approxPolyDP(Mat(contours[i]),contours_ploy[i],3,true);
        ploy_rects[i] = boundingRect(contours_ploy[i]);
    }

    Mat imgdraw;
    imgsrc.copyTo(imgdraw);

    
    Mat des = Mat::zeros(imgsrc.size(),CV_8UC3);
    for ( size_t i = 0;i < contours.size();i++)
    {
        drawContours(des,contours,i,Scalar(0,0,255),1,8,points,0,Point(0,0));
    }

    for ( size_t i = 0;i < contours.size();i++)
    {
        rectangle(imgdraw,ploy_rects[i],Scalar(0,0,255),2,8);
    }
    imshow("draw",des);
    imshow("des",imgdraw);
    waitKey();
    return 0;
}