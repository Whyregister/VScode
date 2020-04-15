#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
 
using namespace cv;
using namespace std;
 
int main()
{
    VideoCapture cap1(0);
    if(!cap1.isOpened())
    {
        std::cout << "can't open the camera!" << std::endl;
        return 3;
    }

    namedWindow("Control",WINDOW_AUTOSIZE); //create a window called "Control" 
    int iLowH = 0;
    int iHighH = 180;
    int iLowS = 0; 
    int iHighS = 30; 
    int iLowV = 166;
    int iHighV = 255;
    createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    createTrackbar("HighH", "Control", &iHighH, 179);
    createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);
    createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);
    Mat imgOriginal;
    while (true)
    {
        cap1 >> imgOriginal;
        if(imgOriginal.empty())
        {
            return 2;
        }

        /**Blur and Threshold process Imge*/
        Mat  src;
        medianBlur(imgOriginal,src,3);
        threshold(src,src,127,255,THRESH_BINARY);
        /**HSVImage*/
        Mat imgHSV;
        cvtColor(src,imgHSV,COLOR_BGR2HSV);//BGR TO HSV;
        /**Color range pick*/
        Mat imgThresholded;
        inRange(imgHSV,Scalar(iLowH, iLowS, iLowV),Scalar(iHighH, iHighS, iHighV),imgThresholded); //Threshold the image
        
        Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
        morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
        morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
        
        imshow("Thresholded Image", imgThresholded); //show the thresholded image
        imshow("Original", imgOriginal); //show the original image
        if(waitKey(27) >= 0)
        break;
    }

    return 0; 
}