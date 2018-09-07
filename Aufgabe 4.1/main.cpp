#include"Graph.h"




void Menu()
{
	
	cout << "1- Graph einlesen" << endl;
	cout << "2- Tiefensuche" << endl;
	cout << "3- Breitensuche " << endl;
	cout << "4- Prim" << endl;
	cout << "5- Kruskal" << endl;
	cout << "6- Graph ausgeben" << endl;
	cout << "0- Programm beenden" << endl;
	cout << "?> ";
}

int main(void) {
	Graph * meinGraph = new Graph();
	vector<GraphNode*> results;
	int gerichtedLimitedOptions = 0;

	int choice = 99;
	

	while (choice != 0) {
		do
		{
			
				Menu();
				cin >> choice;

			

			
		} while (choice > 6 || choice < 0);

		if (choice == 1) {
			

			string fname;
			cout << "Name des .txt file? : ";
			cin >> fname;
			bool gerichtet = false;

		
			meinGraph->clear();
			meinGraph->init(fname, gerichtet);
			
		}
		else if (choice == 2) {
			int key;
			cout << endl;
			
			cout << "Key ? ";
			cin >> key;

			bool success = meinGraph->depthSearch(key);
			if (success)
			{
				cout << "Zusammenhaengend";
			}
			else
			{
				cout << "Nicht Zusammenhaengend";
			}


			meinGraph->resetVisited();
			cout << endl;
		}
		else if (choice == 3) {
			cout << endl;

			bool success = meinGraph->breadthSearch();
			meinGraph->resetVisited();
			if (success)
			{
				cout << "Zusammenhaengend" << endl;
			}
			else
			{
				cout << "Nicht Zusammenhaengend" << endl;
			}
			

			cout << endl;
		}
		else if (choice == 4) {
			int key;
			cout << endl;

			cout << "Key ? ";
			cin >> key;

			double result = meinGraph->prim(key);
			meinGraph->resetConsidered();
			cout << result;
			cout << endl;
		}
		else if (choice == 5) {
			cout << endl;
			double result = meinGraph->kruskal();
			cout << result;
			cout << endl;
		}
		else if (choice == 6) { 
			cout << endl; 
			meinGraph->print(); }
		else if (choice == 0) { break; }

	}

	system("PAUSE");
}