// rational.hpp : Header file for your target.
#include <iostream>
#pragma once

class Rational {

public:

	Rational();
	Rational(int numerator, int denominator);
	

	int den() const;
	int num() const;

	void den(int d);
	void num(int n);

	Rational operator+(const Rational& a);

	Rational operator==(const Rational& a);

private:

	int numerator;
	int denominator;

	int n = 0;

	void simplify(int& num, int& den);
	
	int GCF(int num, int den) const;

	bool denNotZero(int d) const;

	void denNotNeg(int& d, int& n);
	
	void numZero(int &n, int &d);
};