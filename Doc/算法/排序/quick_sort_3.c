/*

这里实现了一个最简单的非递归实现的快速排序,
用来验证凡是递归都可以通过循环来实现这一
现象.

同时可以通过同一种算法的不同实现来学习一种
算法的核心概念.

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MIN 1
#define MAX 100

void print_int_array(int * a, int l)
{
    for(int i = 0; i < l; i ++)
    {
        printf("%d", *(a+i));

        if( i != l - 1)
        {
            printf(", ");
        }
        else
        {
            printf("\r\n");
        }
    }
}

int get_randint(int min, int max)
{
    int i;
    i = rand() % max + min;  // 生成 10 位随机整数
    return i;
}

void get_randint_array(int* a, int l)
{
    for(int i=0; i < l; i ++)
    {
        int n = get_randint(MIN, MAX);
        *(a+i) = n;
    }
}


// 一个下标交换的 partation
int partation(int * a, int low, int high)
{
}

// 快速排序的非递归版本实现
void quick_sort(int* array, int length)
{

    //当 i 与 j 相等的时候就可以停止循环了
    int i = 0;
    int j = length - 1;
    int pivot = *(array + j);

    int low = i;
    int high = j;

    while(true)
    {
        int p = partation(array, low, high);
        int low = i;
        int high = p - 1;
    }
}

int main(int* argv, int argc)
{

    srand(time(NULL));
    int len = 10;
    int arr[len];
    int low = 0;
    int high = len - 1;
    get_randint_array(arr, len);
    printf("Quick Sort demonstration \r\n");

    printf("\r\n");
    printf("Before Sort: \r\n");

    printf("\r\n");
    print_int_array(arr, len);
    printf("\r\n");

    // quick sort
    quick_sort(arr, low, high);

    printf("After Sort: \r\n");
    printf("\r\n");
    print_int_array(arr, len);
}

