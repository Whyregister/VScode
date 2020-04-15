#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
 
using namespace cv;
using namespace std;
 
int main()
{
    namedWindow("Control",WINDOW_AUTOSIZE); //create a window called "Control" 
    int iLowH = 100;
    int iHighH = 140;
    int iLowS = 90; 
    int iHighS = 255; 
    int iLowV = 90;
    int iHighV = 255;
    createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
    createTrackbar("HighH", "Control", &iHighH, 179);
    createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "Control", &iHighS, 255);
    createTrackbar("LowV", "Control", &iLowV, 255); //Value (0 - 255)
    createTrackbar("HighV", "Control", &iHighV, 255);
    Mat imgOriginal = imread("4.jpg");

    while (true)
    {
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
      imshow("Thresholded Image", imgThresholded); //show the thresholded image
      imshow("Original", imgOriginal); //show the original image
      char key = (char) waitKey(300);
      if(key == 27)
      break;
    }

    return 0; 
}