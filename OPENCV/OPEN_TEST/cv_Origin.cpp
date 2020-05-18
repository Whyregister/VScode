#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
using namespace cv;
int iLowH = 0;
int iHighH = 180;
int iLowS = 0; 
int iHighS = 26;
int iLowV = 234;
int iHighV = 255;

void Starline(int ,void *)
{
    Mat src_color = imread("4.jpg");    
    if(src_color.empty())
    {
        return;
    } 
    /**HSVimge*/
    Mat imgHSV;//translate to the HSV IMGE
    cvtColor(src_color, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV    
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
    medianBlur(imgThresholded,imgThresholded,3);
    
    imshow("thre",imgThresholded);
    Mat imgcanny;
    Canny(imgThresholded,imgcanny,100,300);
    
    imshow("canny",imgcanny);

    std::vector<std::vector<Point>>  contours;
    std::vector<Vec4i>  points;            
    findContours(imgcanny,contours,points,RETR_EXTERNAL,CHAIN_APPROX_NONE,Point(0,0));   
    std::vector<std::vector<Point>> contours_ploy(contours.size());
    std::vector<Rect> ploy_rects(contours.size());
    
    for(size_t i = 0;i < contours.size() ; i++)
    {
        approxPolyDP(Mat(contours[i]),contours_ploy[i],45,true);
        ploy_rects[i] = boundingRect(contours_ploy[i]);
    }
    Mat imgdraw;

    src_color.copyTo(imgdraw);
    for ( size_t i = 0;i < ploy_rects.size();i++)
    {
        rectangle(imgdraw,ploy_rects[i],Scalar(0,0,255),2,8);
    }

    imshow("org",imgdraw);

}


int main ()
{
    namedWindow("adjust",WINDOW_FREERATIO);
    createTrackbar("iLowH","adjust",&iLowH,180,Starline);
    createTrackbar("iHigH","adjust",&iHighH,180,Starline);
    createTrackbar("iLowS","adjust",&iLowS,255,Starline);
    createTrackbar("iHigS","adjust",&iHighS,255,Starline);
    createTrackbar("iLowV","adjust",&iLowV,255,Starline);
    createTrackbar("iHigV","adjust",&iHighV,255,Starline); 
    Starline(0,0);    
    waitKey();    
    return 0;
}