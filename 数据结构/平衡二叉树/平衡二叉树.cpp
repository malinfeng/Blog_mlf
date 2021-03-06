
#include <iostream>
#include "AVLTree.h"

template<typename T>
void Print(const std::vector<T> &a)
{
	for (auto it : a)
	{
		std::cout << it << "  ";
	}
	std::cout << std::endl;
}

int main()
{
	AVLTree<int> tree;
	std::vector<int> pre;
	std::vector<int> mid;
	std::vector<int> aft;
	std::vector<int> a = { 1,5,8,10,12,15,10 };
	std::cout << "原始数据：";
	Print(a);

	bool init = tree.InitTree(a);
	std::cout << "初始化状态：" << " " << init << std::endl;

	mid = tree.MidOrder();
	std::cout << "初始化后中序：";
	Print(mid);

	bool in1 = tree.Insert(20);
	bool in2 = tree.Insert(2);
	std::cout << "插入 20 2 的状态：" << " " << in1 << " " << in2 << std::endl;

	mid = tree.MidOrder();
	std::cout << "插入 20 2 后的中序：";
	Print(mid);

	bool has1 = tree.HasValue(8);
	bool has2 = tree.HasValue(7);
	std::cout << "查询 8 7 的状态：" << " " << has1 << " " << has2 << std::endl;

	bool de1 = tree.Delete(8);
	bool de2 = tree.Delete(7);
	std::cout << "删除 8 7 的状态：" << " " << de1 << " " << de2 << std::endl;

	mid = tree.MidOrder();
	std::cout << "删除 8 之后的中序：";
	Print(mid);

	pre = tree.PerOrder();
	std::cout << "删除 8 之后的前序：";
	Print(pre);
	aft = tree.AfterOrder();
	std::cout << "删除 8 之后的后序：";
	Print(aft);

	system("pause");
}


