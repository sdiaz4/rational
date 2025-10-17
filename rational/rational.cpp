// rational.cpp : Source file for your target.
//
#include "rational.hpp"
#include <iostream>
#include <string>

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num, int den) {

	numerator = num;
	if (denominator == 0) {
		throw std::domain_error("Denominator can not be zero");
	}
	else {
		denominator = den;
	}
	
}


int Rational::dem() const {
	return denominator;
}
int Rational::num() const {
	return numerator;
}

void Rational::dem(int d) {
	if (d != 0) {
		denominator = d;
	}
	else {
		std::cout << "Denominator can not be zero";
	}
		
}
void Rational::num(int n) {
	numerator = n;
}

