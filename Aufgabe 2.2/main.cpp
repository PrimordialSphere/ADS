#include <iostream>
#include <string>
#include "ringpuffer.h"
using namespace std;



int main(void)
{
	RingPuffer * meinRingpuffer = new RingPuffer;
	std::string input;
	std::string input2;
	std::string input3;
	std::string input4;
	while (true) {
		cout << std::string(34, '=') << endl;
		cout << "1) Backup einfuegen" << endl;
		cout << "2) Backup suchen" << endl;
		cout << "3) Alle Backups ausgeben" << endl;
		cout << std::string(34, '=') << endl;
		getline(cin, input);
		if (input == "1") {
			cout << "+Neuen Datensatz einfuegen" << endl;
			cout << "Beschreibung ?>";
			getline(cin, input2);
			cout << "Daten ?>";
			getline(cin, input3);
			cout << endl;
			if (meinRingpuffer->addNode(input2, input3)) {
				cout << "+Ihr Datensatz wuede hinzugefuegt." << endl;
			}
			else
			{
				cout << "+Fehler: Ihr Datensatz konnte nicht hinzugefuegt werden";
			}
		}
		else if (input == "2") {
			cout << "+ Nach welchen Daten soll gesucht werden?" << endl;
			cout << "?> ";
			getline(cin, input4);
			meinRingpuffer->search(input4);
		}
		else if (input == "3") {
			meinRingpuffer->outputRingpuffer();
		}
		else if (input == "quit") { break; }

	}


}