
#include <iostream>
#include "Kingdom.h"

using namespace std;


// TODO: the sict namespace

namespace sict {

	// TODO:definition for display(...) 

	void display(const Kingdom& name)
	{
		cout << name.m_name << ", " << "population " << name.m_population << endl;
	}

	//overload display() funtion
	void display(const Kingdom* kingdom, int size) {
		int totalpop = 0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". ";
			display(kingdom[i]);
			totalpop += kingdom[i].m_population;
		}

		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalpop << endl;
		cout << "------------------------------" << endl;

	}
}
