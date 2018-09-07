#include "GraphNode.h"

GraphNode::GraphNode(int keyValue)
{
	key = keyValue;
	visited = false;
	distance = 0;

}

GraphNode::~GraphNode()
{
}

