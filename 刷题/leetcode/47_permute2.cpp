#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class Solution{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
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
		
        unordered_set<int> myset;				//在之前的基础上加了个set，用于去重
		for (int i = start; i < nums.size(); ++i)
		{
			if (myset.count(nums[i]))
			{
				continue;
			}
			swap(nums[start], nums[i]);
			helpPermute(nums, start + 1);
			swap(nums[start], nums[i]);		//回溯
			myset.insert(nums[i])			//避免重复递归
			}
	}
	vector<vector<int>> _result;
};

/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:

输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;

	vector<int> vec = {1,1,2};
	auto ret = a.permute(vec);
	return 0;
}
