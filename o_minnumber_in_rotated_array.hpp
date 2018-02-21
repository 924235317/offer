// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include <cstdio>
#include <exception>

int min_inorder(int *numbers, int start, int end)
{
    int res = numbers[start];
    for(int i = 1; i <= end; ++i)
    {
        if(numbers[start+i] < res)
            res = numbers[start+i];
    }
    return res;
}

int Min(int* numbers, int length)
{
    if(!numbers || length <=0)
        return -1;

    int idx_start = 0;
    int idx_end = length - 1;
    int idx_mid = 0;

    while(numbers[idx_start] >= numbers[idx_end])
    {
        if(idx_start == idx_end-1)
            return numbers[idx_end];



        idx_mid = (idx_end + idx_start) / 2;

        if(numbers[idx_end] == numbers[idx_mid] &&
           numbers[idx_mid] == numbers[idx_start])
        {
            int res = min_inorder(numbers, idx_start, idx_end);
            return res;
        }

        if(numbers[idx_mid] >= numbers[idx_end])
            idx_start = idx_mid;
        else if(numbers[idx_mid] <= numbers[idx_end])
            idx_end = idx_mid;
    }

    return numbers[idx_mid];

}

// ====================测试代码====================
void minnumber_in_rotated_array_Test(int* numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for(int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if(result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if(numbers == nullptr)
            printf("minnumber_in_rotated_array_Test passed.\n");
        else
            printf("minnumber_in_rotated_array_Test failed.\n");
    }
}

int test_minnumber_in_rotated_array()
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = { 3, 4, 5, 1, 2 };
    minnumber_in_rotated_array_Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    minnumber_in_rotated_array_Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    minnumber_in_rotated_array_Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = { 1, 0, 1, 1, 1 };
    minnumber_in_rotated_array_Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = { 1, 2, 3, 4, 5 };
    minnumber_in_rotated_array_Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = { 2 };
    minnumber_in_rotated_array_Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    minnumber_in_rotated_array_Test(nullptr, 0, 0);

    return 0;
}
