#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;

int main()
{
    VideoCapture cap("D:/CloudMusic/MV/SNH48.mp4");
    if(!cap.isOpened())
    {
        return 1;
    }

    Mat src;
    Mat tem;
    namedWindow("sister",WINDOW_NORMAL);      
    while(1)
    {

        cap >> src;

        //Canny(src,tem,50,150);
        cvtColor(src,tem,COLOR_RGB2BGR);

        //resizeWindow("sister",30,20);
        imshow("sister",tem);
        if(waitKey(20) >= 0) break;
    }
    return 1;
}

