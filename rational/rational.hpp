// rational.hpp : Header file for your target.
#include <iostream>
#pragma once

class Rational {

public:

	Rational();
	Rational(int numerator, int denominator);
	

	int dem() const;
	int num() const;

	void dem(int d);
	void num(int n);

private:

	int numerator;
	int denominator;
	

};