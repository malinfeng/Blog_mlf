
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution 
{
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) 
	{
		if (pushV.empty() || popV.empty())
		{
			return false;
		}
		if (pushV.size() != popV.size())
		{
			return false;
		}

		stack<int> helpStack;

		auto itpop = popV.cbegin();
		auto itpush = pushV.cbegin();
		while ( itpop != popV.cend() && itpush != pushV.cend())//出栈元素的顺序
		{
			if (!helpStack.empty() && helpStack.top() == *itpop)
			{
				helpStack.pop();
			}
			else
			{
				while (itpush != pushV.cend() && *itpush != *itpop)//找到出栈相同的节点
				{
					helpStack.push(*itpush);
					itpush++;
				}
				if (itpush == pushV.cend())
				{
					break;
				}
				itpush++;//找到出栈相同的节点后直接出栈
			}
			itpop++;
		}
		while (!helpStack.empty() && itpop != popV.cend())
		{
			if (helpStack.top() != *itpop)
			{
				return false;
			}
			helpStack.pop();
			itpop++;
		}
		if (itpop == popV.cend() && itpush == pushV.cend())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

// 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
// 假设压入栈的所有数字均不相等。
// 例如序列1, 2, 3, 4, 5是某栈的压入顺序，序列4, 5, 3, 2, 1是该压栈序列对应的一个弹出序列，
// 但4, 3, 5, 1, 2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）

int main()
{
	vector<int> pushV = { 1, 2, 3, 4, 5 };
	vector<int> popV = { 4, 5, 3, 2, 1 };

	Solution a;
	bool b = a.IsPopOrder(pushV, popV);
	system("pause");
}

