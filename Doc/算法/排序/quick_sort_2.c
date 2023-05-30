#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MIN 10
#define MAX 100

/**

快速排序 二

这个快速排序, 原理上和 快速排序 一是一样的, 没什么区别.
不同的就是, 这里使用的 partation 方法是双指针循环,
快速排序一 使用的是单指针.

**/

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


// 双指针交换版本的 partation
int partation(int * a, int low, int high)
{
    int pivot = *(a + high);
    int i = low;
    int j = high;

    while( i < high )
    {
        while( *(a + i) < pivot)
        {
            i++;
        }

        while(*(a + j) > pivot)
        {
            j--;
        }

        if(i >= j) return j;

        int temp = * ( a + i);
        *(a + i) = *(a + j);
        *(a + j) = temp;
    }

}

void quick_sort(int* a, int low, int high)
{
    if(low >= 0 && high >= 0 && high > low)
    {
        int pivot = partation(a, low, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
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

