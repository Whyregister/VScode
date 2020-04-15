#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
    Mat src = imread("2.jpg");
    Mat ThresholdImage;
    threshold(src,ThresholdImage,127,255,THRESH_BINARY);
    imshow("display",src);
    imshow("display",ThresholdImage);
    waitKey();
    return 0;
}