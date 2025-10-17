#include "rational.hpp"
#include <gtest/gtest.h>

TEST(DefaultCtor, rightValues) {
	Rational d;

	EXPECT_EQ(d.getDenominator(), 1);
	EXPECT_EQ(d.getNumerator(), 0);

}

/*
TEST(ValueCtor, rightValues) {

}

TEST(Setters, rightValues) {

}

TEST(MathOps, rightValues) {

}

TEST(MathAssignOps, rightValues) {

}

TEST(CompareOp, rightValues) {

}

TEST(ConvertOps, rightValues) {

}

TEST(IoOps, rightValues) {

}
*/
