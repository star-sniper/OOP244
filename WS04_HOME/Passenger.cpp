

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
		d_year = d_month = d_day = 0;
	}


	Passenger::Passenger(const char *name,const char *des,int year,int month,int day)
	{

		if (name != nullptr && name[0] != '\0' && des != nullptr && des[0] != '\0' && year>=2017 && year <=2020 && month>=1 && month<=12 && day>=1 && day<=31)
		{
			strcpy(p_name, name);
			strcpy(dest, des);
			d_day = day;
			d_year = year;
			d_month = month;
		}
		else
		{
			*this = Passenger();
		}
	}
	Passenger::Passenger(const char *name, const char *des) 
	{
		
		//validation
		if (name != nullptr && name[0] != '\0' && des != nullptr && des[0] != '\0') {
			strcpy(p_name, name);
			strcpy(dest, des);
			d_year = 2017;
			d_month = 7;
			d_day = 1;
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
		cout << p_name << " - " << dest << " on " << d_year;
		if (d_month <= 9 || d_day <= 9)
			cout << "/0" << d_month << "/";
		else
			cout << "/" << d_month << "/" ;
		cout << d_day <<endl;
	}
	const char* Passenger::name() const
	{
		return p_name;
	}
	bool Passenger::canTravelWith(const Passenger& p_pass) const
	{
		bool result;
		if (d_year == p_pass.d_year &&	d_month == p_pass.d_month && d_day == p_pass.d_day && strcmp(dest, p_pass.dest) == 0) 
		
			result = true;
		
		else 
			result = false;
		
		return result;
	}
}
