#include <opencv2/opencv.hpp>
using namespace cv;

int i = 13;

void BlurTest(int ,void*)
{
    Mat src = imread("walk4.jpg");
    Mat imgCanny;
    Canny(src,imgCanny,100,300,3);

    Mat BlurImage;
    medianBlur(imgCanny,BlurImage,i*2+1);
    imshow("Blur",BlurImage);
    imshow("Canny",imgCanny);
    imshow("Src",src);   
}

int main()
{
    namedWindow("Blur",WINDOW_FREERATIO);
    createTrackbar("i","Blur",&i,20,BlurTest);
    BlurTest(i,0);
    waitKey();   
    return 1;
}