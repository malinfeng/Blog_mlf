
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public://别人的代码，是真的简洁，好好体会！！！
	int GetUglyNumber_Solution(int index)
	{
		if (index < 7)return index;//前7个数一一对应
		vector<int> res(index);
		res[0] = 1;
		int t2 = 0, t3 = 0, t5 = 0, i;//t2 = 0, t3 = 0, t5 = 0分别为三个队列的头
		for (i = 1; i < index; ++i)
		{
			res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));//从三个队列头中取最小的数
			if (res[i] == res[t2] * 2)t2++;
			if (res[i] == res[t3] * 3)t3++;
			if (res[i] == res[t5] * 5)t5++;
		}
		return res[index - 1];
	}
};

// 把只包含质因子2、3和5的数称作丑数
// 例如6、8都是丑数，但14不是，因为它包含质因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

// 第 1 2 3 4 5 6 7 8 9  10  个
//    1 2 3 4 5 6 8 9 10 12
// 第7个为8

int main()
{
	Solution a;
	int result = a.GetUglyNumber_Solution(7);

	return 0;
}

