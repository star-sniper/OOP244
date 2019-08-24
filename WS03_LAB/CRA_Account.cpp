
#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;
namespace sict
{

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		Sin = sin;
		if (isValid() == true)
		{
			strncpy(FamilyName, familyName, MAX_NAME_LENGTH);
			strncpy(GivenName, givenName, MAX_NAME_LENGTH);
			Sin = sin;
		}
		else
		{
			familyName = NULL;
			givenName = NULL;
			Sin = 0;
		}
	}

	bool CRA_Account::isValid() const
	{
		bool result;
		if (Sin >= MIN_SIN && Sin <= MAX_SIN)
			result = true;
		else
			result = false;
		return result;
	}

	void CRA_Account::display() const
	{
		if (isValid() == true)
		{

			cout << "Family Name: " << FamilyName << endl;

			cout << "Given Name : " << GivenName << endl;

			cout << "CRA Account: " << Sin << endl;
		}
		else
			cout << "Account object is empty!" << endl;
	}
}
