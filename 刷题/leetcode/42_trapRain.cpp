#include <iostream>
#include <vector>
#include <stack> 

using namespace std;

class Solution{
public:
	int trap(vector<int>& height)
	{
		int ret = 0;
		int tempblock = 0;
		stack<int> mys;
		for (int i = 0; i < height.size(); ++i)	// = is valid
		{
			if (mys.empty())
			{
				mys.push(height[i]);
			}
			else
			{
				if (height[i] >= mys.top())
				{
					ret += tempblock;
					tempblock = 0;
					mys.push(height[i]);
				}
				else
				{
					tempblock += mys.top() - height[i];
				}
			}
		}
		while (!mys.empty())
		{
			mys.pop();
		}
		tempblock = 0;
		for (int i = height.size() - 1; i >= 0; --i)// = is not valid
		{
			if (mys.empty())
			{
				mys.push(height[i]);
			}
			else
			{
				if (height[i] > mys.top())
				{
					ret += tempblock;
					tempblock = 0;
					mys.push(height[i]);
				}
				else
				{
					tempblock += mys.top() - height[i];
				}
			}

		}
		return ret;
	}
};

/*
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例:

输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trapping-rain-water
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	vector<int> vec = {0,1,0,2,1,0,1,3,2,1,2,1};
	auto ret = a.trap(vec);
	return 0;
}
