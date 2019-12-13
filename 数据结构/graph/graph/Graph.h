#pragma once
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>

//边是否有方向
#define DIRECTION 1
//最大顶点数量
#define MAXVERTEX 20

struct Edge
{
	Edge(int start, int end, int weight)
		:
		_startIdx(start),
		_endIdx(end),
		_weight(weight),
		_pnext(NULL)
	{}
	int _startIdx;
	int _endIdx;
	int _weight;
	Edge *_pnext;	//邻接表中，指向下一个边
};

template <typename T>
struct Vertex
{
	Vertex() 
		:
		_data(0),
		_edge(NULL)
	{}
	Vertex(std::string &str, T d)
		:
		_data(d),
		_edge(NULL)
	{}
	std::string name;	//顶点名字
	T _data;				//数据
	Edge *_edge;			//与之相关边的指针
};



template <typename T>
class Graph//使用标准方式--邻接表表示的图
{
public:
	Graph():
		_curVertexNum(0)
	{
		_vertexs.resize(MAXVERTEX);
	}
	~Graph()//应该析构相应的动态内存
	{

	}

	void dfs(std::string startVertex)
	{
		if (_name2idx.find(startVertex) == _name2idx.end())
		{
			std::cout << "顶点不存在" << std::endl;
			return;
		}
		int curIdx = _name2idx[startVertex];
		std::vector<int> visited(_curVertexNum, 0);
		std::stack<int> mys;
		int visitedNum = 0;
		mys.push(curIdx);
		while (visitedNum < _curVertexNum)
		{
			if (mys.empty())
			{
				std::cout << "该图为非连通图" << std::endl;
				return;
			}
			curIdx = mys.top();
			mys.pop();

			std::cout << _vertexs[curIdx].name << std::endl;	//访问操纵
			visitedNum++;
			visited[curIdx] = 1;
			Edge *tempEdge = _vertexs[curIdx]._edge;
			while (tempEdge)
			{
				if (!visited[tempEdge->_endIdx])
				{
					mys.push(tempEdge->_endIdx);
				}
				tempEdge = tempEdge->_pnext;
			}
		}
	}

	void bfs(std::string startVertex)
	{
		if (_name2idx.find(startVertex) == _name2idx.end())
		{
			std::cout << "顶点不存在" << std::endl;
			return;
		}
		int curIdx = _name2idx[startVertex];
		std::vector<int> visited(_curVertexNum, 0);
		std::queue<int> myq;
		myq.push(curIdx);	//只要放入队列中，就相当于被访问了，因为不可重复添加进队列
		visited[curIdx] = 1;
		while (!myq.empty())
		{
			curIdx = myq.front();
			myq.pop();
			std::cout << _vertexs[curIdx].name << std::endl;	//访问操纵
			Edge *tempEdge = _vertexs[curIdx]._edge;
			while (tempEdge)
			{
				if (!visited[tempEdge->_endIdx])
				{
					myq.push(tempEdge->_endIdx);
					visited[tempEdge->_endIdx] = 1;
				}
				tempEdge = tempEdge->_pnext;
			}
		}
	}

	void modVertex(std::string name, T data)
	{
		int curidx = 0;
		if (_name2idx.find(name) != _name2idx.end())//顶点已经添加
		{
			curidx = _name2idx[name];
		}
		else//新顶点
		{
			_name2idx[name] = _curVertexNum;
			curidx = _curVertexNum;
			_curVertexNum++;
		}
		_vertexs[curidx].name = name;
		_vertexs[curidx]._data = data;
	}

	void modEdge(std::string start, std::string end, int weight)
	{
		int startidx = 0;
		int endidx = 0;
		if (_name2idx.find(start) == _name2idx.end()	
			|| _name2idx.find(end) == _name2idx.end())	//保证顶点存在
		{
			return;
		}
		startidx = _name2idx[start];
		endidx = _name2idx[end];

		addedge_num(startidx, endidx, weight);
		if (!DIRECTION)//无向图
		{
			addedge_num(endidx, startidx, weight);
		}
	}

	std::map<std::string, int> dijsktra(std::string start)
	{
		std::map<std::string, int> retmap;
		if (_name2idx.find(start) == _name2idx.end())
		{
			std::cout << "顶点不存在" << std::endl;
			return retmap;
		}
		int curIdx = _name2idx[start];

		std::vector<int> s(_curVertexNum, 0);//S集
		std::vector<int> dis(_curVertexNum, INT_MAX);//dis集
		dis[curIdx] = 0;
		Edge *tempEdge = _vertexs[curIdx]._edge;
		while (tempEdge)//初始化dis集
		{
			dis[tempEdge->_endIdx] = tempEdge->_weight;
			tempEdge = tempEdge->_pnext;
		}

		int visitedNum = 1;
		while (visitedNum < _curVertexNum)
		{
			int curmindis = INT_MAX; 
			curIdx = -1;
			for (int i = 0; i < _curVertexNum; ++i)
			{
				if (!s[i] && dis[i] < curmindis)
				{
					curIdx = i;
				}
			}
			if (curIdx == -1)//非连通图，并且已经遍历完
			{
				for (unsigned int i = 0; i < _vertexs.size(); ++i)
				{
					retmap[_vertexs[i].name] = dis[i];
				}
				return retmap;
			}

			tempEdge = _vertexs[curIdx]._edge;
			while (tempEdge)//更新dis
			{
				//dis到当前点 + 当前点到新点 < dis到新点
				if (dis[curIdx] + tempEdge->_weight < dis[tempEdge->_endIdx])
				{
					dis[tempEdge->_endIdx] = dis[curIdx] + tempEdge->_weight;
				}
				tempEdge = tempEdge->_pnext;
			}
			
			visitedNum++;
		}

		for (int i = 0; i < _curVertexNum; ++i)
		{
			retmap[_vertexs[i].name] = dis[i];
		}
		return retmap;
	}

	//无向图算法
	Graph<T> prim()
	{
		Graph<T> retg;
		if (_curVertexNum == 0)
		{
			return retg;
		}
		if (!DIRECTION)
		{
			return retg;
		}
		std::vector<int> visited(_curVertexNum, 0);
		visited[0] = 1;
		retg.modVertex(_vertexs[0].name, _vertexs[0]._data);
		int vertexnum = 1;

		while (vertexnum < _curVertexNum)
		{
			int curminWeight = INT_MAX;
			Edge *nextEdge = NULL;
			for (int i = 0; i < _curVertexNum; ++i)
			{
				if (visited[i])//起点visit
				{
					Edge *tempEdge = _vertexs[i]._edge;
					while (tempEdge)
					{
						if (!visited[tempEdge->_endIdx] && tempEdge->_weight < curminWeight)
						{
							curminWeight = tempEdge->_weight;
							nextEdge = tempEdge;
						}
						tempEdge = tempEdge->_pnext;
					}
				}
			}
			if (nextEdge)
			{
				retg.modVertex(_vertexs[nextEdge->_endIdx].name, _vertexs[nextEdge->_endIdx]._data);
				retg.modEdge(_vertexs[nextEdge->_startIdx].name, _vertexs[nextEdge->_endIdx].name, nextEdge->_weight);
				visited[nextEdge->_endIdx] = 1;
				vertexnum++;
			}
			else
			{
				std::cout << "该图为非连通图" << std::endl;
				break;
			}
		}
		return retg;
	}

	//无向图算法
	Graph<T> kruskal()
	{
		Graph<T> retg;
		if (!DIRECTION)
		{
			return retg;
		}
		std::vector<Edge*> edges;	//边表
		std::vector<int> fathers(_curVertexNum, -1);	//并查集

		for (int i = 0; i < _curVertexNum; ++i)
		{
			retg.modVertex(_vertexs[i].name, _vertexs[i]._data);//默认添加所有顶点
			Edge *tempEdge = _vertexs[i]._edge;
			while (tempEdge)
			{
				edges.push_back(tempEdge);
				tempEdge = tempEdge->_pnext;
			}
		}
		sort(edges.begin(), edges.end(), CMP);

		unsigned int degesIdx = 0;
		Edge *curEdge = NULL;
		int edgenum = 0;

		while (edgenum < _curVertexNum - 1 && degesIdx < edges.size())
		{
			curEdge = edges[degesIdx];
			int startf = familyFather(fathers, curEdge->_startIdx);
			int endf = familyFather(fathers, curEdge->_endIdx);

			if (startf != endf)//边合适
			{
				fathers[endf] = startf;
				retg.modEdge(_vertexs[curEdge->_startIdx].name, _vertexs[curEdge->_endIdx].name, curEdge->_weight);
				edgenum++;
			}
			degesIdx++;
		}
		return retg;
	}
	

	//使用矩阵方式打印图
	void printGraph()
	{
		std::vector<std::vector<int> > tempgraph(_curVertexNum, std::vector<int>(_curVertexNum, 0));
		
		// 第一行打印名字
		std::cout << '\t';
		for (int i = 0; i < _curVertexNum; ++i)
		{
			std::cout << _vertexs[i].name << '\t';
		}
		std::cout << std::endl;

		for (int i = 0; i < _curVertexNum; ++i)//i为起点
		{
			Edge *pcurEdge = _vertexs[i]._edge;
			while (pcurEdge)
			{
				tempgraph[pcurEdge->_startIdx][pcurEdge->_endIdx] = pcurEdge->_weight;
				pcurEdge = pcurEdge->_pnext;
			}
		}
		for (unsigned int i = 0; i < tempgraph.size(); ++i)
		{
			std::cout << _vertexs[i].name << '\t';
			for (unsigned int j = 0; j < tempgraph[i].size(); ++j)
			{
				std::cout << tempgraph[i][j] << '\t';
			}
			std::cout << std::endl;
		}
	}
private:
	//添加一条有向边
	void addedge_num(int startIdx, int endIdx, int weight)
	{
		Vertex<T> &curV = _vertexs[startIdx];
		Edge *pedge = curV._edge;
		if (pedge)
		{
			while (pedge->_pnext)
			{
				if (pedge->_endIdx == endIdx)//说明该边存在
				{
					pedge->_weight = weight;
					return;
				}
				pedge = pedge->_pnext;
			}
			pedge->_pnext = new Edge(startIdx, endIdx, weight);
			return;
		}
		else
		{
			curV._edge = new Edge(startIdx, endIdx, weight);
			return;
		}
	}

	static bool CMP(Edge *e1, Edge *e2)
	{
		return e1->_weight < e2->_weight;
	}

	int familyFather(const std::vector<int> &father, int idx)
	{
		while (father[idx] != -1 && father[idx] != idx)
		{
			idx = father[idx];
		}
		return idx;
	}
private:
	std::vector<Vertex<T>> _vertexs;
	std::map<std::string, int> _name2idx;
	int _curVertexNum;
};

