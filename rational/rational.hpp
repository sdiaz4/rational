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

private:

	int numerator;
	int denominator;
	

};