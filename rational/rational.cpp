// rational.cpp : Source file for your target.
//

#include "rational.hpp"


int Rational::getDenominator() const {
	return denominator;
}
int Rational::getNumerator() const {
	return numerator;
}

void Rational::setDenominator(int d) {
	if (d != 0) {
		denominator = d;
	}
}
void Rational::setNumerator(int n) {

}

