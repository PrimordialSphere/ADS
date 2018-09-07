#ifndef _TREENODE_H
#define _TREENODE_H
#include <string>
#include <iostream>
using namespace std;

class TreeNode
{
	/*
	Die Klasse stellt den Knoten eines einfachen Binären Baums dar.
	*/
private:
	int NodePosID;
	int NodeID;
	std::string Name;
	int Alter;
	double Einkommen; 
	int PLZ;
	TreeNode * links;
	TreeNode * rechts;


public:
	TreeNode();
	TreeNode(int nodeID, string name, int alter, double einkommen, int plz);
	~TreeNode();
	std::string getName(void);
	int getNodePosID(void);
	int getNodeID(void);
	int getAlter(void);
	double getEinkommen(void);
	int getPLZ(void);
	TreeNode * getRechts(void);
	TreeNode * getLinks(void);
	void setNodeID(int key);
	void setName(std::string key);
	void setAlter(int key);
	void setEinkommen(double key);
	void setPLZ(int key);
	void printData(void);
	void setRechts(TreeNode * key);
	void setLinks(TreeNode * key);
};

#endif