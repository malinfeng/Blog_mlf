#pragma once
#include <vector>

using namespace std;

//小顶堆
template <typename T>
class Heap
{
public:
	Heap();
	Heap(const vector<T> &data);
	~Heap();

	void InitHeap(const vector<T> &data);
	void Push(T elem);
	void Pop();
	T Top();

	vector<T> GetData();

private:
	///从rootnum节点处向下调整堆
	void AdjustHeap(int rootnum);
	///从startnum处上溯节点
	void UpOP(int startnum);

private:
	vector<T> _data;//使用vector实现的堆
};

template <typename T>
Heap<T>::Heap()
{

}

template <typename T>
Heap<T>::Heap(const vector<T> &data)
{
	InitHeap(data);
}

template <typename T>
Heap<T>::~Heap()
{
}

template <typename T>
vector<T> Heap<T>::GetData()
{
	return _data;
}

template <typename T>
void Heap<T>::InitHeap(const vector<T> &data)
{
	for (int i = 0; i < data.size(); ++i)
	{
		_data.push_back(data[i]);
	}
	for (int i = data.size() / 2 - 1; i >= 0; i--)
	{
		AdjustHeap(i);
	}
}

template <typename T>
void Heap<T>::Push(T elem)
{
	_data.push_back(elem);
	UpOP(_data.size() - 1);
}

template <typename T>
void Heap<T>::Pop()
{
	std::swap(_data[0], _data.back());
	_data.pop_back();
	AdjustHeap(0);
}

template <typename T>
T Heap<T>::Top()
{
	if (_data.empty())
	{
		throw std::logic_error("error");
	}
	return _data[0];
}

template <typename T>
void Heap<T>::AdjustHeap(int rootnum)
{
	int parentIdx = rootnum;
	int childIdx = 2 * parentIdx + 1;
	if (childIdx + 1 < _data.size() && _data[childIdx + 1] < _data[childIdx])//更小的子节点
	{
		childIdx++;
	}
	while (childIdx < _data.size())
	{
		if (_data[parentIdx] > _data[childIdx])
		{
			std::swap(_data[parentIdx], _data[childIdx]);
		}
		else//完成堆调整
		{
			break;
		}
		parentIdx = childIdx;
		childIdx = 2 * parentIdx + 1;
		if (childIdx + 1 < _data.size() && _data[childIdx + 1] < _data[childIdx])//更小的子节点
		{
			childIdx++;
		}
	}
}

template <typename T>
void Heap<T>::UpOP(int startnum)
{
	//start 表示孩子
	int parentIdx = (startnum - 1) / 2;
	while (parentIdx >= 0)
	{
		if (_data[parentIdx] > _data[startnum])
		{
			std::swap(_data[parentIdx], _data[startnum]);
		}
		else
		{
			break;
		}
		startnum = parentIdx;
		parentIdx = (startnum - 1) / 2;
	}
}