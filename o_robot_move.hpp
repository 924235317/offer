// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

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


// ====================测试代码====================
void robot_moving_Test(char* robot_moving_TestName, int threshold, int rows, int cols, int expected)
{
    if(robot_moving_TestName != nullptr)
        printf("%s begins: ", robot_moving_TestName);

    if(movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void robot_moving_Test1()
{
    robot_moving_Test("robot_moving_Test1", 5, 10, 10, 21);
}

// 方格多行多列
void robot_moving_Test2()
{
    robot_moving_Test("robot_moving_Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void robot_moving_Test3()
{
    robot_moving_Test("robot_moving_Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void robot_moving_Test4()
{
    robot_moving_Test("robot_moving_Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void robot_moving_Test5()
{
    robot_moving_Test("robot_moving_Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void robot_moving_Test6()
{
    robot_moving_Test("robot_moving_Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void robot_moving_Test7()
{
    robot_moving_Test("robot_moving_Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void robot_moving_Test8()
{
    robot_moving_Test("robot_moving_Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
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
