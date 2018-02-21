// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
// A B T G
// C F C S
// J D E H

#include <cstdio>
#include <string>
#include <stack>

using namespace std;

bool hasPathCore(const char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
    if(str[pathLength] == '\0')
        return true;

    bool has_path = false;
    int cur_pos = row * cols + col;
    if(row >=0 && row < rows && col >=0 && col <cols &&//��һ�о���Ϊ��ȷ������Խ��
       matrix[cur_pos] == str[pathLength] && !visited[cur_pos])
    {
        ++pathLength;
        visited[cur_pos] = true;

        has_path = hasPathCore(matrix, rows, cols, row-1, col, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row, col-1, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row+1, col, str, pathLength, visited)
            || hasPathCore(matrix, rows, cols, row, col+1, str, pathLength, visited);

        if(!has_path)
        {
            --pathLength;
            visited[cur_pos] = false;
        }
    }

    return has_path;
}

bool hasPath(const char* matrix, int rows, int cols, const char* str)
{
    if(!matrix || rows < 1 || cols < 1 || !str)
        return false;

    bool visited[rows*cols] = {0};
    int path_length = 0;
    for(int r = 0; r < rows; ++r)
    {
        for(int c = 0; c < cols; ++c)
        {
            if(hasPathCore(matrix, rows, cols, r, c, str, path_length, visited))
                return true;
        }
    }
    return false;
}

// ====================���Դ���====================
void stringpath_in_matrix_Test(const char* stringpath_in_matrix_TestName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(stringpath_in_matrix_TestName != nullptr)
        printf("%s begins: ", stringpath_in_matrix_TestName);

    if(hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//ABTG
//CFCS
//JDEH

//BFCE
void stringpath_in_matrix_Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test1", (const char*) matrix, 3, 4, str, true);
}

//ABCE
//SFCS
//ADEE

//SEE
void stringpath_in_matrix_Test2()
{
    const char* matrix = "ABCESFCSADEE";
    const char* str = "SEE";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test2", (const char*) matrix, 3, 4, str, true);
}

//ABTG
//CFCS
//JDEH

//ABFB
void stringpath_in_matrix_Test3()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "ABFB";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test3", (const char*) matrix, 3, 4, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SLHECCEIDEJFGGFIE
void stringpath_in_matrix_Test4()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SLHECCEIDEJFGGFIE";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test4", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEM
void stringpath_in_matrix_Test5()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEM";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test5", (const char*) matrix, 5, 8, str, true);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEEJIGOEM
void stringpath_in_matrix_Test6()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEEJIGOEM";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test6", (const char*) matrix, 5, 8, str, false);
}

//ABCEHJIG
//SFCSLOPQ
//ADEEMNOE
//ADIDEJFM
//VCEIFGGS

//SGGFIECVAASABCEHJIGQEMS
void stringpath_in_matrix_Test7()
{
    const char* matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char* str = "SGGFIECVAASABCEHJIGQEMS";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test7", (const char*) matrix, 5, 8, str, false);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAA
void stringpath_in_matrix_Test8()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAA";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test8", (const char*) matrix, 3, 4, str, true);
}

//AAAA
//AAAA
//AAAA

//AAAAAAAAAAAAA
void stringpath_in_matrix_Test9()
{
    const char* matrix = "AAAAAAAAAAAA";
    const char* str = "AAAAAAAAAAAAA";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test9", (const char*) matrix, 3, 4, str, false);
}

//A

//A
void stringpath_in_matrix_Test10()
{
    const char* matrix = "A";
    const char* str = "A";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test10", (const char*) matrix, 1, 1, str, true);
}

//A

//B
void stringpath_in_matrix_Test11()
{
    const char* matrix = "A";
    const char* str = "B";

    stringpath_in_matrix_Test("stringpath_in_matrix_Test11", (const char*) matrix, 1, 1, str, false);
}

void stringpath_in_matrix_Test12()
{
    stringpath_in_matrix_Test("stringpath_in_matrix_Test12", nullptr, 0, 0, nullptr, false);
}

int test_stringpath_in_matrix()
{
    stringpath_in_matrix_Test1();
    stringpath_in_matrix_Test2();
    stringpath_in_matrix_Test3();
    stringpath_in_matrix_Test4();
    stringpath_in_matrix_Test5();
    stringpath_in_matrix_Test6();
    stringpath_in_matrix_Test7();
    stringpath_in_matrix_Test8();
    stringpath_in_matrix_Test9();
    stringpath_in_matrix_Test10();
    stringpath_in_matrix_Test11();
    stringpath_in_matrix_Test12();

    return 0;
}
