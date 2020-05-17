#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class Solution{
public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		helpPermute(nums, 0);
		return _result;
	}

	void helpPermute(vector<int>& nums, int start)//求start往后的全排
	{
		if (start == nums.size() - 1)
		{
			_result.push_back(nums);
			return;
		}
		for (int i = start; i < nums.size(); ++i)
		{
			swap(nums[start], nums[i]);
			helpPermute(nums, start + 1);
			swap(nums[start], nums[i]);		//回溯
		}
	}
	vector<vector<int>> _result;
};

/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;

	vector<int> vec = {1,2,3};
	auto ret = a.permute(vec);
	return 0;
}
