#include "Tree.h"

Tree::Tree()
{
	anker = new TreeNode();
	NodeIDCounter = 0;
}

Tree::~Tree()
{
}

void Tree::add(int nodeID, string name, int alter, double einkommen, int plz)
{
	TreeNode * tmpAnker = anker;
	TreeNode * newEntry = new TreeNode(nodeID, name, alter, einkommen, plz);


	if (NodeIDCounter == 0)
	{
		anker = newEntry;
		cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
	}

	else
	{
		while (true)
		{
			if (newEntry->getNodePosID() < tmpAnker->getNodePosID())
			{
				if (tmpAnker->getLinks() == nullptr)
				{
					tmpAnker->setLinks(newEntry);
					cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
					break;
				}
				else
				{
					tmpAnker = tmpAnker->getLinks();
				}

			}
			else if (newEntry->getNodePosID() > tmpAnker->getNodePosID())
			{
				if (tmpAnker->getRechts() == nullptr)
				{
					tmpAnker->setRechts(newEntry);
					cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
					break;
				}
				else
				{
					tmpAnker = tmpAnker->getRechts();
				}
			}
		}
	}
}

void Tree::del(TreeNode * aktuellerKnotenPrev, TreeNode* aktuellerKnoten, int nodeID)
{
	TreeNode * tmpAnker = aktuellerKnoten;
	TreeNode * tmpAnkerPrev = aktuellerKnotenPrev;

	if (tmpAnker->getLinks() != nullptr)
	{
		del(tmpAnker, tmpAnker->getLinks(), nodeID);
	}
	if (tmpAnker->getRechts() != nullptr)
	{
		del(tmpAnker, tmpAnker->getRechts(), nodeID);
	}

	

	if (tmpAnker->getNodePosID() == nodeID)
	{
		// Fall 1 gesuchter Knoten == Anker
		if (tmpAnker == anker) {
			TreeNode * links;
			TreeNode * rechts;
			TreeNode * temp;
			cout << " 1 Fall " << endl;

			if (tmpAnker->getLinks() == nullptr && tmpAnker->getRechts() == nullptr)
			{
				
				delete tmpAnker;
				anker = nullptr;
				cout << "+ Datensatz wurde geloescht " << endl;
				return;
			}

			rechts = tmpAnker->getRechts();
			links = tmpAnker->getLinks();


			if (rechts->getLinks() == nullptr)
			{
				
				rechts->setLinks(links);
				delete tmpAnker;
				anker = rechts;
				cout << "+ Datensatz wurde geloescht " << endl;
				return;

			}
			if (rechts->getLinks() != nullptr)
			{
				temp = rechts;
				while (temp->getLinks() != nullptr)
				{
					temp = temp->getLinks();
				}
				temp->setLinks(links);
				delete tmpAnker;
				anker = rechts;
				cout << "+ Datensatz wurde geloescht " << endl;
				return;

			}

		}
		// 2 Fall Knoten hat keine Kinder
		else if (tmpAnker->getLinks() == nullptr && tmpAnker->getRechts() == nullptr)
		{
			cout << " 2 Fall " << endl;
			if (tmpAnkerPrev->getLinks() == tmpAnker) {
				tmpAnkerPrev->setLinks(nullptr);
				delete tmpAnker;
				cout << "+ Datensatz wurde geloescht " << endl;
				return;
			}
			if (tmpAnkerPrev->getRechts() == tmpAnker) {
				tmpAnkerPrev->setLinks(nullptr);
				delete tmpAnker;
				cout << "+ Datensatz wurde geloescht " << endl;
				return;
			}
			

		}

		// 3 Fall: nur ein Kind
		else if (tmpAnker->getLinks() == nullptr || tmpAnker->getRechts() == nullptr) {
			cout << " 3 Fall " << endl;

			if (tmpAnker->getLinks() == nullptr)
			{
				if (tmpAnkerPrev->getLinks() == tmpAnker)
				{
					tmpAnkerPrev->setLinks(tmpAnker->getRechts());
					delete tmpAnker;
					cout << "+ Datensatz wurde geloescht " << endl;
					return;
				}
				if (tmpAnkerPrev->getRechts() == tmpAnker)
				{
					tmpAnkerPrev->setRechts(tmpAnker->getRechts());
					delete tmpAnker;
					cout << "+ Datensatz wurde geloescht " << endl;
					return;
				}

			}
			if (tmpAnker->getRechts() == nullptr)
			{
				if (tmpAnkerPrev->getLinks() == tmpAnker)
				{
					tmpAnkerPrev->setLinks(tmpAnker->getLinks());
					delete tmpAnker;
					return;
				}
				if (tmpAnkerPrev->getRechts() == tmpAnker)
				{
					tmpAnkerPrev->setRechts(tmpAnker->getLinks());
					delete tmpAnker;
					cout << "+ Datensatz wurde geloescht " << endl;
					return;
				}
			}
		}
		// 4. Fall = Knoten hat zwei Kinder
		else if (tmpAnker->getLinks() != nullptr && tmpAnker->getRechts() != nullptr) {
			cout << " 4 Fall " << endl;
			cout << tmpAnkerPrev->getName() << endl;
			cout << tmpAnker->getName() << endl;
			TreeNode * temp;
			TreeNode * temp1 = tmpAnkerPrev;
			TreeNode * temp2;

			temp = tmpAnker->getRechts();

			while (temp->getLinks() != nullptr) {
				temp1 = temp;
				temp = temp->getLinks();
			}

			if (temp->getRechts() != nullptr) {
				 temp2 = temp->getRechts(); 
				 temp1->setRechts(temp2);
			}

			

			if (tmpAnkerPrev->getLinks() == tmpAnker) {  tmpAnkerPrev->setLinks(temp); }
			if (tmpAnkerPrev->getRechts() == tmpAnker) { tmpAnkerPrev->setRechts(temp); }

			if (tmpAnker->getLinks() != temp) {
				temp->setLinks(tmpAnker->getLinks());
			}
			if (tmpAnker->getRechts() != temp) {
				temp->setRechts(tmpAnker->getRechts());
			}


			delete tmpAnker;
			cout << "+ Datensatz wurde geloescht " << endl;
			return;
		}
	
	}
	else { return; }
	

}

void Tree::inkrementNodeIDCounter(void)
{
	NodeIDCounter++;
}

int Tree::getNodeIDCounter(void)
{
	return NodeIDCounter;
}



TreeNode * Tree::getAnker(void)
{
	return anker;
}


void Tree::print(TreeNode * key)
{
	TreeNode * tmpAnker = key;
	tmpAnker->printData();

	if (tmpAnker->getLinks() != nullptr)
	{
		print(tmpAnker->getLinks());
	}
	if (tmpAnker->getRechts() != nullptr)
	{
		print(tmpAnker->getRechts());
	}
	
	return;
}

void Tree::search(TreeNode* aktuellerKnoten, string key)
{
	TreeNode * tmpAnker = aktuellerKnoten;
	if (tmpAnker->getName() == key)
	{
		cout << "NodeID: " << tmpAnker->getNodeID() << ", Name : " << tmpAnker->getName() << ", Alter: " << tmpAnker->getAlter() << ", Einkommen: " << tmpAnker->getEinkommen() << ", PLZ: " << tmpAnker->getPLZ() << ", PosID: " << tmpAnker->getNodePosID() << endl;
		return;
	}

	if (tmpAnker->getLinks() != nullptr)
	{
		search(tmpAnker->getLinks(), key);
	}
	if (tmpAnker->getRechts() != nullptr)
	{
		search(tmpAnker->getRechts(), key);
	}

	
}
