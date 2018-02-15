// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <cstdio>
#include <cstring>

/*length Ϊ�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���*/
void ReplaceBlank(char str[], int length)
{
    if(str == nullptr || length <= 0)
        return;

    int num_of_str = 0;
    int num_of_blanks = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == ' ')
            ++num_of_blanks;

        ++num_of_str;
        ++i;
    }

    printf("%d,%d\n", num_of_blanks, num_of_str);
    int new_length = num_of_str + num_of_blanks * 2;
    int idx_old = num_of_str;
    int idx_new = new_length;

    if(new_length > length)
        return;

    while(idx_old != idx_new)
    {
        if(str[idx_old] == ' ')
        {
            str[idx_new--] = '0';
            str[idx_new--] = '2';
            str[idx_new--] = '%';
        }
        else
            str[idx_new--] = str[idx_old];

        --idx_old;
    }
}

void ReplaceBlank_Test(char* testName, char str[], int length, char expected[])
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// �ո��ھ����м�
void ReplaceBlank_Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    ReplaceBlank_Test("Test1", str, length, "hello%20world");
    //printf("%s\n", str);
}

// �ո��ھ��ӿ�ͷ
void ReplaceBlank_Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    ReplaceBlank_Test("Test2", str, length, "%20helloworld");
    //printf("%s\n", str);
}

// �ո��ھ���ĩβ
void ReplaceBlank_Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    ReplaceBlank_Test("Test3", str, length, "helloworld%20");
    //printf("%s\n", str);
}

// �����������ո�
void ReplaceBlank_Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    ReplaceBlank_Test("Test4", str, length, "hello%20%20world");
    //printf("%s\n", str);
}

// ����nullptr
void ReplaceBlank_Test5()
{
    ReplaceBlank_Test("Test5", nullptr, 0, nullptr);

}

// ��������Ϊ�յ��ַ���
void ReplaceBlank_Test6()
{
    const int length = 100;

    char str[length] = "";
    ReplaceBlank_Test("Test6", str, length, "");
    //printf("%s\n", str);
}

//��������Ϊһ���ո���ַ���
void ReplaceBlank_Test7()
{
    const int length = 100;

    char str[length] = " ";
    ReplaceBlank_Test("Test7", str, length, "%20");
    //printf("%s\n", str);
}

// ������ַ���û�пո�
void ReplaceBlank_Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    ReplaceBlank_Test("Test8", str, length, "helloworld");
    //printf("%s\n", str);
}

// ������ַ���ȫ�ǿո�
void ReplaceBlank_Test9()
{
    const int length = 100;

    char str[length] = "   ";
    ReplaceBlank_Test("Test9", str, length, "%20%20%20");
    //printf("%s\n", str);
}

int test_ReplaceBlank()
{
    ReplaceBlank_Test1();
    ReplaceBlank_Test2();
    ReplaceBlank_Test3();
    ReplaceBlank_Test4();
    ReplaceBlank_Test5();
    ReplaceBlank_Test6();
    ReplaceBlank_Test7();
    ReplaceBlank_Test8();
    ReplaceBlank_Test9();

    return 0;
}
