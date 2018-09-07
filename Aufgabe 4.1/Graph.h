#ifndef _GRAPH_H
#define _GRAPH_H

#include <string>
#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<set>
#include<algorithm>
#include"GraphNode.h"
using namespace std;


class Graph
{
public:
	Graph();
	Graph(int numberNodes);
	void init(string fname, bool direc);
	~Graph();

	struct teilGraph {
		int parent;
		int rank;
	};

	void resetVisited();
	void resetConsidered();

	int numNodes;
	bool weighted;
	bool directed;
	vector<GraphNode*> nodes;

	bool breadthSearch();
	bool depthSearch(int key);
	void depthSearchRekursion( GraphNode * node);

	double prim(int key);
	int kleinsterKey(int *  keys, bool * nodesStillToDo);



	double kruskal();
	int find(vector<teilGraph> &teilGraphen, int i);
	void makeUnion(vector<teilGraph> &teilGraphen, int x, int y);
	

	void print();
	void clear();

	GraphNode * returnNodeWithKey(int key);

	static bool compareByWeight(GraphNode::edge a, GraphNode::edge b)
	{
		return a.weight < b.weight;
	}
	

private:

	

};







#endif