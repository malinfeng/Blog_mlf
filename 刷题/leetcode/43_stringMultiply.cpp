#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

#if 0
class Solution{//自己的传统解法，竖式分解
public:
	string multiply(string num1, string num2)
	{
		string ret("0");
        if (num1.size() < num2.size())
	    {
            num1.swap(num2);
        }
    	for (int i = 0; i < num2.size(); ++i)
		{
			multiplyOne(num1, num2[i], num2.size() - i - 1, ret);
		}
		return ret;
	}

	void multiplyOne(const string &num1, char num2, int zeroNum, string &ret)
	{
		if (num2 == '0')
		{
			return;
		}
		string tempnum1 = num1;
		int addnum = 0;
		for (int i = num1.size() - 1; i >= 0; --i)
		{
			int curnum = (num2 - '0') * (num1[i] - '0') + addnum;
			addnum = curnum / 10;
			tempnum1[i] = '0' + (curnum % 10);
		}
		if (addnum)
		{
			tempnum1.insert(0, 1, '0' + addnum);
			addnum = 0;
		}
		if (zeroNum)
		{
			tempnum1 += string(zeroNum, '0');
		}
		
		if (tempnum1.size() > ret.size())
		{
			tempnum1.swap(ret);
		}
		int i = ret.size() - 1;
		int j = tempnum1.size() - 1;
		
		while (i >= 0 && j >= 0)
		{
			int curnum = ret[i] - '0' + tempnum1[j] - '0' + addnum;
			addnum = curnum / 10;
			ret[i] = '0' + (curnum % 10);
			i--;
			j--;
		}
		while (addnum && i >= 0)//last addnum
		{
			int curnum = ret[i] - '0' + addnum;
			addnum = curnum / 10;
			ret[i] = '0' + (curnum % 10);
			i--;
		}
		if (addnum)
		{
			ret.insert(0, 1, '0' + addnum);
		}

	}
};
#else

class Solution
{
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
		{
			return "0";
		}
		vector<int> ret(num1.size() + num2.size(), 0);
		vector<int> addnum(num1.size() + num2.size(), 0);
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		for (int i = 0; i < num1.size(); ++i)
		{
			for (int j = 0; j < num2.size(); ++j)
			{
				int curnum = ret[i + j];
				curnum += (num1[i] - '0') * (num2[j] - '0');
				addnum[i + j + 1] += curnum / 10;
				ret[i + j] = curnum % 10 ;
			}
		}

		for (int i = 0; i < ret.size(); ++i)
		{
			if (addnum[i] > 0)
			{
				ret[i] += addnum[i];
			}
			if (ret[i] > 9)
			{
				addnum[i + 1] += ret[i] / 10;
				ret[i] = ret[i] % 10;
			}
		}
		
		string retstr;
		int last = num1.size() + num2.size() - 1;
		int pos = ret[last] != 0 ? last : last - 1;
		while (pos >= 0)
		{
			retstr += ret[pos] + '0';
			pos--;
		}
		return retstr;
	}

};

#endif




/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/multiply-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

int main()
{
	Solution a;
	string num1("123");
	string num2("456");
	auto ret = a.multiply(num1, num2);
	return 0;
}
