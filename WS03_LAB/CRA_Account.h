

#ifndef SICT_CRA_H
#define SICT_CRA_H



namespace sict {

	const int MAX_NAME_LENGTH = 40;
	const int MIN_SIN = 100000000;
	const int MAX_SIN = 999999999;

	class CRA_Account
	{
	private:
		char FamilyName[MAX_NAME_LENGTH];
		char GivenName[MAX_NAME_LENGTH];
		int  Sin;
	public:

		void set(const char* familyName, const char* givenName, int sin);
		bool isValid() const;
		void display() const;
	};
}

#endif
