
#include <iostream>
#include <cstring>
#include <cmath>
#include "CRA_Account.h"
using namespace std;
namespace sict
{
	void CRA_Account::set(int year, double balance)
	{
		if (isValid() == true)
		{
			if (m_years < MAX_YRS)
			{
				m_year[m_years] = year;
				m_balance[m_years] = balance;
				m_years++;
			}
		}
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		Sin = sin;
		if (isValid() == true)
		{
			strncpy(FamilyName, familyName, MAX_NAME_LENGTH);
			strncpy(GivenName, givenName, MAX_NAME_LENGTH);
			m_years = 0;
		}
		else
		{
			familyName = NULL;
			givenName = NULL;
		}
	}

	
	bool CRA_Account::isValid() const
	{
		
		bool result;


		if (Sin >= MIN_SIN && Sin <= MAX_SIN)
		{

			int temp_sin[9] = { 0 };//temporary array to store sin
			int i = 0;
			int final_sum = 0;//to store the final sum
			int size = sizeof(temp_sin) / sizeof(*temp_sin);//calculating the size of array
			int temp = Sin;//storing the SIN in a temporary variable so that the actual remains unchanged

			//extracting each digit of sin into the array and then to perform the further operations
			while (temp > 0)
			{

				int last_dig = temp % 10;
				temp_sin[i] = last_dig;
				temp = temp / 10;
				i++;
			}

			//since we got the sin in reverse order while extraction now,
			//getting the sin in the original order
			for (i = 0; i < size / 2; i++)
			{
				int c = temp_sin[i];
				temp_sin[i] = temp_sin[size - i - 1];
				temp_sin[size - i - 1] = c;
			}


			//modifying the array according to given conditions
			for (i = 1; i < size; i += 2)
				temp_sin[i] = temp_sin[i] * 2;

			//extracting the check digit i.e. the last number
			int check_dig = temp_sin[size - 1];


			//getting the sum for each element in the array and storing in final_sum
			for (i = 0; i < size-1; i++)
			{
				final_sum = final_sum + sumdigits(temp_sin[i]);
			}

			//adding the check digit to final sum calculated above
			final_sum +=check_dig;

			//condition for valid SIN
			if (final_sum % 10 == 0)
				result = true;
			else
				result = false;
		}	
			else
				result = false;

		return result;
	}

	int CRA_Account::sumdigits(int x) const
	{
		
		int total = 0;
		total = x;//if x < 10 then return the number as it is
		if (x > 9)
		{
			int sum = 0;
			//calculation the sum of those digit which are greater than 9 
			//by extracting each of them
			while (total > 0)
			{
				int rem = total % 10;
				sum += rem;
				total /= 10;
			}
			total = sum;
		}
		return total;
	}

	void CRA_Account::display() const
	{
		if (isValid() == true)
		{

			cout << "Family Name: " << FamilyName << endl;

			cout << "Given Name : " << GivenName << endl;

			cout << "CRA Account: " << Sin << endl;

			cout.setf(ios::fixed);
			cout.precision(2);

			for (int i = 0; i < MAX_YRS; i++) 
			{
				cout << "Year (" << m_year[i] << ") ";
				if (m_balance[i] > 2)
					cout << "balance owing: " << m_balance[i] << endl;
				else if (m_balance[i] < -2)
					cout << "refund due: " << fabs(m_balance[i]) << endl;
				else
					cout << "No balance owing or refund due!" << endl;
			}
		}
		else
			cout << "Account object is empty!" << endl;
	}
}
