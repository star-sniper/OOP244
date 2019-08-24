
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;
namespace sict
{
	Passenger::Passenger()
	{
		p_name[0] = '\0';
		dest[0] = '\0';
	}


	Passenger::Passenger(const char* name,const char* des)
	{

		if (name != nullptr && name[0] != '\0' && des != nullptr && des[0] != '\0')
		{
			strncpy(p_name, name,32);
			strncpy(dest, des,32);

		}
		else
		{
			*this = Passenger();
		}
	}
	bool Passenger::isEmpty() const
	{
		bool result;
		if (p_name[0] == '\0' && dest[0] == '\0')
			result = true;
		else
			result = false;

		return result;
	}

	void Passenger::display() const
	{
		cout << p_name << " - " << dest << endl;
	}
}
