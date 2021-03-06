// Prim算法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "Graph.h"

int main()
{
	Graph<int> mygraph;
	mygraph.modVertex("V1", 0);
	mygraph.modVertex("V2", 0);
	mygraph.modVertex("V3", 0);
	mygraph.modVertex("V4", 0);
	mygraph.modVertex("V5", 0);
	mygraph.modVertex("V6", 0);
	mygraph.modVertex("V7", 0);

	mygraph.modEdge("V1", "V2", 2);
	mygraph.modEdge("V1", "V3", 4);
	mygraph.modEdge("V1", "V4", 1);
	mygraph.modEdge("V2", "V4", 3);
	mygraph.modEdge("V2", "V5", 10);
	mygraph.modEdge("V3", "V4", 2);
	mygraph.modEdge("V4", "V5", 7);
	mygraph.modEdge("V3", "V6", 5);
	mygraph.modEdge("V4", "V6", 8);
	mygraph.modEdge("V4", "V7", 4);
	mygraph.modEdge("V5", "V7", 6);
	mygraph.modEdge("V6", "V7", 1);

	mygraph.printGraph();
	std::cout << std::endl;

	mygraph.dfs("V1");
	std::cout << std::endl;

	mygraph.bfs("V1");
	auto ret = mygraph.dijsktra("V1");
	std::cout << std::endl;

	auto ming1 = mygraph.prim();
	ming1.printGraph();
	std::cout << std::endl;

	auto ming2 = mygraph.kruskal();
	ming2.printGraph();
	std::cout << std::endl;
	return 0;
}

