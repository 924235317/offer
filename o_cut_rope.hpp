// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <iostream>
#include <cmath>

// ====================动态规划====================
int maxProductAfterCutting_solution1(int length)
{
    if(length < 2)
        return 0;
    //因为必须切一刀
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;


    int max_value[length+1] = {-1};
    max_value[1] = 1;

    //其实不切更大
    max_value[2] = 2;
    max_value[3] = 3;

    for(int i = 4; i <= length; ++i)
    {
        int max = 0;
        for(int j = 1; j <= i/2; ++j)
        {
            int value = max_value[j] * max_value[i-j];
            if(max < value)
                max = value;
        }

        max_value[i] = max;
    }

    return max_value[length];
}



// ====================测试代码====================
void cut_rope_test(const char* cut_rope_testName, int length, int expected)
{
    int result1 = maxProductAfterCutting_solution1(length);
    if(result1 == expected)
        std::cout << "Solution1 for " << cut_rope_testName << ": " << result1 <<" passed." << std::endl;
    else
        std::cout << "Solution1 for " << cut_rope_testName << ": " << result1<< " FAILED." << std::endl;

//    int result2 = maxProductAfterCutting_solution2(length);
//    if(result2 == expected)
//        std::cout << "Solution2 for " << cut_rope_testName << " passed." << std::endl;
//    else
//        std::cout << "Solution2 for " << cut_rope_testName << " FAILED." << std::endl;
}

void cut_rope_test1()
{
    int length = 1;
    int expected = 0;
    cut_rope_test("cut_rope_test1", length, expected);
}

void cut_rope_test2()
{
    int length = 2;
    int expected = 1;
    cut_rope_test("cut_rope_test2", length, expected);
}

void cut_rope_test3()
{
    int length = 3;
    int expected = 2;
    cut_rope_test("cut_rope_test3", length, expected);
}

void cut_rope_test4()
{
    int length = 4;
    int expected = 4;
    cut_rope_test("cut_rope_test4", length, expected);
}

void cut_rope_test5()
{
    int length = 5;
    int expected = 6;
    cut_rope_test("cut_rope_test5", length, expected);
}

void cut_rope_test6()
{
    int length = 6;
    int expected = 9;
    cut_rope_test("cut_rope_test6", length, expected);
}

void cut_rope_test7()
{
    int length = 7;
    int expected = 12;
    cut_rope_test("cut_rope_test7", length, expected);
}

void cut_rope_test8()
{
    int length = 8;
    int expected = 18;
    cut_rope_test("cut_rope_test8", length, expected);
}

void cut_rope_test9()
{
    int length = 9;
    int expected = 27;
    cut_rope_test("cut_rope_test9", length, expected);
}

void cut_rope_test10()
{
    int length = 10;
    int expected = 36;
    cut_rope_test("cut_rope_test10", length, expected);
}

void cut_rope_test11()
{
    int length = 50;
    int expected = 86093442;
    cut_rope_test("cut_rope_test11", length, expected);
}

int test_cut_rope()
{
    cut_rope_test1();
    cut_rope_test2();
    cut_rope_test3();
    cut_rope_test4();
    cut_rope_test5();
    cut_rope_test6();
    cut_rope_test7();
    cut_rope_test8();
    cut_rope_test9();
    cut_rope_test10();
    cut_rope_test11();

    return 0;
}
