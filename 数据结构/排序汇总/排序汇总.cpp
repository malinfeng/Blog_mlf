
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

#define NUM_MAX 100

void Printdata(vector<int> &data)
{
	int tempcount = 0;
	for (unsigned int i = 0; i < data.size(); ++i)
	{
		if (tempcount == 10)
		{
			std::cout << endl;
			tempcount = 0;
		}
		std::cout << data[i] << "\t";
		tempcount++;
	}
	std::cout << endl << endl;
}

void InitData(vector<int> &data)
{
	data.reserve(NUM_MAX);
	srand((int)time(0));
	for (unsigned int i = 0; i < NUM_MAX; ++i)
	{
		data.push_back(rand() % 1000);
	}

	std::cout << "原始数据为：" << endl;
	Printdata(data);
}

void BubbleSort(vector<int> &data)
{
	for (unsigned int i = 1; i < data.size(); i++)
	{
		for (unsigned int j = i; j > 0; --j)
		{
			if (data[j - 1] < data[j])
			{
				swap(data[j - 1], data[j]);
			}
		}
	}
}

void InsertSort(vector<int> &data)
{
	for (unsigned int i = 0; i < data.size(); ++i)
	{
		for (int j = i; j - 1 >= 0; --j)
		{
			if (data[j] > data[j - 1])
			{
				swap(data[j], data[j - 1]);
			}
			else
			{
				continue;
			}
		}

	}
}

void ChoiceSort(vector<int> &data)
{
	for (unsigned int i = 0; i < data.size(); ++i)
	{
		int maxpos = i;
		for (unsigned int j = i; j < data.size(); ++j)
		{
			if (data[j] > data[maxpos])
			{
				maxpos = j;
			}
		}
		swap(data[maxpos], data[i]);
	}
}

int Partition(vector<int> &data, int start, int end)
{
	int flag = start;
	while (start < end)
	{
		//先走的一定是标杆的对段！！！记住
		while (start < end && data[end] < data[flag])
		{
			end--;
		}
		while (start < end && data[start] >= data[flag])
		{
			start++;
		}
		if (start < end)
		{
			swap(data[start], data[end]);
		}
	}
	swap(data[end], data[flag]);
	return start;
}

void DoQuickSort(vector<int> &data, int start, int end)
{
	if (start < end)
	{
		int flag = Partition(data, start, end);
		DoQuickSort(data, start, flag - 1);
		DoQuickSort(data, flag + 1, end);
	}
}

void QuickSort(vector<int> &data)
{
	DoQuickSort(data, 0, data.size() - 1);
}

void DoMergeSort(vector<int> &data, vector<int> &helper, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		//归并分区间的技巧是一定要保证区间不能重复，不然可能陷入死递归调用
		DoMergeSort(data, helper, start, mid);
		DoMergeSort(data, helper, mid + 1, end);

		int i = start, j = mid + 1;
		int helppos = start;
		while (i <= mid && j <= end)
		{
			if (data[i] > data[j])
			{
				helper[helppos++] = data[i++];
			}
			else
			{
				helper[helppos++] = data[j++];
			}
		}

		while (i <= mid)
		{
			helper[helppos++] = data[i++];
		}
		while (j <= end)
		{
			helper[helppos++] = data[j++];
		}

		helppos = start;
		while (helppos <= end)
		{
			data[helppos] = helper[helppos];
			helppos++;
		}
	}
}

void MergeSort(vector<int> &data)
{
	vector<int> help = data;
	DoMergeSort(data, help, 0, data.size() - 1);
}

//建立小顶堆
void AdjustHeap(vector<int> &data, int start, int end)
{
	while (start < end)
	{
		int child = 2 * start + 1;
		if (child + 1 <= end  && data[child + 1] < data[child] )
		{
			child++;
		}
		if (child <= end && data[child] < data[start])
		{
			swap(data[child], data[start]);
			start = child;
		}
		else
		{
			return;
		}
	}

}

void HeapSort(vector<int> &data)
{
	for (int i = data.size() / 2; i >= 0; --i)
	{
		AdjustHeap(data, i, data.size() - 1);
	}

	for (int i = data.size() - 1; i >= 0; --i)
	{
		AdjustHeap(data, 0, i);
		swap(data[0], data[i]);
	}
}

void ShellSort(vector<int> &data)
{
	//gap为组元素的间隔，同时也是组数
	//组数遍历与组内元素遍历可以合为一个循环，因为两个for也是遍历一次整个数组，可合并为一个for遍历
	for (int gap = data.size() / 2; gap >= 1; gap /= 2)
	{
		for (int i = 0; i < gap; ++i)//组数遍历
		{
			for (unsigned int j = i; j < data.size(); j += gap)//组内元素遍历
			{
				for (int k = j; k - gap >= 0 && data[k] > data[k - gap]; k -= gap)//组内排序
				{
					std::swap(data[k], data[k - gap]);
				}
			}
		}
	}
}

void DoSort(vector<int> data)
{
	vector<int> data1 = data;
	BubbleSort(data1);
	std::cout << "冒泡排序后结果：" << std::endl;
	Printdata(data1);

	vector<int> data2 = data;
	InsertSort(data2);
	std::cout << "插入排序后结果：" << std::endl;
	Printdata(data2);

	vector<int> data3 = data;
	ChoiceSort(data3);
	std::cout << "选择排序后结果：" << std::endl;
	Printdata(data3);

	vector<int> data4 = data;
	QuickSort(data4);
	std::cout << "快速排序后结果：" << std::endl;
	Printdata(data4);

	vector<int> data5 = data;
	MergeSort(data5);
	std::cout << "归并排序后结果：" << std::endl;
	Printdata(data5);

	vector<int> data6 = data;
	HeapSort(data6);
	std::cout << "堆排序后结果：" << std::endl;
	Printdata(data6);

	vector<int> data7 = data;
	ShellSort(data7);
	std::cout << "希尔排序后结果：" << std::endl;
	Printdata(data7);
}


int main()
{
	vector<int> data;
	InitData(data);
	DoSort(data);

	return 0;
}

