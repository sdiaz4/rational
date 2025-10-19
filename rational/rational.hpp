// rational.hpp : Header file for your target.
#include <iostream>
#pragma once

class Rational {

public:

	static const int doubleBase  = 1000000;

	Rational();
	Rational(int numerator, int denominator);
	

	int den() const;
	int num() const;

	void den(int d);
	void num(int n);

	Rational operator+(const Rational& rationalB);
	Rational operator-(const Rational& rationalB);
	Rational operator*(const Rational& rationalB);
	Rational operator/(const Rational& rationalB);
	Rational operator +() const;
	Rational operator -() const;
	Rational& operator ++();
	Rational& operator --();
	Rational operator ++(int);
	Rational operator --(int);

	Rational& operator +=(Rational const& src);
    Rational& operator -=(Rational const& src);
    Rational& operator *=(Rational const& src);
    Rational& operator /=(Rational const& src);
    

	bool operator ==(Rational const& rhs) const;
	bool operator !=(Rational const& rhs) const;
	bool operator < (Rational const& rhs) const;
	bool operator >=(Rational const& rhs) const;
	bool operator > (Rational const& rhs) const;
	bool operator <=(Rational const& rhs) const;

private:

	int numerator;
	int denominator;

	int n = 0;

	void simplify(int& num, int& den);
	
	int GCF(int num, int den) const;

	bool denNotZero(int d) const;

	void denNotNeg(int& d, int& n);
	
	void numZero(int &n, int &d);

	int LCM(int num, int den);


};