#pragma once
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// задача 1.7: разложение числа на простые множители (строка вида "2 * 2 * 3")
inline string factorization(int num)
{
    int i;
    string result = "";
    bool first = true;
    while (num != 1) {
        i = 2;
        while (num % i != 0) {
            i++;
        }
        num = num / i;
        if (!first) {
            result = result + " * ";
        }
        result = result + to_string(i);
        first = false;
    }
    return result;
}

// задача 2.4: простые числа Мерсенна (2^i - 1), не превышающие num
inline vector<int> mersennePrimes(int num)
{
    vector<int> result;
    int i = 2;
    int s = 0;
    while (s <= num) {
        s = pow(2, i) - 1;
        if (s > num) {
            break;
        }
        bool simple = true;
        for (int j = 2; j < s / 2; j++) {
            if (s % j == 0) {
                simple = false;
            }
        }
        if (simple) {
            result.push_back(s);
        }
        i++;
    }
    return result;
}

// задача 3.10: сумма цифр числа равна квадрату центральной цифры
inline bool sumEqualsCenterSquare(int i)
{
    int n = 0;
    int i1 = i;
    int sum = 0;
    while (i1 > 0) {
        n++;
        i1 /= 10;
    }
    int i2 = i;
    for (int j = 1; j != n / 2 + 1; j++) {
        i2 /= 10;
    }
    int sq = i2 % 10;
    int i3 = i;
    while (n != 0) {
        sum = sum + i3 % 10;
        n--;
        i3 /= 10;
    }
    return sq * sq == sum;
}

// все такие числа на отрезке [a, b] (если a > b, они меняются местами)
inline vector<int> findNumbers(int a, int b)
{
    vector<int> result;
    if (a > b) {
        int m = a;
        a = b;
        b = m;
    }
    for (int i = a; i <= b; i++) {
        if (sumEqualsCenterSquare(i)) {
            result.push_back(i);
        }
    }
    return result;
}
