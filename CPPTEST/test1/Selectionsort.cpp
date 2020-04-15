#include <iostream>

using namespace std;

int main ()
{
	int nums[]{12,34,354,4,454,7657};
    int numsLen = sizeof(nums)/sizeof(int);
    int tem;
    int min = nums [0];                //假设最小值为第一个元素.擂台变量
    int minIndex = 0;                 //最小值的初始下标设置为0；
    for (int i = 0;i < numsLen-1;i++)//外层循环控制比较的次数，确定排位的次序数i
    {
        min = nums [i];            //循环内部初始化比较擂台数
        minIndex = i;
		for (int j = i + 1; j < numsLen; j++)//确认次序数位置
        {
			if(nums[i] > nums[j])
            {
				min = nums[j];
                minIndex = j;
            }

        }
            
        if(minIndex > i)
        {
             tem = nums[i];
             nums[i] = min;
          	 nums[minIndex] = tem;
        }
    }
        
        for (int i=0;i<numsLen;i++)
    {
        cout << nums[i] << '\t' << endl;
    }
    return 0;
}