// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <cstdio>

bool matchCore(const char* str, const char* pattern);

bool match(const char* str, const char* pattern)
{
    if(str == nullptr || pattern == nullptr)
        return false;

    return matchCore(str, pattern);
}

bool matchCore(const char *str, const char *pattern)
{
    if(*str == '\0' && *pattern == '\0')
        return true;
    if(*str != '\0' && *pattern == '\0')
        return false;

    if(*(pattern+1) == '*')
    {
        if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchCore(str, pattern+2) ||
                   matchCore(str+1, pattern) ||
                   matchCore(str+1, pattern+2);

        else
            return matchCore(str, pattern+2);
    }

    if(*pattern == *str || (*pattern=='.' && *str != '\0'))
        return matchCore(str+1, pattern+1);

    return false;
}


// ====================测试代码====================
void regular_expressions_Test(const char* regular_expressions_TestName, const char* string, const char* pattern, bool expected)
{
    if(regular_expressions_TestName != nullptr)
        printf("%s begins: ", regular_expressions_TestName);

    if(match(string, pattern) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int test_regular_expressions()
{
    regular_expressions_Test("regular_expressions_Test01", "", "", true);
    regular_expressions_Test("regular_expressions_Test02", "", ".*", true);
    regular_expressions_Test("regular_expressions_Test03", "", ".", false);
    regular_expressions_Test("regular_expressions_Test04", "", "c*", true);
    regular_expressions_Test("regular_expressions_Test05", "a", ".*", true);
    regular_expressions_Test("regular_expressions_Test06", "a", "a.", false);
    regular_expressions_Test("regular_expressions_Test07", "a", "", false);
    regular_expressions_Test("regular_expressions_Test08", "a", ".", true);
    regular_expressions_Test("regular_expressions_Test09", "a", "ab*", true);
    regular_expressions_Test("regular_expressions_Test10", "a", "ab*a", false);
    regular_expressions_Test("regular_expressions_Test11", "aa", "aa", true);
    regular_expressions_Test("regular_expressions_Test12", "aa", "a*", true);
    regular_expressions_Test("regular_expressions_Test13", "aa", ".*", true);
    regular_expressions_Test("regular_expressions_Test14", "aa", ".", false);
    regular_expressions_Test("regular_expressions_Test15", "ab", ".*", true);
    regular_expressions_Test("regular_expressions_Test16", "ab", ".*", true);
    regular_expressions_Test("regular_expressions_Test17", "aaa", "aa*", true);
    regular_expressions_Test("regular_expressions_Test18", "aaa", "aa.a", false);
    regular_expressions_Test("regular_expressions_Test19", "aaa", "a.a", true);
    regular_expressions_Test("regular_expressions_Test20", "aaa", ".a", false);
    regular_expressions_Test("regular_expressions_Test21", "aaa", "a*a", true);
    regular_expressions_Test("regular_expressions_Test22", "aaa", "ab*a", false);
    regular_expressions_Test("regular_expressions_Test23", "aaa", "ab*ac*a", true);
    regular_expressions_Test("regular_expressions_Test24", "aaa", "ab*a*c*a", true);
    regular_expressions_Test("regular_expressions_Test25", "aaa", ".*", true);
    regular_expressions_Test("regular_expressions_Test26", "aab", "c*a*b", true);
    regular_expressions_Test("regular_expressions_Test27", "aaca", "ab*a*c*a", true);
    regular_expressions_Test("regular_expressions_Test28", "aaba", "ab*a*c*a", false);
    regular_expressions_Test("regular_expressions_Test29", "bbbba", ".*a*a", true);
    regular_expressions_Test("regular_expressions_Test30", "bcbbabab", ".*a*a", false);

    return 0;
}

