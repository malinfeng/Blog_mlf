#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	//双指针法
	int maxArea(vector<int>& height) 
	{
		int left = 0, right = height.size() - 1;
		int ret = 0;
		while (left < right)
		{
			if (height[left] <= height[right])
			{
				int newret = height[left] * (right - left);
				if (newret > ret)
				{
					ret = newret;
				}
				while (left < right && height[left + 1] < height[left])//跳过无效数据
				{
					left++;
				}
				left++;
			}
			else
			{
				int newret = height[right] * (right - left);
				if (newret > ret)
				{
					ret = newret;
				}
				while (left < right && height[right - 1] < height[right])//跳过无效数据
				{
					right--;
				}
				right--;
			}
		}
		return ret;
	}
};

/*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/container-with-most-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


int main()
{
	return 0;
}
