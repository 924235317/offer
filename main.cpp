#include <iostream>
#include "o_array.hpp"
#include "o_assignment_operator.hpp"
#include "find_duplication.hpp"

using namespace std;

int main()
{
    int arr2d[2][3] = {1,2,3,4,5,6};


    cout << find_num_array2d(arr2d[0], 2, 3, -1) << endl;

    assignment_operator_test();
    test_duplicate_edit();
}
