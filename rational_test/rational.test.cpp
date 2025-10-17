#include "rational.hpp"
#include <gtest/gtest.h>

TEST(DefaultCtor, rightValues) {
	Rational d;

	EXPECT_EQ(d.dem(), 1);
	EXPECT_EQ(d.num(), 0);

}


TEST(ValueCtor, rightValues) {

	Rational d(1, 3);
	
	EXPECT_EQ(d.num(), 1);
	EXPECT_EQ(d.dem(), 3);
	
}

/*
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
