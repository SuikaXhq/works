#pragma once
#define UNVISITED 0
#define VISITING 1
#define VISITED 2

#include<iostream>
#include<stack>
#include<fstream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

int clock = 0;
int treeEdge = 0;
int backEdge = 1;
int forwardEdge = 2;
int crossEdge = 3;

struct Node
{
	char data;
	int status;//0为unvisited，1为visiting，2为visited
	int time;
	vector<Node*>nexts;
	Node(char dat, int stat)
	{
		data = dat;
		status = stat;
		time = 0;
	}
};

struct Edge 
{
	Node* start;
	Node* end;
	int type;//0为tree edge 1为back edge 2为forward edge 3为cross edge;
	Edge(Node* st, Node* ed) 
	{
		start = st;
		end = ed;
		type = 0;
	}
};

struct Graph
{
	vector<Edge*>edge;
	unordered_map<Node*, Node*>parent;//子节点->父节点映射关系
	vector<Node*>vertex;//表头结点
	vector<Edge*>back_edges;
	int findEdge(Node* a, Node* b)
	{
		for (int i = 0; i < edge.size(); i++)
		{
			if (edge[i]->start == a && edge[i]->end == b)
				return i;
		}
	}
	void initialDFS()
	{
		for (int i = 0; i < vertex.size(); i++)
			vertex[i]->status = UNVISITED;
	}
	int posInVertex(char dat1, vector<Node*> vertex, int nodeNumber)
	{
		for (int i = 0; i < nodeNumber; i++)
		{
			if (vertex[i]->data == dat1)
				return i;
		}
	}

	void singleDFS(Node* s, stack<Node*> &DFSstack, bool is_sort)
	{
		s->status = VISITING;
		s->time = ::clock;
		::clock++;
		for (int i = 0; i < s->nexts.size(); i++)
		{
			if (s->nexts[i]->status == UNVISITED)
			{
				parent.insert(make_pair(s->nexts[i], s));
				edge[findEdge(s, s->nexts[i])]->type = treeEdge;
				singleDFS(s->nexts[i], DFSstack, is_sort);
			}
			else if (s->nexts[i]->status == VISITING)
			{
				edge[findEdge(s, s->nexts[i])]->type = backEdge;
				back_edges.push_back(edge[findEdge(s, s->nexts[i])]);
			}
			else if (s->time < s->nexts[i]->time)
			{
				edge[findEdge(s, s->nexts[i])]->type = forwardEdge;
			}
			else edge[findEdge(s, s->nexts[i])]->type = crossEdge;
		}
	if (is_sort)
	{
		DFSstack.push(s);
	}
	s->status = VISITED;
	}

	void topoSort()
	{
		initialDFS();
		stack<Node*>DFSstack;
		bool is_sort = true;
		for (int i = 0; i < vertex.size(); i++)
		{
			if (vertex[i]->status == UNVISITED)
			{
				singleDFS(vertex[i], DFSstack, is_sort);
			}
		}
		if (!back_edges.empty())
		{
			cout << "Cycle(s) found in the graph. Topological sort failed." << endl;
			return;
		}
		while (!DFSstack.empty())
		{
			char name = DFSstack.top()->data;
			DFSstack.pop();
			cout << name << " ";
		}
	}
	
	
};



int main()
{
	ifstream graphFile("graph.txt", ios::in);
	
	int edgeNumber = 0;
	int nodeNumber = 0;
	char dat1, dat2 = NULL;
	stack<Node*>DFSstack;
	Graph graph;
	graphFile >> nodeNumber;
	for (int i = 0; i < nodeNumber; i++)
	{
		graphFile >> dat1;
		graph.vertex.push_back(new Node(dat1, 0));
	}
	graphFile >> edgeNumber;
	for (int j = 0; j < edgeNumber; j++)
	{
		graphFile >> dat1 >> dat2;
		graph.vertex[graph.posInVertex(dat1, graph.vertex, nodeNumber)]->nexts.
			push_back(graph.vertex[graph.posInVertex(dat2, graph.vertex, nodeNumber)]);
		graph.edge.push_back(new Edge(graph.vertex[graph.posInVertex(dat1, graph.vertex, nodeNumber)],
			graph.vertex[graph.posInVertex(dat2, graph.vertex, nodeNumber)]));
		
	}
	for (int i = 0; i < nodeNumber; i++)
	{
		for (int j = 0; j < graph.vertex[i]->nexts.size(); j++)
		{
			cout << graph.vertex[i]->data << "=>" << graph.vertex[i]->nexts[j]->data<<endl;
		}
	}
	graph.topoSort();

	return 0;
}
