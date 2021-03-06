
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string LeftRotateString(string str, int n) //循环左移
	{
		if (n < 0 || str.empty())
		{
			return str;
		}
		n = n % str.size();
		Rotate(str, 0, n - 1);
		Rotate(str, n, str.size() - 1);
		Rotate(str, 0, str.size() - 1);
		return str;
	}

	void Rotate(string &str, int start, int end)
	{
		while (start < end)
		{
			swap(str[start], str[end]);
			start++;
			end--;
		}
	}
};

//对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
//例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。

int main()
{
	string str = "abcXYZdef";
	Solution a;
	auto result = a.LeftRotateString(str, 3);
	return 0;
}


