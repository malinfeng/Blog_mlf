#include <iostream>

class Solution{
public:
	double myPow(double x, int n)
	{
        long pown = n; //防止溢出
		if (n == 0)
		{
			return 1;
		}
		else if (n > 0)
		{
			return helpPow(x, pown);
		}
		else
		{
			return 1/helpPow(x, -pown);
		}
	}

	double helpPow(double x, long n)
	{
		double ret = 1;
		while (n)
		{
			if (n & 1)
			{
				ret = ret * x;
			}
			x *= x;
			n >>= 1;
		}
		return ret;
	}
};

/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数。

示例 1:
输入: 2.00000, 10
输出: 1024.00000


示例 2:
输入: 2.10000, 3
输出: 9.26100


示例 3:
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/powx-n
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	auto ret = a.myPow(2,5);
	return 0;
}

