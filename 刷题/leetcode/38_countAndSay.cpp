#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
	string countAndSay(int n)
	{
		string str[2];
		str[1] = "1";
		if (n == 1)
		{
			return str[1];
		}
		for (int i = 2; i <= n; ++i)
		{
			int last = (i - 1) % 2;
			int cur = i % 2;
			str[cur] = "";
			int count = 1;
			for (int j = 1; j < str[last].size(); ++j)
			{
				if (str[last][j] == str[last][j - 1])
				{
					count++;
				}
				else//new cha
				{
					str[cur] += '0' + count;
					str[cur] += str[last][j - 1];
					count = 1;
				}
			}
			str[cur] += '0' + count;//last cha
			str[cur] += str[last].back();
					
		}
		return str[n % 2];
	}
};
/*
「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221


1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出外观数列的第 n 项。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-and-say
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	auto ret = a.countAndSay(5);
	return 0;
}
