#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
	void nextPermutation(vector<int> &nums)
	{
		if (nums.empty())
		{
			return;
		}
		int end = nums.size() - 1;
		int start = end - 1;
		while (start >= 0 &&
			      	nums[start] >= nums[start + 1])	//找到第一个减小的数	
		{
			start--;
		}
		if (start >= 0)
		{
			int swapidx = start + 1;
			while (swapidx + 1 < nums.size() && nums[swapidx + 1] > nums[start])//找到交换的位置
			{
				swapidx++;
			}
			swap(nums[start], nums[swapidx]);
		}
		start++;	
		while (start < end)//重排
		{
			swap(nums[start],nums[end]);
			start++;
			end--;
		}
	}

};

/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。
以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

int main()
{
	Solution a;
	std::vector<int> vec = {2,3,1};

	a.nextPermutation(vec);

	return 0;
}
