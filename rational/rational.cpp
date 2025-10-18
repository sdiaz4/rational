// rational.cpp : Source file for your target.
//
#include "rational.hpp"
#include <iostream>
#include <string>

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int num, int den) {

	if (den < 0) {
		den *= -1;
		num *= -1;
	}

	if (den == 0) {
		throw std::domain_error("Denominator can not be zero");
	}
	else {
		denominator = den;
	}

	if (num == 0) {
		numerator = num;
		denominator = 1;
	}
	else {
		numerator = num;
	}
	
	
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
	else if (d < 0) {
		d *= -1;
		denominator = d;
		numerator *= -1;
		
	}
	else {
		denominator = d;
	}
		
}
void Rational::num(int n) {
	if (n == 0) {
		numerator = n;
		denominator = 1;
	}
	else {
		numerator = n;
	}
	
}

