#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int minh,maxh,mins,maxs,minv,maxv;
void helptext()
{
    cout << "B������ɫ\n";
    cout << "H������ɫ\n";
    cout << "W������ɫ\n";
    cout << "R������ɫ\n";
    cout << "O������ɫ\n";
    cout << "Y������ɫ\n";
    cout << "G������ɫ\n";
    cout << "L������ɫ\n";
    cout << "P������ɫ\n";
    cout << "����Ҫ��ʶ�����ɫ��Ӧ����ĸ:" ;
}

void deal(char color)
{
        switch(color){
    case 'B':
        minh = 0;
        maxh = 180;
        mins = 0;
        maxs = 255;
        minv = 0;
        maxv = 46;
        break;
    case 'H':
        minh = 0;
        maxh = 180;
        mins = 0;
        maxs = 43;
        minv = 46;
        maxv = 220;
        break;
    case 'W':
        minh = 0;
        maxh = 180;
        mins = 0;
        maxs = 30;
        minv = 221;
        maxv = 255;
        break;
    case 'R':
        minh = 0;
        maxh = 10;
        mins = 43;
        maxs = 255;
        minv = 46;
        maxv = 255;
        break;
    case 'O':
        minh = 11;
        maxh = 25;
        mins = 43;
        maxs = 255;
        minv = 46;
        maxv = 255;
        break;
    case 'Y':
        minh = 26;
        maxh = 25;
        mins = 43;
        maxs = 255;
        minv = 46;
        maxv = 255;
        break;
    case 'G':
        minh = 35;
        maxh = 77;
        mins = 43;
        maxs = 255;
        minv = 46;
        maxv = 255;
        break;
    case 'L':
        minh = 100;
        maxh = 124;
        mins = 43;
        maxs = 255;
        minv = 46;
        maxv = 255;
        break;
    case 'P':
        minh = 125;
        maxh = 155;
        mins = 43;
        maxs = 255;
        minv = 46;
        maxv = 255;
        break;
    default:
        cout << "�������" << endl;
        exit(0);
    }
}

int main( )
{
    VideoCapture capture(0);
    Mat special;
    helptext();

    /**���ص�*/
    Vec3b Peix;

    char color;
    cin >> color;
    deal(color);
    MatIterator_<Vec3b> it;

    while(1)
    {
        Mat frame;              //�洢ÿһ֡��ͼ��
        capture >> frame;       //��ȡ��ǰ֡
        Mat fhsv;
        cvtColor(frame,fhsv,COLOR_BGR2HSV);   //��ͼ��ת��ΪHSVģ��
        
        //inRange(frame,Scalar(minh,mins,minv),Scalar(maxh,maxs,maxv),special); //��Ѱ��Ҫ�������ڵ���ɫ

        //Canny(frame,fhsv,50,150);

        long long int g = 0;

        for(it = fhsv.begin<Vec3b>() ; it != fhsv.end<Vec3b>() ; ++it)
        {
                Peix = * it;
                if(Peix[0]>35&&Peix[0]<77&&Peix[1]>43&&Peix[2]>46)
                g++;  
        }
        if(4*g>fhsv.cols*fhsv.rows)
        cout << "��ɫ" << endl;


        imshow("ABC",fhsv);
        if(waitKey(30) >= 0)break;
    }

    return 0;
}