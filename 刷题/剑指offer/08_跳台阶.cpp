
#include <iostream>

using namespace std;

class Solution {
public:
	int jumpFloor(int number)
	{
		if (number <= 0)
		{
			return -1;
		}
		else if (number < 3)
		{
			return number;
		}
		else
		{
			int pre1 = 1;
			int pre2 = 2;
			int fi = 3;
			for (int i = 3; i < number; ++i)
			{
				pre1 = pre2;
				pre2 = fi;
				fi = pre1 + pre2;
			}
			return fi;
		}
	}
};

// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。


int main()
{
	Solution a;
	auto ret = a.jumpFloor(5);
	return 0;
}


