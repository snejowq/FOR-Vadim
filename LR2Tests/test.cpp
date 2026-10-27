#include "pch.h"
#include "lab2_functions.h"

// задача 1.7: разложение на простые множители
TEST(Factorization, Number12)
{
    EXPECT_EQ(factorization(12), "2 * 2 * 3");
}

TEST(Factorization, Number100)
{
    EXPECT_EQ(factorization(100), "2 * 2 * 5 * 5");
}

// простое число раскладывается само на себя
TEST(Factorization, PrimeNumber)
{
    EXPECT_EQ(factorization(97), "97");
}

TEST(Factorization, BigPrimeNumber)
{
    EXPECT_EQ(factorization(7919), "7919");
}

// самое маленькое допустимое число после единицы
TEST(Factorization, Number2)
{
    EXPECT_EQ(factorization(2), "2");
}

TEST(Factorization, PowerOfTwo)
{
    EXPECT_EQ(factorization(64), "2 * 2 * 2 * 2 * 2 * 2");
}

TEST(Factorization, ThreeDifferentPrimes)
{
    EXPECT_EQ(factorization(1001), "7 * 11 * 13");
}

// задача 2.4: простые числа Мерсенна не больше N
TEST(Mersenne, TooSmall)
{
    vector<int> expected = {};
    EXPECT_EQ(mersennePrimes(1), expected);
    EXPECT_EQ(mersennePrimes(2), expected);
}

// граница включается: само число 3 подходит
TEST(Mersenne, BorderIncluded)
{
    vector<int> expected = {3};
    EXPECT_EQ(mersennePrimes(3), expected);
}

TEST(Mersenne, UpTo7)
{
    vector<int> expected = {3, 7};
    EXPECT_EQ(mersennePrimes(7), expected);
}

// 15 = 2^4 - 1 не простое, поэтому в список не попадает
TEST(Mersenne, UpTo30)
{
    vector<int> expected = {3, 7};
    EXPECT_EQ(mersennePrimes(30), expected);
}

TEST(Mersenne, UpTo31)
{
    vector<int> expected = {3, 7, 31};
    EXPECT_EQ(mersennePrimes(31), expected);
}

TEST(Mersenne, UpTo127)
{
    vector<int> expected = {3, 7, 31, 127};
    EXPECT_EQ(mersennePrimes(127), expected);
}

TEST(Mersenne, UpTo10000)
{
    vector<int> expected = {3, 7, 31, 127, 8191};
    EXPECT_EQ(mersennePrimes(10000), expected);
}

// задача 3.10: сумма цифр равна квадрату центральной цифры
TEST(CenterSquare, ExamplesFromTask)
{
    EXPECT_TRUE(sumEqualsCenterSquare(22));
    EXPECT_TRUE(sumEqualsCenterSquare(121));
    EXPECT_TRUE(sumEqualsCenterSquare(333));
    EXPECT_TRUE(sumEqualsCenterSquare(234));
}

TEST(CenterSquare, FiveDigitNumber)
{
    EXPECT_TRUE(sumEqualsCenterSquare(12321));
}

// у однозначного числа сумма цифр равна самой цифре, нужно d*d = d
TEST(CenterSquare, OneDigit)
{
    EXPECT_TRUE(sumEqualsCenterSquare(1));
    EXPECT_FALSE(sumEqualsCenterSquare(2));
    EXPECT_FALSE(sumEqualsCenterSquare(9));
}

TEST(CenterSquare, NotSuitable)
{
    EXPECT_FALSE(sumEqualsCenterSquare(123));
    EXPECT_FALSE(sumEqualsCenterSquare(111));
    EXPECT_FALSE(sumEqualsCenterSquare(555));
    EXPECT_FALSE(sumEqualsCenterSquare(12));
}

// центральная цифра 0: сумма цифр не может быть нулём
TEST(CenterSquare, ZeroInCenter)
{
    EXPECT_FALSE(sumEqualsCenterSquare(100));
    EXPECT_FALSE(sumEqualsCenterSquare(505));
}

TEST(CenterSquare, FindInSmallRange)
{
    vector<int> expected = {121};
    EXPECT_EQ(findNumbers(120, 125), expected);
}

TEST(CenterSquare, FindOneNumber)
{
    vector<int> expected = {333};
    EXPECT_EQ(findNumbers(330, 335), expected);
}

// границы в обратном порядке: результат тот же
TEST(CenterSquare, ReversedBorders)
{
    vector<int> expected = {121};
    EXPECT_EQ(findNumbers(125, 120), expected);
}

TEST(CenterSquare, NothingFound)
{
    vector<int> expected = {};
    EXPECT_EQ(findNumbers(500, 510), expected);
}
