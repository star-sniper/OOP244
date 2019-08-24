
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {

	class Passenger
	{
	public:
		int d_year;
		int d_month;
		int d_day;
		char p_name[32];
		char dest[32];
		Passenger();
		Passenger(const char* name,const char* des,int year,int month,int day);
		Passenger(const char *name, const char *dest);
		bool isEmpty() const;
		void display() const;
		const char* name() const;
		bool canTravelWith(const Passenger&) const;
	};
}
#endif
