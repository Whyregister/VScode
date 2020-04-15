#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
int main ()
{
    Mat src = imread("1.png");
    
    //开操作 (去除一些噪点)
    Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
    morphologyEx(src, src, MORPH_OPEN, element);
    //闭操作 (连接一些连通域)
    morphologyEx(src, src, MORPH_CLOSE, element);
    imshow("src",src);
    waitKey();
    return 0;
}