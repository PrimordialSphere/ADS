#ifndef _GRAPHNODE_H
#define _GRAPHNODE_H
#include <string>
#include <iostream>
#include <string>
#include<vector>
using namespace std;

class GraphNode
{
public:
	GraphNode(int keyValue);
	~GraphNode();

	struct edge {
		GraphNode * node; 
		double weight;
		bool considered;
		GraphNode * from;

		edge() {
			node = nullptr;
			weight = 0;
			considered = false;
			from = nullptr;
		}

		edge(GraphNode * n, double key, GraphNode * o) {
			node = o;
			weight = key; 
			considered = false;
			from = n;
		}
		edge(const edge &h) {
			node = h.node;
			weight = h.weight;
			considered = h.considered;
			from = h.from;
		}

	
	};

	

	vector<struct edge> nodeEdges;

	int key;
	bool visited;
	double distance;

private:
	
};


#endif
