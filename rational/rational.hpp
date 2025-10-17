// rational.h : Header file for your target.

#pragma once

class Rational {

public:
	
	Rational() {}
	Rational(int numerator = 0, int denominator = 1) {}

	int getDenominator() const;
	int getNumerator() const;

	void setDenominator(int d);

	void setNumerator(int n);

private:

	int denominator;
	int numerator;

};