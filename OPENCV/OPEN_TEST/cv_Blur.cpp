#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{
    Mat src = imread("1.png");
    Mat BlurImage;
    medianBlur(src,BlurImage,3);
    imshow("Blur",BlurImage);
    imshow("Src",src);
    waitKey();
    return 1;
}