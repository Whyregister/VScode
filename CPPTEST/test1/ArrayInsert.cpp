#include <iostream>

using namespace std;

//从右到左
int main ()
{
	int tem;
	int nums[20]{1,24,54,65};
    /**数组实际长度*/
	int numsLen=4;   		 
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
    


    for (int i=0;i<numsLen;i++){
    cout << nums[i] << '\t' ;
    }

    int insertIndex = INT_MIN;
    int insertDigit = INT_MIN;
    cin >> insertDigit;
    for (int i=0;i<numsLen;i++)
    {
        if(nums[i]<=insertDigit)
        {
            insertIndex = i;
            break;
        }
    }

    if(insertIndex == INT_MIN)
    nums[numsLen] = insertDigit;
    else
    {
        for(int i=numsLen;i>insertIndex;i--)
        {
            nums[i]=nums[i-1];
        }
        nums[insertIndex] = insertDigit;
        numsLen++;
    }

    for (int i=0;i<numsLen;i++)
    {
    cout << nums[i] << '\t' ;
    }

    return 0;

}