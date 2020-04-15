#include <iostream>

using namespace std;

//从右到左
int main ()
{
	int tem;
	int nums[]{1,24,54,65,32,43,1,32,43,5445,232};
	int numsLen=sizeof(nums)/sizeof(int);   		 
    for (int i=0;i<numsLen-1;i++)		//控制循环轮数
    {
        for (int j=0;j<numsLen-1-i;j++)	//控制比较次数
        {
            
            if(nums[j]<nums[j+1])	   //判断后交换
            {
             tem=nums[j];
			 nums[j]=nums[j+1];
             nums[j+1]=tem;
            }
        }
    }

    for (int i=0;i<numsLen;i++)
    {
        cout << nums[i] << '\t' << endl;
    }
    return 0;
}