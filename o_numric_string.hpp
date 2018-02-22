// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include <stdio.h>

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str)
{
    if(str == nullptr)
    {
        //printf("nullptr\n");
        return false;
    }

    bool numeric = scanInteger(&str);

    if(*str == '.')
    {
        ++str;
        bool b = scanUnsignedInteger(&str);
        numeric = (numeric || b);
    }


    if(*str == 'e' || *str == 'E')
    {
        ++str;
        numeric = numeric && scanInteger(&str);
    }


    return *str == '\0' && numeric;
}


bool scanUnsignedInteger(const char** str)
{
    const char *before = *str;
    while(**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);

    return *str > before;
}
bool scanInteger(const char** str)
{
    if(**str == '-' || **str == '+')
        ++(*str);

    return scanUnsignedInteger(str);
}

// ====================测试代码====================
void numeric_string_Test(const char* numeric_string_TestName, const char* str, bool expected)
{
    if(numeric_string_TestName != nullptr)
        printf("%s begins: ", numeric_string_TestName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int test_numeric_string()
{
    numeric_string_Test("numeric_string_Test1", "100", true);
    numeric_string_Test("numeric_string_Test2", "123.45e+6", true);
    numeric_string_Test("numeric_string_Test3", "+500", true);
    numeric_string_Test("numeric_string_Test4", "5e2", true);
    numeric_string_Test("numeric_string_Test5", "3.1416", true);
    numeric_string_Test("numeric_string_Test6", "600.", true);
    numeric_string_Test("numeric_string_Test7", "-.123", true);
    numeric_string_Test("numeric_string_Test8", "-1E-16", true);
    numeric_string_Test("numeric_string_Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    numeric_string_Test("numeric_string_Test10", "12e", false);
    numeric_string_Test("numeric_string_Test11", "1a3.14", false);
    numeric_string_Test("numeric_string_Test12", "1+23", false);
    numeric_string_Test("numeric_string_Test13", "1.2.3", false);
    numeric_string_Test("numeric_string_Test14", "+-5", false);
    numeric_string_Test("numeric_string_Test15", "12e+5.4", false);
    numeric_string_Test("numeric_string_Test16", ".", false);
    numeric_string_Test("numeric_string_Test17", ".e1", false);
    numeric_string_Test("numeric_string_Test18", "e1", false);
    numeric_string_Test("numeric_string_Test19", "+.", false);
    numeric_string_Test("numeric_string_Test20", "", false);
    numeric_string_Test("numeric_string_Test21", nullptr, false);

    return 0;
}
