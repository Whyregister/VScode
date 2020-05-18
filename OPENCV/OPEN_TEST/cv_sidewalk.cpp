#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace cv;
using namespace std;
int i = 12;
int sobel_kersize = 3; 

void zebracrossing(int ,void *)
{
    Mat imgsrc = imread("walk5.jpg");
    //灰度图
    Mat imgGray;
    cvtColor(imgsrc,imgGray,COLOR_BGR2GRAY);
    imshow("gray",imgGray);
    //二值化

    //中值虚化过滤
    Mat imgBlur;
    medianBlur(imgGray,imgBlur,i*2+1);
    //开闭降噪
    // Mat element = getStructuringElement(MORPH_RECT, Size(3,3));
    // morphologyEx(imgBlur, imgBlur, MORPH_OPEN, element);
    // morphologyEx(imgBlur, imgBlur, MORPH_CLOSE, element);  
    // imshow("blur",imgBlur);
    //边缘检测
    Mat imgCanny;
    Canny(imgBlur,imgCanny,100,300,3);
    imshow("canny",imgCanny);
    //进行霍夫变换
	vector<Vec4i> linesP;
	HoughLinesP(imgCanny,linesP,1,CV_PI/180,50,50,10);	
    
    for( size_t i = 0; i < linesP.size(); i++ )
    {
        Vec4i l = linesP[i];
        line(imgsrc, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(255,0,34), 2, LINE_AA);
    }
    int linesCount = linesP.size();
    
    if(linesCount <= 4)
    {
        cout << "nonthing" << endl;
    }
    else
    {
        const int Count = linesCount;
        int aveY[Count];
        int sum = 0;
        for(int i = 0 ; i < Count ;i++)
        {
            aveY[i] = (linesP[i][1]+linesP[i][3])/2;
            sum += aveY[i];
        }
        //求平均值
        int avg = sum/Count;
        //求方差 
        double diffsum = 0;
        for(int i = 0 ; i < Count ;i++)
        {
            diffsum += pow((avg - aveY[i]),2);
        }         
        double diffcount = diffsum / (Count);
        if(diffcount >= 600)
        {
            cout <<"nothing diff" << endl;
        }
        else
        {
                    
        int Distance[2*Count];
        for(int i = 0 ,j=0 ; i < 2*Count ; j++,i+=2)
        {
            Distance[i] = pow(linesP[j][0],2) + pow(linesP[j][1],2);
            Distance[i+1] = pow(linesP[j][2],2) + pow(linesP[j][3],2);
        }
        int minIdex = -1;
        int minDis = INT_MAX;
        int maxIdex = -1;
        int maxDis = -1;
        for(int i = 0;i < 2*Count ; i++)
        {
            if(minDis > Distance[i])
            {
                minDis = Distance[i];
                minIdex = i;
            }
            if(maxDis < Distance[i])
            {
                maxDis = Distance[i];
                maxIdex = i;
            }
        }
        int X_i = minIdex/2;
        int X_j = minIdex%2*2;
        int Y_i = maxIdex/2;
        int Y_j = maxIdex%2*2;
        rectangle(imgsrc,Point(linesP[X_i][X_j],linesP[X_i][X_j+1]),Point(linesP[Y_i][Y_j],linesP[Y_i][Y_j+1]),Scalar(0,200,0),3);
        // for( int i = 0 ; i < Count ; i++)
        // {
        //     cout << linesP[i] << endl;
        // }
        // cout << X_i << X_j << endl;
        // cout << Y_i << Y_j <<endl;
        // cout <<Point(linesP[X_i][X_j],linesP[X_i][X_j+1])<<endl;
        // cout <<Point(linesP[Y_i][Y_j],linesP[Y_i][Y_j+1])<<endl;
        // cout <<minIdex<<endl;
        // for(int i = 0;i < 44 ; i++)
        // {
        //     cout << Distance[i] << endl;
        // }
        }
    }
    
    imshow("src",imgsrc);
}


int main()
{
    namedWindow("track",WINDOW_FREERATIO);
    createTrackbar("i","track",&i,50,zebracrossing);
    zebracrossing(i,0);
    waitKey();
    return 0;
}



