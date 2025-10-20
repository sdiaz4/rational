// rational.cpp : Source file for your target.
//
#include "rational.hpp"
#include <iostream>
#include <string>

void Rational::numZero(int &n, int &d) {
	if (n == 0) {
		d = 1;
	}
}
void Rational::denNotNeg(int &n, int &d) {
	if (d < 0) {
		d *= -1;
		n *= -1;
	}
}

void Rational::simplify(int &num, int &den) {
	numZero(num, den);
	denNotNeg(num, den);

	int gcf = Rational::GCF(num, den);
	if (gcf != 0) {
		num /= gcf;
		den /= gcf;
	}
	
}
int Rational::GCF(int num, int den) const {
	if (den == 0)
	{
		throw std::domain_error("Denominator can not be zero");
	}

		if (num < 0) {
			num *= -1;
		}
		if (den < 0) {
			den *= -1;
		}
		
		if (num % den == 0) {
			return den;
		}
		else
			return GCF(den, num % den);
		
		
}
int Rational::LCM(int num, int den) {
	if (den == 0) {
		throw std::domain_error("Denominator can not be zero");
	}

	if (num < 0) {
		num *= -1;
	}
	if (den < 0) {
		den *= -1;
	}

	int LCM = num / GCF(num, den) * den;
	return LCM;
}

Rational::Rational() : numerator(0), denominator(1) {}
Rational::Rational(int n) : numerator(n), denominator(1) {}
Rational::Rational(double d) {
	numerator = (int)(d * doubleBase);
	denominator = doubleBase;

	simplify(numerator, denominator);

}
Rational::operator int() const {
	return numerator / denominator;
}
Rational::operator double() const {
	return static_cast<double>(numerator) / denominator;
}
Rational::Rational(int num, int den) {

	if (den == 0) {
		throw std::domain_error("Denominator can not be zero");
	}
	numerator = num;
	denominator = den;
	simplify(numerator, denominator);
	

	
}


int Rational::den() const {
	return denominator;
}
int Rational::num() const {
	return numerator;
}

void Rational::den(int d) {
	if (d == 0) {
		throw std::domain_error("Denominator can not be zero");
	}
	
	denominator = d;
	simplify(numerator, denominator);
		
}
void Rational::num(int n) {
	numerator = n;
	simplify(numerator, denominator);
}

//MATHOPS
Rational Rational::operator+(const Rational& rationalB) {
	int lcm = LCM(denominator, rationalB.den());
	 
	int multipleA = lcm / denominator;
	int multipleB = lcm / rationalB.den();

	int den = lcm;
	int num = (numerator * multipleA) + (rationalB.num() * multipleB);
	
	return Rational (num, den);
}
Rational Rational::operator-(const Rational& rationalB) {
	int lcm = LCM(denominator, rationalB.den());

	int multipleA = lcm / denominator;
	int multipleB = lcm / rationalB.den();

	int den = lcm;
	int num = (numerator * multipleA) - (rationalB.num() * multipleB);

	return Rational(num, den);
}
Rational Rational::operator*(const Rational& rationalB) {
	int num = numerator * rationalB.num();
	int den = denominator * rationalB.den();

	return Rational(num, den);
}
Rational Rational::operator/(const Rational& rationalB) {
	int num = numerator * rationalB.den();
	int den = denominator * rationalB.num();

	return Rational(num, den);
}
Rational Rational::operator +() const {
	return *this;
}
Rational Rational::operator -() const {
	return Rational(-numerator, denominator);
}
//Prefix
Rational& Rational::operator ++() {
	numerator += denominator;
	simplify(numerator, denominator);
	return *this;
}
Rational& Rational::operator --() {
	numerator -= denominator;
	simplify(numerator, denominator);
	return *this;
}
//Postfix
Rational Rational::operator ++(int) {
	Rational i = *this;
	++(*this);
	return i;
}
Rational Rational::operator --(int) {
	Rational i = *this;
	--(*this);
	return i;
}

//MATHASSIGNMENTOPS
Rational& Rational::operator +=(Rational const& src) {
	int lcm = LCM(denominator, src.den());

	int multipleA = lcm / denominator;
	int multipleB = lcm / src.den();

	denominator = lcm;
	numerator = (numerator * multipleA) + (src.num() * multipleB);

	simplify(numerator, denominator);

	return *this;
}
Rational& Rational::operator -=(Rational const& src) {
	int lcm = LCM(denominator, src.den());

	int multipleA = lcm / denominator;
	int multipleB = lcm / src.den();

	denominator = lcm;
	numerator = (numerator * multipleA) - (src.num() * multipleB);

	simplify(numerator, denominator);

	return *this;
}
Rational& Rational::operator *=(Rational const& src) {
	numerator = numerator * src.num();
	denominator = denominator * src.den();

	simplify(numerator, denominator);

	return *this;
}
Rational& Rational::operator /=(Rational const& src) {
	numerator = numerator * src.den();
	denominator = denominator * src.num();

	simplify(numerator, denominator);

	return *this;
}

//COMPAREOPS
bool Rational::operator ==(Rational const& rhs) const {
	return ((denominator == rhs.den()) && (numerator == rhs.num()));
}
bool Rational::operator !=(Rational const& rhs) const {
	return ((denominator != rhs.den()) || (numerator != rhs.num()));
}
bool Rational::operator < (Rational const& rhs) const {
	return (numerator * rhs.den() < denominator * rhs.num());
}
bool Rational::operator >=(Rational const& rhs) const {
	return (numerator * rhs.den() >= denominator * rhs.num());
}
bool Rational::operator > (Rational const& rhs) const {
	return (numerator * rhs.den() > denominator * rhs.num());
}
bool Rational::operator <=(Rational const& rhs) const {
	return (numerator * rhs.den() <= denominator * rhs.num());
}

std::ostream& operator <<(std::ostream& out, Rational const& Rational) {
	out << Rational.num() << "/" << Rational.den();
	return out;
}
std::istream& operator >>(std::istream& in, Rational& Rational) {
	in >> Rational.numerator >> Rational.denominator;
	return in;
}

inline 
bool operator==(Rational const& lhs, int const& rhs) {
	return (lhs == rhs);
}
inline
bool operator==(Rational const& lhs, double const& rhs) {
	return (lhs == rhs);
}
inline
bool operator!=(Rational const& lhs, int const& rhs) {
	return (lhs != rhs);
}
inline
bool operator!=(Rational const& lhs, double const& rhs) {
	return (lhs != rhs);
}
inline
bool operator>(Rational const& lhs, int const& rhs) {
	return (lhs > rhs);
}
bool operator>(Rational const& lhs, double const& rhs) {
	return (lhs > rhs);
}
bool operator<(Rational const& lhs, int const& rhs) {
	return (lhs < rhs);
}
bool operator<(Rational const& lhs, double const& rhs) {
	return (lhs < rhs);
}
bool operator<=(Rational const& lhs, int const& rhs) {
	return (lhs <= rhs);
}
bool operator<=(Rational const& lhs, double const& rhs) {
	return (lhs <= rhs);
}
bool operator>=(Rational const& lhs, int const& rhs) {
	return (lhs >= rhs);
}
bool operator>=(Rational const& lhs, double const& rhs) {
	return (lhs >= rhs);
}


