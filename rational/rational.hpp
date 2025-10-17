#pragma once


class Rational {

public:
	Rational();
	Rational(int numerator, int denominator);

	int getDenominator() const;
	int getNumerator() const;

	void setDenominator(int d);
	void setNumerator(int n);


private:
	int denominator;
	int numerator;



};