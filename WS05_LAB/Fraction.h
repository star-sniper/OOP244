
#ifndef SICT_FRACTIO_H
#define SICT_FRACTION_H

namespace sict
{
	class Fraction
	{
	public:
		
		Fraction();
		Fraction(const int num,const int den);
		bool isEmpty() const;
		void display() const;
		Fraction operator +(const Fraction& f1) const;
	private:
		int nume, deno;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
		};
}

#endif // !SICT_FRACTIO_H
