#include <cstdio>

void swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int partition(int *numbers, int start, int end)
{
    int mid_value = numbers[start];

    int mid = start;
    int left = start + 1;
    for(; left <= end; ++left)
    {
        if(numbers[left] < mid_value)
            swap(&numbers[left], &numbers[++mid]);
    }

    swap(&numbers[start], &numbers[mid]);
    return mid;
}

int quick_sort(int *numbers, int start, int end)
{
    if(!numbers || start >= end)
        return -1;

    int mid = partition(numbers, start, end);
    printf("mid: %d\n", mid);
    quick_sort(numbers, start, mid-1);
    quick_sort(numbers, mid+1, end);
    return 0;
}



int test_partition()
{
    //int a[] = {9,4,5,21,2,3,5,5,6,23};
    int a[] = {9,4,5};
    int x = partition(a, 0, 2);

    for(int i = 0; i < 2; ++i)
    {
        printf("%d\n", a[i]);
    }

    return 0;
}

void test_quick_sort()
{
    int a[] = {9,4,5,21,2,3,5,5,6,23};
    //int a[] = {9,5,4,21,2,3,5,6};
    int x = quick_sort(a, 0, 9);

    for(int i = 0; i < 10 ; ++i)
    {
        printf("%d\n", a[i]);
    }
}
