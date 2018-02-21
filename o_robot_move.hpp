// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

#include <cstdio>

int get_digit_sum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool check(int threshold, int rows, int cols, int r, int c, bool *visited)
{
    if(r >= 0 && r < rows && c >= 0 && c < cols
       && !visited[r*cols+c] &&
       get_digit_sum(r) + get_digit_sum(c) <= threshold)
        return true;

    return false;
}

int moving_count_core(int threshold, int rows, int cols, int r, int c, bool *visited)
{
    int count = 0;
    int cur_pos = r * cols + c;
    if(check(threshold, rows, cols, r, c, visited))
    {
        visited[cur_pos] = true;
        count = 1 + moving_count_core(threshold, rows, cols, r-1, c, visited) +
            moving_count_core(threshold, rows, cols, r+1, c, visited) +
            moving_count_core(threshold, rows, cols, r, c-1, visited) +
            moving_count_core(threshold, rows, cols, r, c+1, visited);
    }

    return count;
}


int movingCount(int threshold, int rows, int cols)
{
    if(threshold < 0 || rows <=0 || cols <= 0)
        return 0;

    bool visited[rows*cols] = {0};
    int count = moving_count_core(threshold, rows, cols, 0, 0, visited);

    return count;
}


// ====================���Դ���====================
void robot_moving_Test(char* robot_moving_TestName, int threshold, int rows, int cols, int expected)
{
    if(robot_moving_TestName != nullptr)
        printf("%s begins: ", robot_moving_TestName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// ������ж���
void robot_moving_Test1()
{
    robot_moving_Test("robot_moving_Test1", 5, 10, 10, 21);
}

// ������ж���
void robot_moving_Test2()
{
    robot_moving_Test("robot_moving_Test2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void robot_moving_Test3()
{
    robot_moving_Test("robot_moving_Test3", 10, 1, 100, 29);
}

// ����ֻ��һ�У��������ܵ������з���
void robot_moving_Test4()
{
    robot_moving_Test("robot_moving_Test4", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void robot_moving_Test5()
{
    robot_moving_Test("robot_moving_Test5", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void robot_moving_Test6()
{
    robot_moving_Test("robot_moving_Test6", 15, 10, 1, 10);
}

// ����ֻ��һ��һ��
void robot_moving_Test7()
{
    robot_moving_Test("robot_moving_Test7", 15, 1, 1, 1);
}

// ����ֻ��һ��һ��
void robot_moving_Test8()
{
    robot_moving_Test("robot_moving_Test8", 0, 1, 1, 1);
}

// �����˲��ܽ�������һ������
void robot_moving_Test9()
{
    robot_moving_Test("robot_moving_Test9", -10, 10, 10, 0);
}

int test_robot_moving()
{
    robot_moving_Test1();
    robot_moving_Test2();
    robot_moving_Test3();
    robot_moving_Test4();
    robot_moving_Test5();
    robot_moving_Test6();
    robot_moving_Test7();
    robot_moving_Test8();
    robot_moving_Test9();

    return 0;
}
