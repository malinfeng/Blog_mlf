#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
	int firstMissingPositive(vector<int>& nums)
	{
		int i = 0;
		while (i < nums.size())	
		{
			if (0 < nums[i] && nums[i] <= nums.size())
			{
				if (nums[nums[i] - 1] != nums[i])
				{
					swap(nums[i], nums[nums[i] - 1]);
					
				}
				else
				{
					i++;
				}
			}
			else
			{
				i++;
			}
		}
		i = 0;
		while (i < nums.size() && nums[i] == i + 1)
		{
			i++;
		}
		return i+1;
	}
};

/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:
输入: [1,2,0]
输出: 3

示例 2:
输入: [3,4,-1,1]
输出: 2

示例 3:
输入: [7,8,9,11,12]
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//核心思路，把数组看作一个hash表
int main()
{
	Solution a;
	vector<int> vec = {1,2,0};
	int ret = a.firstMissingPositive(vec);
	return 0;
}
