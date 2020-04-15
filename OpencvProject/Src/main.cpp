#include <iostream>
#include <opencv2/core.hpp>
#include "opencv2/highgui.hpp"
using namespace cv;
using namespace std;

int main()
{
    Mat src = Mat::eye(5,5,CV_8UC1);
    cout << src <<endl;
    waitKey();
    return 0;
}