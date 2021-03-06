
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> result;
		if (num.empty())
		{
			return result;
		}
		if (size <= 0 || size > num.size())
		{
			return result;
		}
		deque<int> q;//用于记录最大值位置
		
		for (int i = 0; i < num.size(); ++i)
		{
			if (!q.empty() && q.front() < int(i - size) +1)//超过滑动窗口长度的值
			{
				q.pop_front();
			}
			if (q.empty())
			{
				q.push_front(i);//放入第一个元素
			}

			if (!q.empty() && num.at(i) > num.at(q.front()))
			{
				q.push_front(i);
			}
			else
			{
				while (num.at(i) > num.at(q.back()))
				{
					q.pop_back();
				}
				if (num.at(i) < num.at(q.front()))
				{
					q.push_back(i);
				}
			}

			if (i >= size - 1)
			{
				result.push_back(num.at(q.front()));
			}
		}

		return result;
	}
};


// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
// 例如，如果输入数组{ 2,3,4,2,6,2,5,1 }及滑动窗口的大小3，
// 那么一共存在6个滑动窗口，他们的最大值分别为{ 4,4,6,6,6,5 }； 
// 针对数组{ 2,3,4,2,6,2,5,1 }的滑动窗口有以下6个：
// { [2,3,4],2,6,2,5,1 }，{ 2,[3,4,2],6,2,5,1 }，
// { 2,3,[4,2,6],2,5,1 }，{ 2,3,4,[2,6,2],5,1 }，
// { 2,3,4,2,[6,2,5],1 }，{ 2,3,4,2,6,[2,5,1] }。

int main()
{
	vector<int> nums = { 16,14,12,10,8,6,4 };
	Solution a;
	vector<int> result = a.maxInWindows(nums,1);
	return 0;
}
	


