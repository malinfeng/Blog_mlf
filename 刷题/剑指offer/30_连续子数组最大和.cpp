
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	///动态规划
	///状态转移方程： sum[i]=max(sum[i-1]+a[i],a[i]),sum[i]是以元素i结尾的连续子数组最大值
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		int result = 0;
		int tempsum = 0;
		tempsum = result = array.front();
		for (int i = 1; i < array.size(); ++i)
		{
			tempsum = (tempsum + array.at(i)) > array.at(i) ? tempsum + array.at(i) : array.at(i);
			if (tempsum > result)
			{
				result = tempsum;
			}
		}
		return result;
	}

};



//例如:{6, -3, -2, 7, -15, 1, 2, 2}, 连续子向量的最大和为8(从第0个开始, 到第3个为止)。
//给一个数组，返回它的最大连续子序列的和
int main()
{
	vector<int> array = { 6, -3, -2, 7, -15, 1, 2, 2 };
	Solution a;
	int result = a.FindGreatestSumOfSubArray(array);
	return 0;
}



