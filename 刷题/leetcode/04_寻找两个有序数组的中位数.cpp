
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int len1 = nums1.size();
		int len2 = nums2.size();
		if ((len1 + len2) & 1)
		{
			return helpfindKth(nums1, 0, nums2, 0, (len1 + len2) / 2 + 1);
		}
		else
		{
			return (helpfindKth(nums1, 0,  nums2, 0, (len1 + len2) / 2 + 1) 
				+ helpfindKth(nums1, 0,  nums2, 0, (len1 + len2 ) / 2)) / 2.0;
		}
	}

	double helpfindKth(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k)
	{
		if (s1 >= nums1.size())
		{
			return nums2[s2 + k - 1];
		}
		if (s2 >= nums2.size())
		{
			return nums1[s1 + k - 1];
		}
		if (k == 1)
		{
			return min(nums1[s1], nums2[s2]);
		}
		//是否有k/2个数，当一个数组不够长时，可直接淘汰另个一数组的K/2个数。
		int midVal1 = (s1 + k / 2 - 1 < nums1.size()) ? nums1[s1 + k / 2 - 1] : INT_MAX;
		int midVal2 = (s2 + k / 2 - 1 < nums2.size()) ? nums2[s2 + k / 2 - 1] : INT_MAX;

		if (midVal1 < midVal2)
		{
			return helpfindKth(nums1, s1 + k / 2, nums2, s2, k - k / 2);
		}
		else
		{
			return helpfindKth(nums1, s1, nums2, s2 + k / 2, k - k / 2);
		}
	}
};


/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0


示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	Solution a;
	vector<int> vec1 = { 1, 2 };
	vector<int> vec2 = { 3, 4 };
	auto ret = a.findMedianSortedArrays(vec1, vec2);
	return 0;
}

