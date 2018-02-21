// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
// ����һ����������������һ����ת�������ת�������СԪ�ء���������
// {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��

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

// ====================���Դ���====================
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
    // �������룬��������������һ����ת
    int array1[] = { 3, 4, 5, 1, 2 };
    minnumber_in_rotated_array_Test(array1, sizeof(array1) / sizeof(int), 1);

    // ���ظ����֣������ظ������ָպõ���С������
    int array2[] = { 3, 4, 5, 1, 1, 2 };
    minnumber_in_rotated_array_Test(array2, sizeof(array2) / sizeof(int), 1);

    // ���ظ����֣����ظ������ֲ��ǵ�һ�����ֺ����һ������
    int array3[] = { 3, 4, 5, 1, 2, 2 };
    minnumber_in_rotated_array_Test(array3, sizeof(array3) / sizeof(int), 1);

    // ���ظ������֣������ظ������ָպ��ǵ�һ�����ֺ����һ������
    int array4[] = { 1, 0, 1, 1, 1 };
    minnumber_in_rotated_array_Test(array4, sizeof(array4) / sizeof(int), 0);

    // �����������飬��ת0��Ԫ�أ�Ҳ���ǵ����������鱾��
    int array5[] = { 1, 2, 3, 4, 5 };
    minnumber_in_rotated_array_Test(array5, sizeof(array5) / sizeof(int), 1);

    // ������ֻ��һ������
    int array6[] = { 2 };
    minnumber_in_rotated_array_Test(array6, sizeof(array6) / sizeof(int), 2);

    // ����nullptr
    minnumber_in_rotated_array_Test(nullptr, 0, 0);

    return 0;
}
