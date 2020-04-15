#include <opencv2/opencv.hpp>
using namespace cv;
int main ()
{
    Mat src = imread ("5.jpg");
    /**直接法*/
    Mat des,next;
    medianBlur(src,des,3);
    threshold(des,next,127,255,THRESH_BINARY);
    namedWindow("nima",WINDOW_AUTOSIZE);
    imshow("nima",next);
    waitKey(0);
    
    /**高斯虚化+高数阈值*/
    Size a(5,5);
    GaussianBlur(src,des,a,0);
    adaptiveThreshold(des,next,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,11,21);
    imshow("nima",next);
    waitKey(0);
    threshold(des,next,0,255,THRESH_BINARY+THRESH_OTSU);
    imshow("nima",next);
    waitKey(0);
    destroyAllWindows();
    
    return 0;

}