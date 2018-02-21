// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include <iostream>
#include <cmath>

bool g_InvalidInput = false;

bool equal(double num1, double num2)
{
    if((num1-num2<0.00001) && (num1-num2>-0.00001))//很重要
        return true;
    return false;
}


//还没有考虑是不是溢出了
double Power(double base, int exponent)
{
    g_InvalidInput = false;

    if(equal(base, 0.0) && exponent < 0)//很重要
    {
        g_InvalidInput = true;
        return 0;
    }

    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    bool is_neg = false;
    int abs_exponent;
    if(exponent < 0)
    {
        is_neg = true;
        abs_exponent = -exponent;
    }
    else
        abs_exponent = exponent;


    double res = 1.0;
    for(int i = 1; i <= abs_exponent; ++i)
        res *= base;

    if(is_neg)
        res = 1.0/res;

    return res;
}

double PowerCore(double base, int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    double res = PowerCore(base, exponent >> 1);
    res *= res;
    if((exponent & 0x1) == 1)
        res *= base;

    return res;
}

double Power2(double base, int exponent)
{
    g_InvalidInput = false;

    if(equal(base, 0.0) && exponent < 0)//很重要
    {
        g_InvalidInput = true;
        return 0;
    }

    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;

    bool is_neg = false;
    int abs_exponent;
    if(exponent < 0)
    {
        is_neg = true;
        abs_exponent = -exponent;
    }
    else
        abs_exponent = exponent;


    //////////////////////////
    double res = PowerCore(base, abs_exponent);

    if(is_neg)
        res = 1.0/res;

    return res;

}

// ====================测试代码====================
void power_Test(const char* power_TestName, double base, int exponent, double expectedResult, bool expectedFlag)
{
    double result = Power(base, exponent);
    if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
        std::cout << power_TestName << " passed" << std::endl;
    else
        std::cout << power_TestName << " FAILED :" << result << std::endl;
}



int test_power()
{
    // 底数、指数都为正数
    power_Test("power_Test1", 2, 3, 8, false);

    // 底数为负数、指数为正数
    power_Test("power_Test2", -2, 3, -8, false);

    // 指数为负数
    power_Test("power_Test3", 2, -3, 0.125, false);

    // 指数为0
    power_Test("power_Test4", 2, 0, 1, false);

    // 底数、指数都为0
    power_Test("power_Test5", 0, 0, 1, false);

    // 底数为0、指数为正数
    power_Test("power_Test6", 0, 4, 0, false);

    // 底数为0、指数为负数
    power_Test("power_Test7", 0, -4, 0, true);

    return 0;
}
