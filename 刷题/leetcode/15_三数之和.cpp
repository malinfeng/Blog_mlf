#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		for (int i = 0; i < (int)nums.size() - 2; ++i)
		{
			int left = i + 1; 
			int right = nums.size() - 1;
			while (left < right)
			{
				if (nums[i] + nums[left] + nums[right] < 0)
				{
					left++;
				}
				else if(nums[i] + nums[left] + nums[right] > 0)
				{
					right--;
				}
				else
				{
					ret.push_back({ nums[i], nums[left], nums[right] });
					++left;
					--right;
					while (left < right && nums[left] == nums[left - 1])
					{
						++left;
					}
					while (left < right && nums[right] == nums[right + 1])
					{
						--right;
					}
				}
			}

			while (i < nums.size() - 2 && nums[i] == nums[i + 1])
			{
				i++;
			}
		}
		return ret;
	}
};

/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	vector<int> ve;
	a.threeSum(ve);
	return 0;
}