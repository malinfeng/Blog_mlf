
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int rectCover(int number)
	{
		if (number <= 0)
		{
			return 0;
		}
		else if (number < 3)
		{
			return number;
		}

		vector<int> dp(number + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i < number + 1; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[number];
	}
};

// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
// 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

int main()
{
	Solution a;
	auto ret = a.rectCover(5);
	return 0;
}


