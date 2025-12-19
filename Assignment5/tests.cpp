/*
 *Elena Tsyganova
 *st142266@student.spbu.ru
 *Assignment3
 */

#include <gtest/gtest.h>
#include "matrix.h"
#include "rational.h"

TEST(MatrixTest, MatrixAddition_Int) {
    Matrix<2, 2, int> a;
    a(0, 0) = 1; a(0, 1) = 2;
    a(1, 0) = 3; a(1, 1) = 4;

    Matrix<2, 2, int> b;
    b(0, 0) = 5; b(0, 1) = 6;
    b(1, 0) = 7; b(1, 1) = 8;

    Matrix<2, 2, int> c = a + b;

    EXPECT_EQ(c(0, 0), 6);
    EXPECT_EQ(c(0, 1), 8);
    EXPECT_EQ(c(1, 0), 10);
    EXPECT_EQ(c(1, 1), 12);
}

TEST(MatrixTest, MatrixAddition_Rational) {
    Matrix<2, 2, Rational> a;
    a(0, 0) = Rational(1, 2);
    a(0, 1) = Rational(3, 4);
    a(1, 0) = Rational(2, 3);
    a(1, 1) = Rational(5, 1);

    Matrix<2, 2, Rational> b;
    b(0, 0) = Rational(1, 3);
    b(0, 1) = Rational(1, 4);
    b(1, 0) = Rational(4, 3);
    b(1, 1) = Rational(-2, 1);

    Matrix<2, 2, Rational> c = a + b;

    EXPECT_EQ(c(0, 0).numerator(), 5);
    EXPECT_EQ(c(0, 0).denominator(), 6);
    EXPECT_EQ(c(0, 1).numerator(), 1);
    EXPECT_EQ(c(0, 1).denominator(), 1);
    EXPECT_EQ(c(1, 0).numerator(), 2);
    EXPECT_EQ(c(1, 0).denominator(), 1);
    EXPECT_EQ(c(1, 1).numerator(), 3);
    EXPECT_EQ(c(1, 1).denominator(), 1);
}

TEST(MatrixTest, ScalarMultiplication_Double) {
    Matrix<2, 3, double> m;
    m(0, 0) = 1; m(0, 1) = 2; m(0, 2) = 3;
    m(1, 0) = 4; m(1, 1) = 5; m(1, 2) = 6;

    double scalar = 2.5;
    Matrix<2, 3, double> result = m * scalar;

    EXPECT_DOUBLE_EQ(result(0, 0), 2.5);
    EXPECT_DOUBLE_EQ(result(0, 1), 5.0);
    EXPECT_DOUBLE_EQ(result(0, 2), 7.5);
    EXPECT_DOUBLE_EQ(result(1, 0), 10.0);
    EXPECT_DOUBLE_EQ(result(1, 1), 12.5);
    EXPECT_DOUBLE_EQ(result(1, 2), 15.0);
}

TEST(MatrixTest, ScalarMultiplication_Rational) {
    Matrix<2, 2, Rational> m;
    m(0, 0) = Rational(1, 2);
    m(0, 1) = Rational(3, 1);
    m(1, 0) = Rational(0, 1);
    m(1, 1) = Rational(4, 5);

    Rational scalar(2, 3);
    Matrix<2, 2, Rational> result = m * scalar;

    EXPECT_EQ(result(0, 0).numerator(), 1);
    EXPECT_EQ(result(0, 0).denominator(), 3);
    EXPECT_EQ(result(0, 1).numerator(), 2);
    EXPECT_EQ(result(0, 1).denominator(), 1);
    EXPECT_EQ(result(1, 0).numerator(), 0);
    EXPECT_EQ(result(1, 0).denominator(), 1);
    EXPECT_EQ(result(1, 1).numerator(), 8);
    EXPECT_EQ(result(1, 1).denominator(), 15);
}

TEST(MatrixTest, MatrixMultiplication_Int) {
    Matrix<2, 3, int> a;
    a(0, 0) = 1; a(0, 1) = 2; a(0, 2) = 3;
    a(1, 0) = 4; a(1, 1) = 5; a(1, 2) = 6;

    Matrix<3, 2, int> b;
    b(0, 0) = 7; b(0, 1) = 8;
    b(1, 0) = 9; b(1, 1) = 10;
    b(2, 0) = 11; b(2, 1) = 12;

    Matrix<2, 2, int> c = a * b;

    EXPECT_EQ(c(0, 0), 58);
    EXPECT_EQ(c(0, 1), 64);
    EXPECT_EQ(c(1, 0), 139);
    EXPECT_EQ(c(1, 1), 154);
}

TEST(MatrixTest, MatrixMultiplication_Rational) {
    Matrix<2, 2, Rational> a;
    a(0, 0) = Rational(1, 2);
    a(0, 1) = Rational(1, 3);
    a(1, 0) = Rational(1, 4);
    a(1, 1) = Rational(1, 5);

    Matrix<2, 2, Rational> b;
    b(0, 0) = Rational(2, 1);
    b(0, 1) = Rational(0, 1);
    b(1, 0) = Rational(0, 1);
    b(1, 1) = Rational(5, 1);

    Matrix<2, 2, Rational> c = a * b;

    EXPECT_EQ(c(0, 0).numerator(), 1);
    EXPECT_EQ(c(0, 0).denominator(), 1);
    EXPECT_EQ(c(0, 1).numerator(), 5);
    EXPECT_EQ(c(0, 1).denominator(), 3);
    EXPECT_EQ(c(1, 0).numerator(), 1);
    EXPECT_EQ(c(1, 0).denominator(), 2);
    EXPECT_EQ(c(1, 1).numerator(), 1);
    EXPECT_EQ(c(1, 1).denominator(), 1);
}

TEST(MatrixTest, Transpose_Int) {
    Matrix<3, 2, int> m;
    m(0, 0) = 1; m(0, 1) = 2;
    m(1, 0) = 3; m(1, 1) = 4;
    m(2, 0) = 5; m(2, 1) = 6;

    Matrix<2, 3, int> t = m.transpose();

    EXPECT_EQ(t(0, 0), 1);
    EXPECT_EQ(t(0, 1), 3);
    EXPECT_EQ(t(0, 2), 5);
    EXPECT_EQ(t(1, 0), 2);
    EXPECT_EQ(t(1, 1), 4);
    EXPECT_EQ(t(1, 2), 6);
}

TEST(MatrixTest, Transpose_Rational) {
    Matrix<2, 3, Rational> m;
    m(0, 0) = Rational(1, 2);
    m(0, 1) = Rational(3, 4);
    m(0, 2) = Rational(5, 6);
    m(1, 0) = Rational(7, 8);
    m(1, 1) = Rational(9, 10);
    m(1, 2) = Rational(11, 12);

    Matrix<3, 2, Rational> t = m.transpose();

    EXPECT_EQ(t(0, 0).numerator(), 1);
    EXPECT_EQ(t(0, 0).denominator(), 2);
    EXPECT_EQ(t(0, 1).numerator(), 7);
    EXPECT_EQ(t(0, 1).denominator(), 8);
    EXPECT_EQ(t(1, 0).numerator(), 3);
    EXPECT_EQ(t(1, 0).denominator(), 4);
    EXPECT_EQ(t(1, 1).numerator(), 9);
    EXPECT_EQ(t(1, 1).denominator(), 10);
    EXPECT_EQ(t(2, 0).numerator(), 5);
    EXPECT_EQ(t(2, 0).denominator(), 6);
    EXPECT_EQ(t(2, 1).numerator(), 11);
    EXPECT_EQ(t(2, 1).denominator(), 12);
}
TEST(RationalTest, TestInvariance) {
    Rational r1(1, 2);
    Rational r2(2, 4);
    EXPECT_EQ(r1.numerator(), r2.numerator());
    EXPECT_EQ(r1.denominator(), r2.denominator());

    Rational r3(3, 4);
    Rational r4(-3, -4);
    EXPECT_EQ(r3.numerator(), r4.numerator());
    EXPECT_EQ(r3.denominator(), r4.denominator());

    Rational r5(5, 6);
    Rational r6(-10, -12);
    EXPECT_EQ(r5.numerator(), r6.numerator());
    EXPECT_EQ(r5.denominator(), r6.denominator());

    Rational r7(0, 1);
    Rational r8(0, 52);
    EXPECT_EQ(r7.numerator(), r8.numerator());
    EXPECT_EQ(r7.denominator(), r8.denominator());

    Rational r9(-7, 8);
    Rational r10(7, -8);
    EXPECT_EQ(r9.numerator(), r10.numerator());
    EXPECT_EQ(r9.denominator(), r10.denominator());

    Rational r11(-9, 10);
    Rational r12(18, -20);
    EXPECT_EQ(r11.numerator(), r12.numerator());
    EXPECT_EQ(r11.denominator(), r12.denominator());

    Rational a = Rational(5, 1);  // Явное создание
    EXPECT_EQ(a.numerator(), 5);
    EXPECT_EQ(a.denominator(), 1);
    
    Rational b = Rational(25, 5);
    EXPECT_EQ(b.numerator(), 5);
    EXPECT_EQ(b.denominator(), 1);

    Rational c = Rational(0, 1);
    EXPECT_EQ(c.numerator(), 0);
    EXPECT_EQ(c.denominator(), 1);
    
    Rational d = Rational(0, 52);
    EXPECT_EQ(d.numerator(), 0);
    EXPECT_EQ(d.denominator(), 1);
}

TEST(RationalTest, TestOperations) {
    Rational r1 = Rational(1, 4) + Rational(1, 6);
    EXPECT_EQ(r1.numerator(), 5);
    EXPECT_EQ(r1.denominator(), 12);

    Rational r2 = Rational(1, 4) - Rational(1, 6);
    EXPECT_EQ(r2.numerator(), 1);
    EXPECT_EQ(r2.denominator(), 12);

    Rational r3 = Rational(3, 4) * Rational(5, 6);
    EXPECT_EQ(r3.numerator(), 5);
    EXPECT_EQ(r3.denominator(), 8); 
}
