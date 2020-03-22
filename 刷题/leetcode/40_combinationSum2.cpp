#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		vector<int> oneret;
		helpFind(candidates, target, oneret, 0);
		return _result;
	}

	void helpFind(vector<int>& candidates, int target, vector<int>& oneret, int curpos)
	{
		if (target == 0)
		{
			_result.push_back(oneret);
			return;
		}
		if (target < 0)
		{
			return;
		}
		if (curpos == candidates.size())
		{
			return;
		}

		oneret.push_back(candidates[curpos]);
		helpFind(candidates, target - candidates[curpos], oneret, curpos + 1);//choose
		oneret.pop_back();

		while (0 <= curpos && curpos + 1 < candidates.size() &&
			candidates[curpos + 1] == candidates[curpos])//不选择，好好体会此处跳过重复的方法，即同一个元素，在递归中，只让一个分支遍历
		{
			curpos++;
		}

		helpFind(candidates, target, oneret, curpos + 1);
	}
	vector<vector<int>> _result;
};

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用一次。
说明：
	所有数字（包括目标数）都是正整数。
	解集不能包含重复的组合。 
示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combination-sum-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	vector<int> vec = {10,1,2,7,6,1,5};
	auto ret = a.combinationSum2(vec, 8);
	return 0;
}
