#include "TreeNode.h"



TreeNode::TreeNode(int nodeID, string name, int alter, double einkommen, int plz)
{
	NodePosID = alter + plz + einkommen;
	NodeID = nodeID;
	Name = name;
	Alter = alter;
	Einkommen = einkommen;
	PLZ = plz;
	rechts = nullptr;
	links = nullptr;
	
}

TreeNode::TreeNode()
{
	links = nullptr;
	rechts = nullptr;
	NodeID = 0;
}

TreeNode::~TreeNode()
{

}

string TreeNode::getName(void)
{
	return Name;
}

int TreeNode::getNodePosID(void)
{
	return NodePosID;
}

int TreeNode::getNodeID(void)
{
	return NodeID;
}

int TreeNode::getAlter(void)
{
	return Alter;
}

double TreeNode::getEinkommen(void)
{
	return Einkommen;
}

int TreeNode::getPLZ(void)
{
	return PLZ;
}

TreeNode * TreeNode::getRechts(void)
{
	return rechts;
}

TreeNode * TreeNode::getLinks(void)
{
	return links;
}

void TreeNode::setNodeID(int key)
{
	NodeID = key;
}

void TreeNode::setName(string key)
{
	Name = key;
}

void TreeNode::setAlter(int key)
{
	Alter = key;
}

void TreeNode::setEinkommen(double key)
{
	Einkommen = key;
}

void TreeNode::setPLZ(int key)
{
	PLZ = key;
}

void TreeNode::printData(void)
{
	cout << NodeID << "   |      " << Name << "|    " << Alter << " |          " << Einkommen << "|  " << PLZ << " |" << NodePosID << endl;
}

void TreeNode::setRechts(TreeNode * key)
{
	rechts = key;
}

void TreeNode::setLinks(TreeNode * key)
{
	links = key;
}
