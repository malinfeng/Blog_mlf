#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
	int searchLeft(vector<int> &nums, int target)
	{
		if (nums.empty())
		{
			return -1;
		}
		int start = 0, end = nums.size() - 1;	
		while(start < end)
		{
			int mid = (start + end) / 2;//向下取整，为了保证循环结束 statr = mid + 1
			if(nums[mid] >= target)
			{
				end = mid;
			}
			else
			{
				start = mid + 1;
			}
		}
		if (nums[start] == target)
		{
			return start;
		}
		return -1;
	}
	
	int searchRight(vector<int> &nums, int target)
	{
		if (nums.empty())
		{
			return -1;
		}
		int start = 0, end = nums.size() - 1;	
		while (start < end)
		{
			int mid = (start + end + 1) / 2;//向上取整，为了保证循环结束，end = mid - 1
			if (nums[mid] > target)	
			{
				end = mid - 1;
			}
			else
			{
				start = mid;
			}
		}
		if (nums[start] == target)
		{
			return start;
		}	
		return -1;
	}

	vector<int> searchRange(vector<int>& nums,int target)
	{
		int left = searchLeft(nums, target);
		int right = searchRight(nums, target);
		return {left, right};
	}
};

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。
找出给定目标值在数组中的开始位置和结束位置。
你的算法时间复杂度必须是 O(log n) 级别。
如果数组中不存在目标值，返回 [-1, -1]。
示例 1:
输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:
输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]
*/

int main()
{
	Solution a;
	vector<int> vec = {5,7,7,8,8,10};
	auto ret = a.searchRange(vec, 6);
	return 0;
}
