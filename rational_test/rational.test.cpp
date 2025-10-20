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

TEST(Setters, Values) {
	Rational d;
	d.num(4);
	d.den(2);

	EXPECT_EQ(d.den(), 1);
	EXPECT_EQ(d.num(), 2);
}



TEST(MathOps, Addition) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	Rational result = a + b;
	EXPECT_EQ(result.num(), 1);
	EXPECT_EQ(result.den(), 1);
}

TEST(MathOps, Subtraction) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	Rational result = a - b;
	EXPECT_EQ(result.num(), 0);
	EXPECT_EQ(result.den(), 1);
}

TEST(MathOps, Multiplication) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	Rational result = a * b;
	EXPECT_EQ(result.num(), 1);
	EXPECT_EQ(result.den(), 4);
}

TEST(MathOps, Division) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	Rational result = a / b;
	EXPECT_EQ(result.num(), 1);
	EXPECT_EQ(result.den(), 1);
}

TEST(MathAssignOps, PlusEquals) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	a += b;
	EXPECT_EQ(a.num(), 1);
	EXPECT_EQ(a.den(), 1);
}

TEST(MathAssignOps, MinusEquals) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	a -= b;
	EXPECT_EQ(a.num(), 0);
	EXPECT_EQ(a.den(), 1);
}

TEST(MathAssignOps, TimesEquals) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	a *= b;
	EXPECT_EQ(a.num(), 1);
	EXPECT_EQ(a.den(), 4);
}
TEST(MathAssignOps, DividEquals) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	a /= b;
	EXPECT_EQ(a.num(), 1);
	EXPECT_EQ(a.den(), 1);
}


TEST(CompareOp, EqualTo) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	EXPECT_TRUE(a == b);
}
TEST(CompareOp, NotEqualTo) {
	Rational a{ 1, 2 };
	Rational b{ 1, 3 };
	EXPECT_TRUE(a != b);
}
TEST(CompareOp, LessThan) {
	Rational a{ 1, 3 };
	Rational b{ 1, 2 };
	EXPECT_TRUE(a < b);
}
TEST(CompareOp, GreaterThanEqualTo) {
	Rational a{ 1, 2 };
	Rational b{ 1, 3 };
	EXPECT_TRUE(a >= b);
}
TEST(CompareOp, GreaterThanEqualToEqual) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	EXPECT_TRUE(a >= b);
}
TEST(CompareOp, GreaterThan) {
	Rational a{ 1, 2 };
	Rational b{ 1, 3 };
	EXPECT_TRUE(a > b);
}
TEST(CompareOp, LessThanEqualTo) {
	Rational a{ 1, 3 };
	Rational b{ 1, 2 };
	EXPECT_TRUE(a <= b);
}
TEST(CompareOp, LessThanEqualToEqual) {
	Rational a{ 1, 2 };
	Rational b{ 1, 2 };
	EXPECT_TRUE(a <= b);
}

TEST(ConvertOps, Int) {
	Rational a{ 3 };
	
	EXPECT_EQ(a.num(), 3);
	EXPECT_EQ(a.den(), 1);
}

TEST(ConvertOps, Double) {
	Rational a{ 3.0 };

	EXPECT_EQ(a.num(), 3);
	EXPECT_EQ(a.den(), 1);
}

TEST(ConvertOps, RationalPlusRational) {
	Rational a{ 3.0 };
	Rational b{ 3, 4 };

	Rational Result = a + b;
	EXPECT_EQ(Result.num(), 15);
	EXPECT_EQ(Result.den(), 4);
}

TEST(ConvertOps, DoublePlusRational) {
	Rational a{ 3, 4 };
	

	Rational Result = 3 + a;
	EXPECT_EQ(Result.num(), 15);
	EXPECT_EQ(Result.den(), 4);
}

TEST(ConvertOps, DoubleEqualRational) {
	Rational a{ 3, 1 };


	EXPECT_TRUE(3.0 == a);
}

TEST(ConvertOps, DoubleNotEqualRational) {
	Rational a{ 3, 1 };


	EXPECT_TRUE(4.0 != a);
}

TEST(IoOps, InputOperator) {
	std::istringstream in("4/6");
	Rational r;
	in >> r;
	EXPECT_EQ(r.num(), 2);
	EXPECT_EQ(r.den(), 3);
}

TEST(IoOps, OutputOne) {
	Rational a{ 3, 4};

	std::ostringstream out;

	out << a;

	EXPECT_EQ(out.str(), "3/4");
}

