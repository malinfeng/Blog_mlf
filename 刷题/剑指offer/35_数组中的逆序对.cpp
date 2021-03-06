
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	//使用归并排序的技巧
	int InversePairs(vector<int> data)
	{
		if (data.empty())
		{
			return 0;
		}
		int ret = 0;
		vector<int> merge(data.size());
		Merge(data, merge, 0, data.size() - 1, ret);//分区

		return ret;
	}

	void Merge(vector<int> &data, vector<int> &merge, int start, int end, int &count)
	{
		if (start == end)
		{
			return;
		}
		int mid = (start + end) / 2;
		Merge(data, merge, start, mid, count);
		Merge(data, merge, mid + 1, end, count);
		Merge_gui(data, merge, start, mid, end, count);
	}

	void Merge_gui(vector<int> &data, vector<int> &merge, int start, int mid, int end, int &count)
	{
		int i = mid;
		int j = end;
		int posCount = end;
		while (i >= start && j >= mid + 1)//此处必须从后往前遍历
		{
			if (data.at(i) > data.at(j))//前面大于后面，逆序对，并且逆序对的个数与j的位置有关！！！
			{
				count += (j - mid);
				merge.at(posCount) = data.at(i);
				i--;
				posCount--;
			}
			else
			{
				merge.at(posCount) = data.at(j);
				j--;
				posCount--;
			}
		}

		while (i >= start)
		{
			merge.at(posCount) = data.at(i);
			i--;
			posCount--;
		}

		while (j >= mid + 1)
		{
			merge.at(posCount) = data.at(j);
			j--;
			posCount--;
		}

		for (int i = end; i >= start; --i)//反向复制数组
		{
			data.at(i) = merge.at(i);
		}

		return;
	}
};

// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组, 求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P % 1000000007

// 1, 2, 3, 4, 5, 6, 7, 0
// 结果为 7
int main()
{
	vector<int> vec = { 364,637,341,406,747,995,234,971,571,219,
		993,407,416,366,315,301,601,650,418,355,
		460,505,360,965,516,648,727,667,465,849,
		455,181,486,149,588,233,144,174,557,67,
		746,550,474,162,268,142,463,221,882,576,
		604,739,288,569,256,936,275,401,497,82,
		935,983,583,523,697,478,147,795,380,973,
		958,115,773,870,259,655,446,863,735,784,
		3,671,433,630,425,930,64,266,235,187,
		284,665,874,80,45,848,38,811,267,575 };//结果2519
	//vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 0 };
	Solution a;
	int result = a.InversePairs(vec);
	return 0;
}

