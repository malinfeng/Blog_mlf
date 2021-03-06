
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int jumpFloorII(int number)
	{
		if (number <= 0)
		{
			return -1;
		}
		else if (number < 3)
		{
			return number;
		}
		
		vector<int > dp(number + 1, 0);
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i < number + 1; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				dp[i] += dp[j];
			}
		}
		return dp[number];
	}
};

// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。


int main()
{
	Solution a;
	auto ret = a.jumpFloorII(5);
	return 0;
}


