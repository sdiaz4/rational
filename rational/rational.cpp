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

bool Rational::denNotZero(int d) const {
	if (d == 0) {
		throw std::domain_error("Denominator can not be zero");
	}
	else return true;
}

void Rational::simplify(int &num, int &den) {
	numZero(num, den);
	denNotNeg(num, den);

	int gcf = Rational::GCF(num, den);
	num /= gcf;
	den /= gcf;
}

int Rational::GCF(int num, int den) const {
		denNotZero(den);

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
	denNotZero(den);

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

Rational::Rational(int num, int den) {

	if (denNotZero(den)) {
		numerator = num;
		denominator = den;
		simplify(numerator, denominator);
	}

	
}


int Rational::den() const {
	return denominator;
}
int Rational::num() const {
	return numerator;
}

void Rational::den(int d) {
	if (denNotZero(d))
	{
		denominator = d;
		simplify(numerator, denominator);
	}	
}
void Rational::num(int n) {
	numerator = n;
	simplify(numerator, denominator);
}

Rational Rational::operator+(const Rational& rationalB) {
	int lcm = LCM(denominator, rationalB.den());
	 
	int multipleA = lcm / denominator;
	int multipleB = lcm / rationalB.den();

	int den = lcm;
	int num = (numerator * multipleA) + (rationalB.num() * multipleB);
	
	return Rational (num, den);
}
//Rational operator-(const Rational& rationalB);
//Rational operator*(const Rational& rationalB);
//Rational operator/(const Rational& rationalB);

