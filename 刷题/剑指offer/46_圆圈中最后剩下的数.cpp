
#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
	int LastRemaining_Solution(int n, int m)//n个人数m
	{
		if (n <= 0 || m <= 0)
		{
			return -1;
		}
		vector<int> childs(n, 1);
		int cursize = n;
		int curnum = -1;
		int curpos = 0;
		while (true)
		{
			if (childs[curpos])
			{
				curnum++;
				if (curnum == m - 1)
				{
					curnum = -1;
					childs[curpos] = 0;
					cursize--;
					if (cursize == 0)
					{
						return curpos;
					}
				}
			}
			curpos++;
			if (curpos == n)
			{
				curpos = 0;
			}
		}
	}
};

//小朋友们围成一个大圈。然后,随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列.
//继续0...m-1报数....这样下去....直到剩下最后一个小朋友,
//求最后留下的小朋友的编号？(注：小朋友的编号是从0到n-1) 

int main()
{
	Solution a;
	auto result = a.LastRemaining_Solution(10,3);
	return 0;
}


