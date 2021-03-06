// 堆.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "Heap.h"  

#include <iostream>  
#include <vector>

using namespace  std;

int main()
{
	Heap<int> myheap;

	vector<int> sourcedata = { 21,13,19,16,24,31,65,36,32,68 };
	std::cout << "初始化的数据：";
	for (int i = 0; i < sourcedata.size(); ++i)
	{
		std::cout << sourcedata[i] << " ";
	}
	std::cout << std::endl;
	myheap.InitHeap(sourcedata);

	std::cout << "初始化的堆：";
	vector<int> data = myheap.GetData();
	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

	myheap.Push(14);

	std::cout << "push 14 后的堆：";
	data = myheap.GetData();
	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

	myheap.Pop();

	std::cout << "pop后的堆：";
	data = myheap.GetData();
	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}