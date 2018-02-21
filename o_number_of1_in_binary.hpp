// ������15����������1�ĸ���
// ��Ŀ����ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ���������
// ��9��ʾ�ɶ�������1001����2λ��1������������9���ú������2��

#include <cstdio>

int NumberOf1_Solution1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(flag & n)
            ++count;

        flag = flag << 1;
    }

    return count;
}

int NumberOf1_Solution2(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n = n & (n-1);
    }

    return count;
}

// ====================���Դ���====================
void number_of1_in_binary_Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution1(number);
    if (actual == expected)
        printf("Solution1: number_of1_in_binary_Test for %p passed.\n", number);
    else
        printf("Solution1: number_of1_in_binary_Test for %p failed.\n", number);

    actual = NumberOf1_Solution2(number);
    if (actual == expected)
        printf("Solution2: number_of1_in_binary_Test for %p passed.\n", number);
    else
        printf("Solution2: number_of1_in_binary_Test for %p failed.\n", number);

    printf("\n");
}

int test_number_of1_in_binary()
{
    // ����0���ڴ��������0
    number_of1_in_binary_Test(0, 0);

    // ����1���ڴ��������1
    number_of1_in_binary_Test(-1, 32);

    // ����10���ڴ��������2
    number_of1_in_binary_Test(10, 2);

    // ����0x7FFFFFFF���ڴ��������31
    number_of1_in_binary_Test(0x7FFFFFFF, 31);

    // ����0xFFFFFFFF�����������ڴ��������32
    number_of1_in_binary_Test(0xFFFFFFFF, 32);

    // ����0x80000000�����������ڴ��������1
    number_of1_in_binary_Test(0x80000000, 1);

    return 0;
}
