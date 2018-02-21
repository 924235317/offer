// ������16����ֵ�������η�
// ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
// �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

#include <iostream>
#include <cmath>

bool g_InvalidInput = false;

bool equal(double num1, double num2)
{
    if((num1-num2<0.00001) && (num1-num2>-0.00001))//����Ҫ
        return true;
    return false;
}


//��û�п����ǲ��������
double Power(double base, int exponent)
{
    g_InvalidInput = false;

    if(equal(base, 0.0) && exponent < 0)//����Ҫ
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

    if(equal(base, 0.0) && exponent < 0)//����Ҫ
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

// ====================���Դ���====================
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
    // ������ָ����Ϊ����
    power_Test("power_Test1", 2, 3, 8, false);

    // ����Ϊ������ָ��Ϊ����
    power_Test("power_Test2", -2, 3, -8, false);

    // ָ��Ϊ����
    power_Test("power_Test3", 2, -3, 0.125, false);

    // ָ��Ϊ0
    power_Test("power_Test4", 2, 0, 1, false);

    // ������ָ����Ϊ0
    power_Test("power_Test5", 0, 0, 1, false);

    // ����Ϊ0��ָ��Ϊ����
    power_Test("power_Test6", 0, 4, 0, false);

    // ����Ϊ0��ָ��Ϊ����
    power_Test("power_Test7", 0, -4, 0, true);

    return 0;
}
