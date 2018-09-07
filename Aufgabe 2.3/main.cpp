#include "Tree.h"
#include <fstream>

int main (void){
	Tree * meinTree = new Tree();
	int input;
	std::string input2;
	int input3;
	double input4;
	int input5;
	
	while (true) {
		cout << std::string(34, '=') << endl;
		cout << "1) Datensatz einfuegen, maneull" << endl;
		cout << "2) Datensatz einfuegen, CSV Datei" << endl;
		cout << "3) Datensatz loeschen" << endl;
		cout << "4) Suchen" << endl;
		cout << "5) Datenstruktur anzeigen" << endl;
		cout << std::string(34, '=') << endl;
		

		cin >> input;
		while (cin.fail()) {
			cout << "Fehler! Bitte geben Sie eine Zahl zwischen 1 und 5 ein. " << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cin >> input;
		}


		if (input == 1) {
			

			cout << "+ Bitte geben Sie den Datensatz ein" << endl;
			cout << "Name ?>";
			cin >> input2;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie einen Namen ein. " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				
				cin >> input2;
			}
			cout << "Alter ?> ";
			cin >> input3;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie eine ganze Zahl ein" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> input3;
			}
			cout << "Einkommen ?> ";
			cin >> input4;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie eine double Zahl ein " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> input4;
			}
			cout << "PLZ ?> ";
			cin >> input5;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie eine ganze Zahl ein. " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> input5;
			}

			
			meinTree->add(meinTree->getNodeIDCounter(), input2, input3, input4, input5);
			meinTree->inkrementNodeIDCounter();

			
		}
		else if (input == 2) {
			
			ifstream csvread;
			csvread.open("ExportZielanalyse.csv", ios::in);
			if (csvread)
			{
				string name, alter, einkommen, plz;
				while (!csvread.eof())
				{
					
					getline(csvread, name, ';');
						getline(csvread, alter, ';');
						getline(csvread, einkommen, ';');
						getline(csvread, plz, '\n');
					
				
					

					input2 = name;
					input3 = stoi(alter);
					input4 = stod(einkommen);
					input5 = stoi(plz);
				 meinTree->add(meinTree->getNodeIDCounter(), input2, input3, input4, input5); meinTree->inkrementNodeIDCounter(); 
					
				}
				csvread.close();
		}
			else
			{
				cout << "Fehler beim Lesen!" << endl;
			
			}

		}
		else if (input == 3) {
			cout << "Bitte geben Sie den zu loeschenden Datensatz an" << endl;
			cout << "PosID ?> ";
			cin >> input3;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie eine ganze Zahl ein " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> input3;
			}

			meinTree->del(nullptr, meinTree->getAnker(), input3);
		}
		else if (input == 4) {
			
			cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl;
			cout << "Name ?> ";
			cin >> input2;
			while (cin.fail()) {
				cout << "Fehler! Bitte geben Sie einen Namen ein " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> input2;
			}
			cout << "+ Fundstellen :" << endl;

			meinTree->search(meinTree->getAnker(), input2);

		}
		else if (input == 5) {
			cout << "ID  | Name          | Alter | Einkommen      | PLZ | Pos" << endl;
			cout << "----+---------------+-------+----------------+-----+-------" << endl;
			meinTree->print(meinTree->getAnker());

		}
		else if (input == 6) { break;
		}

		cin.clear();
	}

}