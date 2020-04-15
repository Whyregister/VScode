#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
using namespace cv;
using namespace std;
int main ()
{
             //Trackbar control;
    namedWindow("Control",WINDOW_AUTOSIZE);
    int iLowH = 0;
    int iHighH = 179;
    int iLowS = 0; 
    int iHighS = 30;
    int iLowV = 166;
    int iHighV = 255;
    createTrackbar("LowH", "Control", &iLowH, 179);
    createTrackbar("HighH", "Control", &iHighH, 179);
    createTrackbar("LowS", "Control", &iLowS, 255);
    createTrackbar("HighS", "Control", &iHighS, 255);
    createTrackbar("LowV", "Control", &iLowV, 255);
    createTrackbar("HighV", "Control", &iHighV, 255);
    
    // open process image;
    Mat imgOriginal = imread("4.jpg");

    //begin to recognition;
    while (1)
    {
    imshow("org",imgOriginal);
    /**HSVimge*/
    Mat imgHSV;//translate to the HSV IMGE
    cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
    
    /**3chanleImage*/
    vector<Mat> hsvSplit;
    split(imgHSV, hsvSplit);
    equalizeHist(hsvSplit[2],hsvSplit[2]);//Hist value;
    merge(hsvSplit,imgHSV);//merge the chanles;

    imshow("the His HSVimage", imgHSV); //show the handled image;
    
    Mat imgThresholded; //Threshold range contoral;
    inRange(imgHSV,Scalar(iLowH, iLowS, iLowV),Scalar(iHighH, iHighS, iHighV),imgThresholded); //Threshold the image

    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);

    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);
    imshow("Thresholded Image", imgThresholded); //show the thresholded image

    char key = (char) waitKey(300);
    if(key == 27)
    break;
    
    }
    return 0;
}