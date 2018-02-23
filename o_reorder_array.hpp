// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。

#include <cstdio>

bool is_odd(int n)
{
    return n & 1;
}

void swap_num(int *n1, int *n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void ReorderOddEven_1(int *pData, unsigned int length)
{
    if(!pData || length == 0)
        return;

    int *start = pData;
    int *end = pData + length - 1;

    while(start < end)
    {
        while(start < end && is_odd(*start))
            ++start;

        while(start < end && !is_odd(*end))
            --end;

        if(start < end)
        {
            swap_num(start, end);
        }

    }
}

// ====================方法二====================
void reorder(int *pData, unsigned int length, bool (*func)(int))
{
    if(!pData || length == 0)
        return;

    int *start = pData;
    int *end = pData + length - 1;

    while(start < end)
    {
        while(start < end && func(*start))
            ++start;

        while(start < end && !func(*end))
            --end;

        if(start < end)
        {
            swap_num(start, end);
        }

    }
}

void ReorderOddEven_2(int *pData, unsigned int length)
{
    reorder(pData, length, is_odd);
}


// ====================测试代码====================
void PrintArray(int numbers[], int length)
{
    if(length < 0)
        return;

    for(int i = 0; i < length; ++i)
        printf("%d\t", numbers[i]);

    printf("\n");
}

void reorder_array_Test(char* reorder_array_TestName, int numbers[], int length)
{
    if(reorder_array_TestName != nullptr)
        printf("%s begins:\n", reorder_array_TestName);

    int* copy = new int[length];
    for(int i = 0; i < length; ++i)
    {
        copy[i] = numbers[i];
    }

    printf("reorder_array_Test for solution 1:\n");
    PrintArray(numbers, length);
    ReorderOddEven_1(numbers, length);
    PrintArray(numbers, length);

    printf("reorder_array_Test for solution 2:\n");
    PrintArray(copy, length);
    ReorderOddEven_2(copy, length);
    PrintArray(copy, length);

    delete[] copy;
}

void reorder_array_Test1()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7};
    reorder_array_Test("reorder_array_Test1", numbers, sizeof(numbers)/sizeof(int));
}

void reorder_array_Test2()
{
    int numbers[] = {2, 4, 6, 1, 3, 5, 7};
    reorder_array_Test("reorder_array_Test2", numbers, sizeof(numbers)/sizeof(int));
}

void reorder_array_Test3()
{
    int numbers[] = {1, 3, 5, 7, 2, 4, 6};
    reorder_array_Test("reorder_array_Test3", numbers, sizeof(numbers)/sizeof(int));
}

void reorder_array_Test4()
{
    int numbers[] = {1};
    reorder_array_Test("reorder_array_Test4", numbers, sizeof(numbers)/sizeof(int));
}

void reorder_array_Test5()
{
    int numbers[] = {2};
    reorder_array_Test("reorder_array_Test5", numbers, sizeof(numbers)/sizeof(int));
}

void reorder_array_Test6()
{
    reorder_array_Test("reorder_array_Test6", nullptr, 0);
}

int test_reorder_array()
{
    reorder_array_Test1();
    reorder_array_Test2();
    reorder_array_Test3();
    reorder_array_Test4();
    reorder_array_Test5();
    reorder_array_Test6();

    return 0;
}
