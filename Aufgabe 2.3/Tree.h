#ifndef _TREE_H
#define _TREE_H
#include "TreeNode.h"
#include <string>
#include <iostream>
using namespace std;

class Tree
{
	/*
	Ein einfach Binärer Baum bestehend aus Tree Nodes. 
	*/
private:
	TreeNode * anker;			// Zeiger auf Wurzel
	int NodeIDCounter;			// Counter für die IDs der Blätter
	
public:
	Tree();
	~Tree();
	void add(int nodeID, string name, int alter, double einkommen, int plz);
	void del(TreeNode * aktuellerKnotenPrev, TreeNode* aktuellerKnoten, int nodeID);
	void inkrementNodeIDCounter(void);
	int getNodeIDCounter(void);
	
	TreeNode * getAnker(void);
	void print(TreeNode * key);
	void search(TreeNode* aktuellerKnoten, string key);
};

#endif