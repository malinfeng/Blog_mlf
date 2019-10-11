
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
	{
		if (nums.size() < 3)
		{
			return 0;
		}
		sort(nums.begin(), nums.end());
		int ret = nums[0] + nums[1] + nums[2];//初始值
		
		for (int left = 0; left < nums.size() - 2; ++left)
		{
			int mid = left + 1;
			int right = nums.size() - 1;
			while (mid < right)
			{
				int curnum = nums[left] + nums[mid] + nums[right];
				if (abs(curnum - target) < abs(ret - target))
				{
					ret = curnum;
				}

				if (curnum > target)//太大
				{
					right--;
				}
				else//太小
				{
					mid++;
				}
			}
		}
		return ret;
	}
};

/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。
找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	Solution a;
	vector<int> vec = { 1,-3,3,5,4,1 };
	auto ret = a.threeSumClosest(vec, 1);
	return 0;
}
