
#include <iostream>

using namespace std;

class Solution {
public:
     int  NumberOf1(int n) 
     {
         int count = 0;
         unsigned int flag = 1;
         while(flag)
         {
             if (n & flag)//此处只要不是全零 就为1 
             {
                 count++;
             }
             flag = flag<<1; 
         }
         return count;
     }
};

// 输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

int main()
{
	Solution a;
	auto ret = a.NumberOf1(1);
	return 0;
}


