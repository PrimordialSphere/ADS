#include"Graph.h"

Graph::Graph()
{
	numNodes = 0;
	nodes.clear();
}

Graph::Graph(int numberNodes)
{
	numNodes = numberNodes;
	for (int i = 0; i < numNodes; i++) {
		GraphNode * aktuelleNode = new GraphNode(i);
		nodes.push_back(aktuelleNode);
	}
}

void Graph::init(string fname , bool direc)
{
	directed = direc;
std::ifstream file;
		file.open(fname, ios_base::in);
		if (!file) {
			std::cout << "Cannot open file." << std::endl;
		}
		else {
			string line;
			getline(file, line);
			istringstream iss(line);
			//Erste Zeile Auslesen
			iss >> numNodes;
			//Alle Knoten anlegen
			for (int i = 0; i < numNodes; i++) {
				GraphNode * aktuelleNode = new GraphNode(i);
				nodes.push_back(aktuelleNode);
			}
			//Alle Kanten anlegen
			while (std::getline(file, line)) {
				istringstream edge(line);
				int from, to, weight; 
				edge >> from; 
				edge >> to;
				edge >> weight;

				GraphNode * currentNode = returnNodeWithKey(from);
				GraphNode * currentNeighbour = returnNodeWithKey(to);
				GraphNode::edge kante(currentNode, weight, currentNeighbour);
				currentNode->nodeEdges.push_back(kante);
				GraphNode::edge rückwegKante(currentNeighbour, weight, currentNode);
				currentNeighbour->nodeEdges.push_back(rückwegKante);

				
				

			}
			
		}
		file.close();
	
}

Graph::~Graph()
{
}

void Graph::resetVisited()
{
	if (nodes.empty()) { return; }
	for (int i = 0; i < numNodes; i++)
	{
		GraphNode * aktuellerKnoten = nodes[i];
		for (unsigned int j = 0; j < aktuellerKnoten->nodeEdges.size(); j++)
		{
			if (!aktuellerKnoten->nodeEdges.empty()) {
				GraphNode::edge aktuelleKante = aktuellerKnoten->nodeEdges[j];
				aktuelleKante.node->visited = false;
			}
		}
		
	}
}

void Graph::resetConsidered()
{
	if (nodes.empty()) { return; }
	for (int i = 0; i < numNodes; i++)
	{
		GraphNode * aktuellerKnoten = nodes[i];
		for (unsigned int j = 0; j < aktuellerKnoten->nodeEdges.size(); j++)
		{
			if (!aktuellerKnoten->nodeEdges.empty()) {
				GraphNode::edge aktuelleKante = aktuellerKnoten->nodeEdges[j];
				aktuelleKante.considered = false;
			}
		}

	}
}




bool Graph::breadthSearch()
{
	bool result = true;
	vector<bool> markiert; 
	markiert.resize(numNodes);
	deque<GraphNode*> queue;
	int key;
	queue.push_back(this->returnNodeWithKey(0));
	
	while (!(queue.empty()))
	{
		GraphNode * aktuellerKnoten = queue.front();
		queue.pop_front();
		key = aktuellerKnoten->key;
		markiert.at(key) = true;
		
		
			for (unsigned int j = 0; j < aktuellerKnoten->nodeEdges.size(); j++)
			{
				if (!aktuellerKnoten->nodeEdges.empty()) {
					GraphNode::edge aktuelleKante = aktuellerKnoten->nodeEdges[j];
					if (!aktuelleKante.node->visited)
					{
						aktuelleKante.node->visited = true;
						queue.push_back(this->returnNodeWithKey(aktuelleKante.node->key));
					}
					
					

				}
			}
	}
	for (auto it = markiert.begin(); it < markiert.end(); it++)
	{
		if (*it != true){
			result = false;
		}
	}
	return result;
}

bool Graph::depthSearch(int key)
{
	bool result = true;
	
	GraphNode * currentNode = returnNodeWithKey(key);
	currentNode->visited = true;
	for (int i = 0; i < currentNode->nodeEdges.size(); i++)
	{
		if (currentNode->nodeEdges[i].node->visited != true)
		{
			depthSearchRekursion(currentNode->nodeEdges[i].node);
		}
	}

	for (auto it = nodes.begin(); it < nodes.end(); it++)
	{
		GraphNode * currentNode = *it;
		if (currentNode->visited != true) {
			result = false;
		}
	}

	return result;
}

void Graph::depthSearchRekursion(GraphNode * node)
{
	node->visited = true;
	for (int i = 0; i < node->nodeEdges.size(); i++)
	{
		if (node->nodeEdges[i].node->visited != true)
		{
			depthSearchRekursion(node->nodeEdges[i].node);
		}
	}
}

double Graph::prim(int key)
{
	 int V = numNodes;
	 double result = 0;
	 //adjazentenmatrix dynamisch erstellen

	 double ** adjazentenMatrix;
	 adjazentenMatrix = new double*[V];
	for (int i = 0; i < V; i++)
	{
		adjazentenMatrix[i] = new double[V];
	}

	//Alle Werte auf Null setzen
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			adjazentenMatrix[i][j] = 0;
		}
	}
	
	//Die im Graphen vorhandenen Kanten in die adjazentenmatrix eintragen
	for (int i = 0; i < nodes.size(); i++)
	{
		GraphNode currentNode = *nodes[i];

		for (int j = 0; j < currentNode.nodeEdges.size(); j++)
		{
			adjazentenMatrix[i][currentNode.nodeEdges[j].node->key] = currentNode.nodeEdges[j].weight;
		}

	}


	for (int i = 0; i < V; i++)
	{
	

		for (int j = 0; j < V; j++)
		{
			cout << adjazentenMatrix[i][j] << " | ";
		}
		cout << endl;
	}
	cout << endl;
	
	signed int * aktuelleListeVorgänger = new signed int[V];
	int *  keys  = new int[V];
	bool * nodesStillToDo = new bool[V];

	for (int i = 0; i < V; i++)
	{
		keys[i] = INT_MAX;
		nodesStillToDo[i] = false;
	}


	keys[key] = 0;
	aktuelleListeVorgänger[key] = -1;

	
	for (int count = 0; count < V-1; count++)
	{
		int u = kleinsterKey(keys, nodesStillToDo);

		if (u < numNodes) {
			nodesStillToDo[u] = true;


			for (int v = 0; v < V; v++)
			{
				if (adjazentenMatrix[u][v] && nodesStillToDo[v] == false && adjazentenMatrix[u][v] < keys[v])
				{
					aktuelleListeVorgänger[v] = u;
					keys[v] = adjazentenMatrix[u][v];

				}
			}

		}
	}

	
	for (int i = 0; i < V; i++)
	{
		if (keys[i]!= INT_MAX) {
			result = result + keys[i];
		}
	}

	
	
	delete aktuelleListeVorgänger, keys, nodesStillToDo, adjazentenMatrix;
	return result; 
}

int Graph::kleinsterKey(int * keys, bool * nodesStillToDo)
{
	int min = INT_MAX;
	int min_index;

	for (int v = 0; v < numNodes; v++) {
		if (nodesStillToDo[v] == false && keys[v] < min) {
			min = keys[v];
			min_index = v;
		}
	}

	return min_index;
}

double Graph::kruskal()
{
	deque<struct GraphNode::edge  > kantenListe;
	GraphNode * aktuellerKnoten;
	
	

	for (int i = 0; i < nodes.size(); i++)
	{
		aktuellerKnoten = nodes[i];

		if (!aktuellerKnoten->nodeEdges.empty()) {
			for (unsigned int j = 0; j < aktuellerKnoten->nodeEdges.size(); j++)
			{
				GraphNode::edge aktuelleKante = aktuellerKnoten->nodeEdges[j];
				kantenListe.push_back(aktuelleKante);

			}
		}
	}

	sort(kantenListe.begin(), kantenListe.end(), compareByWeight);

	for (unsigned int i = 0; i < kantenListe.size(); i++)
	{
		cout << i << " " << kantenListe[i].from->key << " " << kantenListe[i].node->key << " " << kantenListe[i].weight << endl;
	}

	vector<teilGraph> teilGraphen;
	teilGraphen.resize(numNodes);


	for (int i = 0; i < numNodes; ++i)
	{
		teilGraphen[i].parent = i;
		teilGraphen[i].rank = 0;
	}


	double result = 0;
	int added = 0;
	
	
	
	for(int index = 0; index < kantenListe.size(); index++) {
		
		

			int x = find(teilGraphen, kantenListe[index].from->key);
			int y = find(teilGraphen, kantenListe[index].node->key);

			if (x != y)
			{
				result = result + kantenListe[index].weight;
				makeUnion(teilGraphen, x, y);
				added++;
			}
			
		
	}

	return result;
}

void Graph::makeUnion(vector<teilGraph> &teilGraphen, int x, int y)
{
	int xWurzel = find(teilGraphen, x);
	int yWurzel = find(teilGraphen, y);

	if (teilGraphen[xWurzel].rank < teilGraphen[yWurzel].rank) {
		teilGraphen[xWurzel].parent = yWurzel;
	}
	else if (teilGraphen[xWurzel].rank > teilGraphen[yWurzel].rank)
	{
		teilGraphen[yWurzel].parent = xWurzel;
	}
	else
	{
		teilGraphen[yWurzel].parent = xWurzel;
		teilGraphen[xWurzel].rank++;
	}
}

int Graph::find(vector<teilGraph> &teilGraphen, int i)
{
	if (teilGraphen[i].parent != i) {
		teilGraphen[i].parent = find(teilGraphen, teilGraphen[i].parent);
	}
	return teilGraphen[i].parent;

}

void Graph::print()
{
	if (nodes.empty()) { return; }
	for (int i = 0; i < numNodes; i++)
	{
		GraphNode * aktuellerKnoten = nodes[i];
		cout << aktuellerKnoten->key << " | ";
		for (unsigned int j = 0; j < aktuellerKnoten->nodeEdges.size(); j++)
		{
			if (!aktuellerKnoten->nodeEdges.empty()) {
				GraphNode::edge aktuelleKante = aktuellerKnoten->nodeEdges[j];
				cout << aktuelleKante.from->key  << " " <<  aktuelleKante.node->key << " " << aktuelleKante.weight << " | ";
			}
		}
		cout << endl;
	}
	
}

void Graph::clear()
{
	for (auto it = nodes.begin(); it != nodes.end(); ++it) {
		delete *it;
	}
	nodes.clear();
	numNodes = 0;
}

GraphNode * Graph::returnNodeWithKey(int key)
{
	for (int i = 0; i < numNodes; i++)
	{
		GraphNode * aktuellerKnoten = nodes[i];
		if (aktuellerKnoten->key == key)
		{
			return aktuellerKnoten;
		}
	}
	return nullptr;
}





