


#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H

namespace sict {

	class Passenger
	{
	public:
		char p_name[32];
		char dest[32];
		Passenger();
		Passenger(const char* name,const char* des);
		bool isEmpty() const;
		void display() const;
	};
}
#endif
