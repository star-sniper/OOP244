

#include <iostream>
#include "Fraction.h"

using namespace std;
namespace sict
{
	Fraction::Fraction()
	{
		nume = 0;
		deno = 1;
	}
	Fraction::Fraction(const int num, const int den)
	{
		if (num > 0 && den > 0)
		{
			nume = num;
			deno = den;
			reduce();
		}
		else
			*this = Fraction();
	}
	int Fraction::max() const
	{
		int res = 0;
		if (nume > deno)
			res = nume;
		else
			res = deno;
		return res;
	}
	int Fraction::min() const
	{

		int res = 0;
		if (nume > deno)
			res = deno;
		else
			res = nume;
		return res;
	}

	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	// reduce simplifies the fraction by dividing the numerator and denominator by the greatest common divisor
	//
	void Fraction::reduce()
	{
		int gcd_res = gcd();
		nume = nume / gcd_res;
		deno = deno / gcd_res;
	}



	Fraction Fraction::operator +(const Fraction& f1) const
	{


		Fraction result;

		if (isEmpty() == false)
		{
			result.nume = nume*f1.deno + deno*f1.nume;
			result.deno = deno*f1.deno;
		}
		else
		{
			Fraction(result.nume, result.deno);
		}
		return result;

	}


	Fraction Fraction::operator *(const Fraction& f1) const
	{
		Fraction result;
		if (isEmpty() == false)
		{
			result.nume = nume*f1.nume;
			result.deno = deno*f1.deno;
		}
		else
			Fraction(result.nume, result.deno);

		return result;
	}

	bool Fraction::operator==(const Fraction& f1)
	{
		bool result;
		if (isEmpty() == false)
		{
			reduce();
			if (nume == f1.nume && deno == f1.deno)
				result = true;
			else
				result = false;
		}
		else
			result = false;

		return result;
	}
	bool Fraction::operator!=(const Fraction& f1)
	{
		bool result;
		if (isEmpty() == false)
		{
			reduce();
			if ((*this) == f1)
				result = false;
			else
				result = true;
		}
		else
			result = false;
		return result;
	}


	Fraction& Fraction::operator+=(const Fraction& f2) 
	{

		*this = *this + f2;
		reduce();
		return *this;
	}



	bool Fraction::isEmpty() const
	{
		bool result;
		if (nume == 0 && deno == 1)
			result = true;
		else
			result = false;

		return result;
	}


	void Fraction::display() const
	{
		if (isEmpty() == true)
			cout << "no fraction stored";
		else
		{
			if (nume > 0 && deno == 1)
				cout << nume;
			else
				cout << nume << "/" << deno;
		}


	}
}
