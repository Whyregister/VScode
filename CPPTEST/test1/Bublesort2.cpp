#include <iostream>

using namespace std;

//从左至右
int main ()
{
	int tem;
    int nums[20]{1,2,3,4,-2};
    int numsleth = sizeof(nums)/sizeof(int);

    for(int i=0;i<numsleth-1;i++)    	//外层循环控制比较的轮数lenthof(arry)-1;
    {
        for (int j=numsleth-1;j>i;j--)	//内层循环控制比较次数；
        {
            if(nums[j]<nums[j-1])	    //判断后交换
            {
                tem = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = tem;
            }
        }
    }

       for (int i=0;i<numsleth;i++)
    {
        cout << nums[i] << '\t' << endl;
    } 

    return 0;
    
        
}