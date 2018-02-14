//#include <iostream>
#include<cstring>
#include<cstdio>

using namespace std;

class CMyString
{
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString& str);
    ~CMyString(void);

    CMyString& operator = (const CMyString& str);

    void Print();

private:
    char* m_pData;
};


CMyString::CMyString(char *pData)
{
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData) + 1;
        m_pData = new char[length];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString& str)
{
    int length = strlen(str.m_pData) + 1;
    m_pData = new char[length];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
    delete[] m_pData;
}

CMyString& CMyString::operator = (const CMyString& str)
{
    if(this == &str)
        return *this;

    delete []m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);

    return *this;
}




void CMyString::Print()
{
    printf("%s\n", m_pData);
}


void assignment_operator_test()
{
    CMyString s("sdf");
    s.Print();

    CMyString s1(s);
    s1.Print();

    CMyString s2;
    s2 = s1;
    s2.Print();
    s2 = s;
    s2.Print();

}
