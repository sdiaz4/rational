#include "rational.hpp"
#include <gtest/gtest.h>

TEST(DefaultCtor, rightValues) {
	Rational d;

	EXPECT_EQ(d.den(), 1);
	EXPECT_EQ(d.num(), 0);

}


TEST(ValueCtor, rightValues) {

	Rational d(1, 3);
	
	EXPECT_EQ(d.num(), 1);
	EXPECT_EQ(d.den(), 3);
	
}

TEST(ValueCtor, Error) {

	EXPECT_ANY_THROW(Rational d(1, 0));

}

TEST(ValueCtor, ZeroNum) {

	Rational d{ 1, -3 };

	EXPECT_EQ(d.num(), -1);
	EXPECT_EQ(d.den(), 3);


}

TEST(ValueCtor, DenOne) {

	Rational d{ 0, 4 };

	EXPECT_EQ(d.den(), 1);
	EXPECT_EQ(d.num(), 0);

}

TEST(ValueCtor, Simplify) {

	Rational d{ 30, 60 };

	EXPECT_EQ(d.den(), 2);
	EXPECT_EQ(d.num(), 1);

}


TEST(Setters, rightValues) {
	Rational d;
	d.num(4);
	d.den(2);

	EXPECT_EQ(d.den(), 1);
	EXPECT_EQ(d.num(), 2);

	
}

TEST(Setters, ChecksZero) {
	Rational d;

	EXPECT_ANY_THROW(d.den(0));
}

TEST(Setters, ChecksNeg) {
	Rational d;

	d.num(1);
	d.den(-3);

	EXPECT_EQ(d.den(), 3);
	EXPECT_EQ(d.num(), -1);
}



/*
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
