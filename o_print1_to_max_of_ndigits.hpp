// ������17����ӡ1������nλ��
// ��Ŀ����������n����˳���ӡ����1����nλʮ����������������3����
// ��ӡ��1��2��3һֱ������3λ����999��

#include <cstdio>
#include <memory>

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// ====================����һ====================
void Print1ToMaxOfNDigits_1(int n)
{
    if(n <= 0)
        return;

    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    while(!Increment(number))
    {
        PrintNumber(number);
    }

    delete[] number;
}

bool Increment(char* number)
{
    bool is_overflow = false;
    int take_over = 0;
    int length = strlen(number);

    for(int i = length-1; i >= 0; --i)
    {
        int sum = number[i] - '0' + take_over;
        if(i == length-1)//����Ҫ�������λ��һ������
            sum++;
        if(sum >= 10)//�����λ
        {
            if(i == 0)
                is_overflow = true;
            else
            {
                take_over = 1;//��λֻ������1
                sum -= 10;
                number[i] = '0' + sum;
            }
        }
        else
        {
            number[i] = '0' + sum;
            break;
        }


    }
    return is_overflow;
}


void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for(int i = 0; i < 10; ++i)//ȷ��һλ����ӡ��һλ��������������
    {
        number[index+1] = '0' + i;
        Print1ToMaxOfNDigitsRecursively(number, length, index+1);
    }
}

void Print1ToMaxOfNDigits_2(int n)
{
    if(n <= 0)
        return;

    char *number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';

    for(int i = 0; i < 10; ++i)
    {
        number[0] = '0' + i;
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}

// ====================��������====================
// �ַ���number��ʾһ�����֣����������ɸ�0��ͷ
// ��ӡ��������֣������Կ�ͷ��0
void PrintNumber(char* number)
{
    bool isBeginning0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; ++i)
    {
        if (isBeginning0 && number[i] != '0')
            isBeginning0 = false;

        if (!isBeginning0)
        {
            printf("%c", number[i]);
        }
    }

    printf("\t");
}



// ====================���Դ���====================
void print1_to_max_of_ndigits_Test(int n)
{
    printf("print1_to_max_of_ndigits_Test for %d begins:\n", n);

    //Print1ToMaxOfNDigits_1(n);
    Print1ToMaxOfNDigits_2(n);

    printf("\nprint1_to_max_of_ndigits_Test for %d ends.\n", n);
}

int test_print1_to_max_of_ndigits()
{

    //PrintNumber("1234");
    print1_to_max_of_ndigits_Test(1);
    print1_to_max_of_ndigits_Test(2);
    print1_to_max_of_ndigits_Test(3);
    print1_to_max_of_ndigits_Test(0);
    print1_to_max_of_ndigits_Test(-1);

    return 0;
}
