// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

#include <cstdio>

// ====================方法1：递归====================
long long Fibonacci_Solution1(unsigned int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    return Fibonacci_Solution1(n-1) + Fibonacci_Solution1(n-2);
}

// ====================方法2：循环====================
long long Fibonacci_Solution2(unsigned n)
{
    int result[] = {0, 1};
    if(n < 2)
        return result[n];

    int i = 2;
    int n_1 = result[0];
    int n_2 = result[1];
    long long res = 0;
    for(; i <= n; ++i)
    {
        res = n_1 + n_2;
        n_1 = n_2;
        n_2 = res;
    }

    return res;
}


// ====================测试代码====================
void fibonacci_Test(int n, int expected)
{
    if(Fibonacci_Solution1(n) == expected)
        printf("fibonacci_Test for %d in solution1 passed.\n", n);
    else
        printf("fibonacci_Test for %d in solution1 failed.\n", n);

    if(Fibonacci_Solution2(n) == expected)
        printf("fibonacci_Test for %d in solution2 passed.\n", n);
    else
        printf("fibonacci_Test for %d in solution2 failed.\n", n);
//
//    if(Fibonacci_Solution3(n) == expected)
//        printf("fibonacci_Test for %d in solution3 passed.\n", n);
//    else
//        printf("fibonacci_Test for %d in solution3 failed.\n", n);
}

int test_fibonacci()
{
    fibonacci_Test(0, 0);
    fibonacci_Test(1, 1);
    fibonacci_Test(2, 1);
    fibonacci_Test(3, 2);
    fibonacci_Test(4, 3);
    fibonacci_Test(5, 5);
    fibonacci_Test(6, 8);
    fibonacci_Test(7, 13);
    fibonacci_Test(8, 21);
    fibonacci_Test(9, 34);
    fibonacci_Test(10, 55);

    fibonacci_Test(40, 102334155);

    return 0;
}
