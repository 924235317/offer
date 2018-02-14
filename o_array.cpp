#include "o_array.hpp"

bool find_num_array2d(int *arr2d, int row, int col, int target)
{
    bool res = false;

    int r = 0;
    int c = col - 1;
    while(r < row && c >= 0)
    {
        int conner = arr2d[r*col + c];
        cout << conner << endl;
        if(conner == target)
        {
            res = true;
            break;
        }
        else if(conner < target)
            r++;
        else
            c--;
    }

    return res;
}






