
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	void Insert(int num)
	{
		if (smallq.empty() || num <= smallq.top())
		{
			smallq.push(num);
		}
		else
		{
			bigq.push(num);
		}
		if (smallq.size() == bigq.size() + 2)
		{
			bigq.push(smallq.top());
			smallq.pop();
		}
		if (bigq.size() == smallq.size() + 2)
		{
			smallq.push(bigq.top());
			bigq.pop();
		}
	}
	double GetMedian()
	{
		if (smallq.size() == bigq.size())
		{
			return double(smallq.top() + bigq.top()) / 2.0;
		}
		else if (smallq.size() > bigq.size())
		{
			return smallq.top();
		}
		else
		{
			return bigq.top();
		}
	}
	priority_queue<int, vector<int>, greater<int>> bigq;
	priority_queue<int, vector<int>, less<int>> smallq;
};

//我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

int main()
{

	return 0;
}