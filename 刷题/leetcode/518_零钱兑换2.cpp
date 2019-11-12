
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int change(int amount, vector<int>& coins)
	{
		if (amount <= 0)
		{
			return 1;
		}
		if (coins.empty())
		{
			return 0;
		}
		vector<int> dp(amount + 1, 0);
// 		for (int j = 0; j * coins[0] <= amount; ++j)//j个数物品
// 		{
// 			dp[j * coins[0]] = 1;//钱数
// 		}
		dp[0] = 1;//初始化条件
		for (int i = 0; i < coins.size(); ++i)//第i个物品
		{
			for (int j = 0; j <= amount; ++j)//j块钱
			{
				if (j - coins[i] >= 0)
				{
					dp[j] += dp[j - coins[i]];
				}
			}
		}
		return dp.back();
	}
};

/*
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

示例 1:

输入: amount = 5, coins = [1, 2, 5]
输出: 4
解释: 有四种方式可以凑成总金额:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1


示例 2:

输入: amount = 3, coins = [2]
输出: 0
解释: 只用面额2的硬币不能凑成总金额3。


示例 3:

输入: amount = 10, coins = [10]
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/coin-change-2
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	Solution a;
	vector<int> coins = { 1, 2, 5 };
	auto ret = a.change(5, coins);
	return 0;
}
