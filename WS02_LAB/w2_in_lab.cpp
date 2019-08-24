
#include <iostream>
#include "Kingdom.h"
using namespace std;
using namespace sict;

void read(Kingdom&);
int main() {
	int count = 0; // the number of kingdoms in the array
	Kingdom* pKingdom = nullptr;			   // TODO: declare the pKingdom pointer here (don't forget to initialize it)
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();
	if (count < 1) return 1;
	pKingdom = new Kingdom[count];
	// TODO: allocate dynamic memory here for the pKingdom pointer
	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);// TODO: add code to accept user input for Kingdom i
	}
	cout << "==========" << endl << endl;
	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The first kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(&pKingdom[0]);
	cout << "------------------------------" << endl << endl;
	delete[] pKingdom;// TODO: deallocate the dynamic memory here
	pKingdom = nullptr;
	return 0;
}
// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {
	cout << "Enter the name of the kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
