

#ifndef SICT_CRA_H
#define SICT_CRA_H


namespace sict {

	const int MAX_NAME_LENGTH = 40;
	const int MIN_SIN = 100000000;
	const int MAX_SIN = 999999999;
	const int MAX_YRS = 4;

	class CRA_Account
	{
	private:
		char FamilyName[MAX_NAME_LENGTH];
		char GivenName[MAX_NAME_LENGTH];
		int  Sin;
		int m_year[MAX_YRS];
		double m_balance[MAX_YRS];
		int m_years;
	public:

		void set(const char* familyName, const char* givenName, int sin);
		bool isValid() const;
		int sumdigits(int x) const;
		void display() const;
		void set(int year, double balance);//function to add digits
	};
}

#endif
