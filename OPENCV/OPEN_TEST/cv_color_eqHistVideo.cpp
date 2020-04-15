#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
using namespace cv;
using namespace std;
int main ()
{
    VideoCapture  cap1(0);
    if(!cap1.isOpened())
    {
        return 3;
    }
    //Trackbar control;
    namedWindow("Control",WINDOW_NORMAL);
    int iLowH = 0;
    int iHighH = 180;
    int iLowS = 0; 
    int iHighS = 54;
    int iLowV = 77;
    int iHighV = 255;
    // createTrackbar("LowH", "Control", &iLowH, 180);
    // createTrackbar("HighH", "Control", &iHighH, 180);
    // createTrackbar("LowS", "Control", &iLowS, 255);
    // createTrackbar("HighS", "Control", &iHighS, 255);
    // createTrackbar("LowV", "Control", &iLowV, 255);
    // createTrackbar("HighV", "Control", &iHighV, 255);
    int type=1;
    createTrackbar("Des","Control",&type,5);
    // set window;
    namedWindow("org",WINDOW_NORMAL);
    namedWindow("prcess",WINDOW_NORMAL);    
    // open process image;
    Mat imgOriginal;

    //begin to recognition;
    while (1)
    {
        switch (type)
        {
        case 1:    
            iLowH = 0;
            iHighH = 180;
            iLowS = 0; 
            iHighS = 16;
            iLowV = 255;
            iHighV = 255;
            break;
        case 2:    
            iLowH = 17;
            iHighH = 51;
            iLowS = 0; 
            iHighS = 255;
            iLowV = 44;
            iHighV = 255;
            break;
        case 3:    
            iLowH = 52;
            iHighH = 86;
            iLowS = 69; 
            iHighS = 255;
            iLowV = 25;
            iHighV = 255;
            break;
        case 4:    
            iLowH = 92;
            iHighH = 138;
            iLowS = 76; 
            iHighS = 255;
            iLowV = 160;
            iHighV = 255;
            break;
        case 5:    
            iLowH = 0;
            iHighH = 180;
            iLowS = 0; 
            iHighS = 255;
            iLowV = 0;
            iHighV = 198;
            break;
        default:
            break;
        }
        cap1 >> imgOriginal;
        if(imgOriginal.empty())
        {
            return 1;
        }       
        /**HSVimge*/
        Mat imgHSV;//translate to the HSV IMGE
        cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV
        
        /**3chanleImage*/
        vector<Mat> hsvSplit;
        split(imgHSV, hsvSplit);
        equalizeHist(hsvSplit[2],hsvSplit[2]);//Hist value;
        merge(hsvSplit,imgHSV);//merge the chanles;

        //pick color;
        Mat imgThresholded; //Threshold range contoral;
        inRange(imgHSV,Scalar(iLowH, iLowS, iLowV),Scalar(iHighH, iHighS, iHighV),imgThresholded); //Threshold the image
        //
        
        Mat element = getStructuringElement(MORPH_RECT, Size(3,3));
        morphologyEx(imgThresholded, imgThresholded, MORPH_OPEN, element);
        morphologyEx(imgThresholded, imgThresholded, MORPH_CLOSE, element);        
        blur(imgThresholded,imgThresholded,Size(3,3));
        imshow("prcess",imgThresholded);
        
        
        Mat imgcanny;
        Canny(imgThresholded,imgcanny,100,150,7);

        std::vector<std::vector<Point>>  contours;
        std::vector<Vec4i>  points;        
        
        findContours(imgcanny,contours,points,RETR_EXTERNAL,CHAIN_APPROX_NONE,Point(0,0));
        
        // Mat des = Mat::zeros(imgOriginal.size(),CV_8UC3);
        // for ( size_t i = 0;i < contours.size();i++)
        // {
        //     drawContours(des,contours,i,Scalar(0,0,255),1,8,points,0,Point(0,0));
        // }
        // imshow("des",des);

        std::vector<std::vector<Point>> contours_ploy(contours.size());
        std::vector<Rect> ploy_rects(contours.size());
        for(size_t i = 0;i < contours.size() ; i++)
        {
            approxPolyDP(Mat(contours[i]),contours_ploy[i],45,true);
            ploy_rects[i] = boundingRect(contours_ploy[i]);
        }

        Mat imgdraw;
        imgOriginal.copyTo(imgdraw);
        for ( size_t i = 0;i < contours.size();i++)
        {
            rectangle(imgdraw,ploy_rects[i],Scalar(0,0,255),2,8);
        }
        // /**直线坐标集*/
        // std::vector<Vec4f> Posline;
        // //霍夫直线变换提取坐标；
        // HoughLinesP(imgThresholded,Posline,1,CV_PI/180.0,10,0,20);
        // //画直线；
        // for(size_t i = 0 ; i < Posline.size() ;i++)
        // {
        //     Vec4f lineP = Posline[i];
        //     line(imgOriginal,Point(lineP[0],lineP[1]),Point(lineP[2],lineP[3]),Scalar(0,0,255),1,LINE_AA);
        // }
        //show the original image;
        imshow("org",imgdraw);       
        if(waitKey(30) >= 0)
        break;
        
    }
    return 0;
}