#pragma once
#include <vector>

#define MAX(a,b) a > b ? a : b

template <typename T>
 struct AVLNode
{
	AVLNode()
	{
		value = 0;
		lson = nullptr;
		rson = nullptr;
		freq = 0;
		hight = 0;
	}
	T value;
	AVLNode* lson;
	AVLNode* rson;
	int freq;
	int hight;
};

template <typename T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	bool InitTree(const std::vector<T> &vec);
	bool Insert(const T val);
	bool Delete(const T val);
	bool HasValue(T val);
	std::vector<T> PerOrder();
	std::vector<T> MidOrder();
	std::vector<T> AfterOrder();

private:
	void PreTravel(const AVLNode<T> *node, std::vector<T> &tempresult);
	void MidTravel(const AVLNode<T> *node, std::vector<T> &tempresult);
	void AfterTravel(const AVLNode<T> *node, std::vector<T> &tempresult);
	bool DoFind(const AVLNode<T> *node, const T val);
	bool DoInsert(AVLNode<T> *&node, const T val);
	bool DoDelete(AVLNode<T> *&node, const T val);

	int Hight(const AVLNode<T> *node);
	void SingleRotateLeft(AVLNode<T> *&node);
	void SingleRotateRight(AVLNode<T> *&node);
	void DoubleRotateRL(AVLNode<T> *&node);
	void DoubleRotateLR(AVLNode<T> *&node);

	AVLNode<T> *_pnode;

};



//===============模板函数实现==================//
template <typename T>
AVLTree<T>::AVLTree()
{
	_pnode = nullptr;
}

template <typename T>
AVLTree<T>::~AVLTree()
{
}

template <typename T>
bool AVLTree<T>::InitTree(const std::vector<T> &vec)
{
	bool result = true;
	for (auto it : vec)
	{
		if (Insert(it) == false)
		{
			result = false;
			break;
		}
	}
	return result;
}

template <typename T>
bool AVLTree<T>::Insert(const T val)
{
	return DoInsert(_pnode, val);
}

template <typename T>
bool AVLTree<T>::Delete(const T val)
{
	return DoDelete(_pnode, val);
}

template <typename T>
bool AVLTree<T>::DoDelete(AVLNode<T> *&node, const T val)
{
	bool result;
	if (node == nullptr)
	{
		result = false;
	}
	else if (val < node->value)//左子树中删除
	{
		result = DoDelete(node->lson, val);
		if (Hight(node->rson)-Hight(node->lson) == 2)//失去平衡，右子树比左子树高
		{
			if (Hight(node->rson->rson) > Hight(node->rson->lson))
			{
				SingleRotateRight(node);
			}
			else
			{
				DoubleRotateRL(node);
			}
		}
		node->hight = MAX(Hight(node->lson), Hight(node->rson)) + 1;
	}
	else if (val > node->value)//右子树中删除
	{
		result = DoDelete(node->rson, val);
		if (Hight(node->lson) - Hight(node->rson) == 2)//失去平衡，左子树比右子树高
		{
			if (Hight(node->lson->lson) > Hight(node->lson->rson))
			{
				SingleRotateLeft(node);
			}
			else
			{
				DoubleRotateLR(node);
			}
		}
		node->hight = MAX(Hight(node->lson), Hight(node->rson)) + 1;
	}
	else//相等，删除代码
	{
		if (node->lson == nullptr && node->rson == nullptr)//没孩子
		{
			if (node->freq == 1)//节点只有1个数据，直接删除节点
			{
				delete(node);
				node = nullptr;
				return true;//此处直接返回
			}
			else
			{
				node->freq--;
			}
		}
		else if (node->lson == nullptr)//一个右孩子
		{
			if (node->freq == 1)//节点只有1个数据，直接删除节点
			{ 
				node->value = node->rson->value;
				node->freq = node->rson->freq;
				delete(node->rson);
				node->rson = nullptr;
			}
			else
			{
				node->freq--;
			}
		}
		else if (node->rson == nullptr)//一个左孩子
		{
			if (node->freq == 1)//节点只有1个数据，直接删除节点
			{
				node->value = node->lson->value;
				node->freq = node->lson->freq;
				delete(node->lson);
				node->lson = nullptr;
			}
			else
			{
				node->freq--;
			}
		}
		else//两个孩子
		{
			if (node->freq == 1)//节点只有1个数据，直接删除节点
			{
				AVLNode<T> *derectAfter = node->rson;
				while (derectAfter->lson != nullptr)//求直接后继
				{
					derectAfter = derectAfter->lson;
				}
				node->value = derectAfter->value;
				node->freq = derectAfter->freq;
				DoDelete(derectAfter,val);
				if (Hight(node->lson) - Hight(node->rson) == 2)//失去平衡，左子树比右子树高
				{
					if (Hight(node->lson->lson) > Hight(node->lson->rson))
					{
						SingleRotateLeft(node);
					}
					else
					{
						DoubleRotateLR(node);
					}
				}
			}
			else
			{
				node->freq--;
			}
		}
		node->hight = MAX(Hight(node->lson), Hight(node->rson)) + 1;
		result = true;
	}
	return result;
}

template <typename T>
bool AVLTree<T>::HasValue(T val)
{
	return DoFind(_pnode, val);

}

template <typename T>
bool AVLTree<T>::DoFind(const AVLNode<T> *node, const T val)
{
	if (node == nullptr)
	{
		return false;
	}
	if (val == node->value)
	{
		return true;
	}
	else if (val < node->value)
	{
		return DoFind(node->lson, val);
	}
	else
	{
		return DoFind(node->rson, val);
	}
}

template <typename T>
bool AVLTree<T>::DoInsert(AVLNode<T> *&node, const T val)
{
	bool result;
	if (node == nullptr)
	{
		node = new AVLNode<T>();
		node->value = val;
		node->freq++;
		result = true;
	}
	else if (val < node->value)
	{
		result = DoInsert(node->lson, val);
		if (Hight(node->lson) - Hight(node->rson) == 2)//失去平衡，左子树比右子树高
		{
			if (Hight(node->lson->lson) > Hight(node->lson->rson))
			{
				SingleRotateLeft(node);
			}
			else
			{
				DoubleRotateLR(node);
			}
		}
	}
	else if (val > node->value)
	{
		result = DoInsert(node->rson, val);
		if (Hight(node->rson) - Hight(node->lson) == 2)//失去平衡，右子树比左子树高
		{
			if (Hight(node->rson->rson) > Hight(node->rson->lson))
			{
				SingleRotateRight(node);
			}
			else
			{
				DoubleRotateRL(node);
			}
		}
	}
	else
	{
		node->freq++;
		result = true;
	}
	node->hight = MAX(Hight(node->lson), Hight(node->rson)) + 1;
	return result;
}

template <typename T>
void AVLTree<T>::PreTravel(const AVLNode<T> *node, std::vector<T> &tempresult)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		for (int i = 0; i < node->freq; ++i)
		{
			tempresult.push_back(node->value);
		}
		PreTravel(node->lson, tempresult);
		PreTravel(node->rson, tempresult);
	}
}

template <typename T>
std::vector<T> AVLTree<T>::PerOrder()
{
	std::vector<T> result;
	PreTravel(_pnode, result);
	return result;

}

template <typename T>
void AVLTree<T>::MidTravel(const AVLNode<T> *node, std::vector<T> &tempresult)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		MidTravel(node->lson, tempresult);
		for (int i = 0; i < node->freq; ++i)
		{
			tempresult.push_back(node->value);
		}
		MidTravel(node->rson, tempresult);
	}
}

template <typename T>
std::vector<T> AVLTree<T>::MidOrder()
{
	std::vector<T> result;
	MidTravel(_pnode, result);
	return result;

}

template <typename T>
void AVLTree<T>::AfterTravel(const AVLNode<T> *node, std::vector<T> &tempresult)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		AfterTravel(node->lson, tempresult);
		AfterTravel(node->rson, tempresult);
		for (int i = 0; i < node->freq; ++i)
		{
			tempresult.push_back(node->value);
		}
	}
}

template <typename T>
std::vector<T> AVLTree<T>::AfterOrder()
{
	std::vector<T> result;
	AfterTravel(_pnode, result);
	return result;

}

template <typename T>
void AVLTree<T>::SingleRotateLeft(AVLNode<T> *&k2)
{
	AVLNode<T> *k1 = k2->lson;
	k2->lson = k1->rson;
	k1->rson = k2;
	k1->hight = MAX(Hight(k1->lson), Hight(k1->rson)) + 1;//更新高度
	k2->hight = MAX(Hight(k2->lson), Hight(k2->rson)) + 1;
	k2 = k1;
}

template <typename T>
void AVLTree<T>::SingleRotateRight(AVLNode<T> *&k2)
{
	AVLNode<T> *k1 = k2->rson;
	k2->rson = k1->lson;
	k1->lson = k2;
	k1->hight = MAX(Hight(k1->lson), Hight(k1->rson)) + 1;//更新高度
	k2->hight = MAX(Hight(k2->lson), Hight(k2->rson)) + 1;
	k2 = k1;
}

template <typename T>
void AVLTree<T>::DoubleRotateRL(AVLNode<T> *&k2)
{
	SingleRotateLeft(k2->rson);
	SingleRotateRight(k2);
}

template <typename T>
void AVLTree<T>::DoubleRotateLR(AVLNode<T> *&k2)
{
	SingleRotateRight(k2->lson);
	SingleRotateLeft(k2);
}

template <typename T>
int AVLTree<T>::Hight(const AVLNode<T> *node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return node->hight;
}