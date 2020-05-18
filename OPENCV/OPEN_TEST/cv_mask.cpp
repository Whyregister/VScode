#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;


void MyFillploy();
int main()
{
    Mat src = imread("walk3.jpg");
    if(src.empty())
    {
        return 2;
    }
    Mat mask = Mat::zeros(src.size(),src.type());
    
    Point pts[2][4];
    //四边形
    pts[0][0] = Point(0, 100);
    pts[0][1] = Point(0, 300);
    pts[0][2] = Point(600, 300);
    pts[0][3] = Point(600, 100);
    const Point * ppt[1] = {pts[0]};
    int npt[] = {4};        
    fillPoly(mask,ppt,npt,1,Scalar(255,255,255),8);

    bitwise_and(mask,src,mask);
    imshow("ma",mask);
    waitKey(0);
    return 0;
}
