#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
using namespace cv;
int main ()
{
    int iLowH = 0;
    int iHighH = 180;
    int iLowS = 0; 
    int iHighS = 26;
    int iLowV = 234;
    int iHighV = 255;
    // createTrackbar("LowH", "Control", &iLowH, 180);
    // createTrackbar("HighH", "Control", &iHighH, 180);
    // createTrackbar("LowS", "Control", &iLowS, 255);
    // createTrackbar("HighS", "Control", &iHighS, 255);
    // createTrackbar("LowV", "Control", &iLowV, 255);
    // createTrackbar("HighV", "Control", &iHighV, 255);
    // open process image;
    Mat imgOriginal = imread("1.png");
    //begin to recognition;
    if(imgOriginal.empty())
    {
        return 1;
    }


    /**HSVimge*/
    Mat imgHSV;//translate to the HSV IMGE
    cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV    
    /**3chanleImage*/
    std::vector<Mat> hsvSplit;
    split(imgHSV, hsvSplit);
    equalizeHist(hsvSplit[2],hsvSplit[2]);//Hist value;
    merge(hsvSplit,imgHSV);//merge the chanles;
    //pick color;
    Mat imgThresholded; //Threshold range contoral;
    inRange(imgHSV,Scalar(iLowH, iLowS, iLowV),Scalar(iHighH, iHighS, iHighV),imgThresholded); //Threshold the image    
    Mat element = getStructuringElement(MORPH_RECT, Size(3,3));
    morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
    morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);        
    
    imshow("prcess",imgThresholded);    
    Mat imgcanny;
    Canny(imgThresholded,imgcanny,100,200);
    std::vector<Vec4f> Posline;
    //霍夫直线变换提取坐标；
    HoughLinesP(imgcanny,Posline,1,CV_PI/180.0,10,40.0,80.0);
    //画直线； 


    for(size_t i = 0 ; i < Posline.size() ;i++)
    {
        Vec4f lineP = Posline[i];
        line(imgOriginal,Point(lineP[0],lineP[1]),Point(lineP[2],lineP[3]),Scalar(37,160,0),1,LINE_AA);
    }

    imshow("des",imgOriginal);       
    waitKey();

    return 0;
}