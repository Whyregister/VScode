//黄色路障
#include<opencv2/opencv.hpp>
#include<iostream>

#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgcodecs/legacy/constants_c.h>
#include<vector>
using namespace std;
using namespace cv;

void RoadBlock()
{
    Mat srcImg = imread("6.png");  
    Mat hsvImg;
    //将RGB颜色空间转换为HSV颜色空间
    cvtColor(srcImg, hsvImg, COLOR_BGR2HSV); //CV_BGR2YCrCb
	namedWindow("hsv", CV_WINDOW_AUTOSIZE);
	imshow("hsv", hsvImg);
    int minH = 0; //26
    int maxH = 0; //34
    int minS = 0; //
    int maxS = 0;
    int minV = 0; //200
    int maxV = 0;

    Mat yellowImg, blueImg, redImg;

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
            case 0: //黄色
                minH = 16; //26
                maxH = 35; //34
                minS = 160; //
                maxS = 255;
                minV = 50; //200
                maxV = 255;
                // inRange(原图像, 最小值的范围, 最大值的范围, 输出图像); //输出图像是黑白二值图像，其中 最小值<=像素点<=最大值 的像素点是白色
                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), yellowImg); //Threshold the image
                break;

            case 1: //蓝色
                minH = 70; //26
                maxH = 120; //34
                minS = 150; //
                maxS = 255;
                minV = 50; //200
                maxV = 255;
                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), blueImg); //Threshold the image
                break;

            case 2: //红色
                minH = 0; //26
                maxH = 15; //34
                minS = 160; //
                maxS = 255;
                minV = 50; //200
                maxV = 255;
                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), redImg); 
                break;
            default:
                cout << "颜色标志输入错误" << endl;
        }
    }

    Mat resultImg;

    Mat eleOpen = getStructuringElement(MORPH_RECT, Size(6, 6));
    morphologyEx(yellowImg, resultImg, MORPH_OPEN, eleOpen);
    imshow("open", resultImg);

	vector<vector<Point>>contours; //轮廓    
	vector<Vec4i> hierarchy;//分层    
	findContours(resultImg, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));//寻找轮廓    
	vector<vector<Point>> contours_poly(contours.size());  //近似后的轮廓点集    
	vector<Rect> boundRect(contours.size());  //包围点集的最小矩形vector   
	Rect rect_roadblock;


											  //画轮廓
	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true); //对多边形曲线做适当近似，contours_poly[i]是输出的近似点集    
		boundRect[i] = boundingRect(Mat(contours_poly[i])); //计算并返回包围轮廓点集的最小矩形     
		rect_roadblock = boundingRect(contours_poly[i]);
	    int avgX = (rect_roadblock.x + rect_roadblock.x + rect_roadblock.width) / 2; //矩形的中点X位置——cols
	    int avgY = (rect_roadblock.y + rect_roadblock.y + rect_roadblock.height) / 2; //矩形的中点Y位置——rows
		printf("%d , %d\n", avgX, avgY);//输出每个框住路障的矩形中心坐标，用来判断左右移动
	}


	for (size_t i = 0; i < contours.size(); i++) 
    {
		Scalar color = Scalar(0, 0, 255);
		rectangle(srcImg, boundRect[i].tl(), boundRect[i].br(), color, 1, 8);//画矩形
	}

	imshow("end", srcImg);


}

int main()
{
    
    Mat srcImg = imread("6.png");  

    Mat hsvImg;

    //将RGB颜色空间转换为HSV颜色空间
    cvtColor(srcImg, hsvImg, COLOR_BGR2HSV); //CV_BGR2YCrCb
	namedWindow("hsv", CV_WINDOW_AUTOSIZE);
	imshow("hsv", hsvImg);

    int minH = 0; //26
    int maxH = 0; //34

    int minS = 0; //
    int maxS = 0;

    int minV = 0; //200
    int maxV = 0;

    Mat yellowImg, blueImg, redImg;

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
            case 0: //黄色
                minH = 16; //26
                maxH = 35; //34

                minS = 160; //
                maxS = 255;

                minV = 50; //200
                maxV = 255;

                // inRange(原图像, 最小值的范围, 最大值的范围, 输出图像); //输出图像是黑白二值图像，其中 最小值<=像素点<=最大值 的像素点是白色
                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), yellowImg); //Threshold the image
                break;

            case 1: //蓝色
                minH = 70; //26
                maxH = 120; //34

                minS = 150; //
                maxS = 255;

                minV = 50; //200
                maxV = 255;

                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), blueImg); //Threshold the image
                break;

            case 2: //红色
                minH = 0; //26
                maxH = 15; //34

                minS = 160; //
                maxS = 255;

                minV = 50; //200
                maxV = 255;

                inRange(hsvImg, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), redImg); 
                break;

            default:
                cout << "颜色标志输入错误" << endl;
        }
    }

    Mat resultImg;

    Mat eleOpen = getStructuringElement(MORPH_RECT, Size(6, 6));
    morphologyEx(yellowImg, resultImg, MORPH_OPEN, eleOpen);
    imshow("open", resultImg);

	vector<vector<Point>>contours; //轮廓    
	vector<Vec4i> hierarchy;//分层    
	findContours(resultImg, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));//寻找轮廓    
	vector<vector<Point>> contours_poly(contours.size());  //近似后的轮廓点集    
	vector<Rect> boundRect(contours.size());  //包围点集的最小矩形vector   
	Rect rect_roadblock;


											  //画轮廓
	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true); //对多边形曲线做适当近似，contours_poly[i]是输出的近似点集    
		boundRect[i] = boundingRect(Mat(contours_poly[i])); //计算并返回包围轮廓点集的最小矩形     
		rect_roadblock = boundingRect(contours_poly[i]);
	    int avgX = (rect_roadblock.x + rect_roadblock.x + rect_roadblock.width) / 2; //矩形的中点X位置——cols
	    int avgY = (rect_roadblock.y + rect_roadblock.y + rect_roadblock.height) / 2; //矩形的中点Y位置——rows
		printf("%d , %d\n", avgX, avgY);//输出每个框住路障的矩形中心坐标，用来判断左右移动
	}


	for (size_t i = 0; i < contours.size(); i++) {
		Scalar color = Scalar(0, 0, 255);
		rectangle(srcImg, boundRect[i].tl(), boundRect[i].br(), color, 1, 8);//画矩形
	}

	imshow("end", srcImg);

    waitKey(0);
    return 0;
}