#include <iostream>
#include <vector>


using namespace std;

class Solution{
public:
	int search(vector<int>& nums,int target)
	{
		if (nums.empty())
		{
			return -1;
		}
		int left = 0;
		int right = nums.size() - 1;
		int mid = 0;
		while(left<right)
		{
			mid = (left + right) / 2; 
			if (nums[left] <= nums[mid])//left is ordered
			{
				if (nums[left] <= target && target <= nums[mid])
				{
					right = mid;	
				}
				else
				{
					left = mid + 1;
				}
			}
			else//right is ordered
			{
				if (nums[mid] <= target && target <= nums[right])
				{
					left = mid;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
		if(nums[left] == target)
		{
			return left;
		}
		return -1;
	}

};

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

int main()
{
	Solution a;
	std::vector<int> vec = {4,5,6,7,0,1,2};
	int target = 3;
	int ret = a.search(vec, target);
	return 0;
}
