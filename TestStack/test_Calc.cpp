#include "gtest.h"
#include "../stack/Calcul.h"


TEST(TCalculator, can_create_calc) {
	ASSERT_NO_THROW(TCalculator n);
}

TEST(TCalculator, can_calculate) {
	TCalculator m;
	m.SetExpr("2+2");
	ASSERT_NO_THROW(m.CalcOne());
}

TEST(TCalculator, correct_plus_calculate) {
	TCalculator m;
	m.SetExpr("2+2");
	EXPECT_EQ(4,m.CalcOne());
}

TEST(TCalculator, correct_minus_calculate) {
	TCalculator m;
	m.SetExpr("2-2");
	EXPECT_EQ(0, m.CalcOne());
}

TEST(TCalculator, correct_multiply_calculate) {
	TCalculator m;
	m.SetExpr("3*2");
	EXPECT_EQ(6, m.CalcOne());
}

TEST(TCalculator, correct_split_calculate) {
	TCalculator m;
	m.SetExpr("6/2");
	EXPECT_EQ(3, m.CalcOne());
}

TEST(TCalculator, correct_stepen_calculate) {
	TCalculator m;
	m.SetExpr("6^2");
	EXPECT_EQ(36, m.CalcOne());
}

TEST(TCalculator, correct_calculate_hard_expr) {
	TCalculator m;
	m.SetExpr("(2+((4*2)-6)^(4/2))/6");
	double res = (2 + ((4 * 2) - 6) ^ (4 / 2)) / 6.0;
	EXPECT_EQ(res, m.CalcOne());
}


TEST(TCalculator, correct_brackate_one) {
	TCalculator m;
	m.SetExpr("2+(2)");
	ASSERT_NO_THROW(m.CalcOne());
}

TEST(TCalculator, correct_brackate_two) {
	TCalculator m;
	m.SetExpr("(((2)+(2)))");
	ASSERT_NO_THROW(m.CalcOne());
}

TEST(TCalculator, uncorrect_brackate) {
	TCalculator m;
	m.SetExpr("(2+(2)");
	
	ASSERT_ANY_THROW(m.CalcOne());
}

TEST(TCalculator, uncorrect_operand) {
	TCalculator m;
	m.SetExpr("2 2");

	ASSERT_ANY_THROW(m.CalcOne());
}

TEST(TCalculator, uncorrect_operator) {
	TCalculator m;
	m.SetExpr("2++2");

	ASSERT_ANY_THROW(m.CalcOne());
}

/*
могу созд
набор на проверку корект расстан скобок с разными выражениями
полн набор тестов на операции 2+2 =4
некоректн выражения
больще операндов больше операций

*/