#include <cstdio>

// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
bool duplicate_edit(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;

    //��������Ƿ����Ҫ��
    int i = 0;
    for(; i < length; ++i)
    {
        if(numbers[i] < 0 || numbers[i] > length)
            return false;
    }

    for(i = 0; i < length; ++i)
    {
        if(numbers[i] == numbers[numbers[i]])
        {
            *duplication = numbers[i];
            return true;
        }

        int tmp = numbers[numbers[i]];
        numbers[numbers[i]] = numbers[i];
        numbers[i] = tmp;
    }

    return false;
}

void test_duplicate_edit()
{
    int numbers[] = {2,2,1,1,3,4,6,4,8};
    int duplication = -1;
    duplicate_edit(numbers, 9, &duplication);
    printf("%d\n", duplication);
}


// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3��

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
// ����ֵ:
//        ����  - ������Ч�����������д����ظ������֣�����ֵΪ�ظ�������
//        ����  - ������Ч������������û���ظ�������

int duplicate_noedit(int numbers[], int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;

    int start = 1;
    int end = length - 1;
    while(start <= end)
    {
        int mid = (end - start) / 2 + start;

    }
}
