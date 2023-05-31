/*

array 作为最简单的数据结构, 是必须要了解的, 这里
主要复习一下关于数组的特征, 基本的参数, 以及
基本操作的实现.

*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MIN 10
#define MAX 100
#define BUFF_SIZE 10


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

void fill_array(int* a, int len, int d)
{

    for(int i = 0 ; i < len; i ++)
    {
        *(a + i) = d;
    }
}

void fill_array_zero(int* a, int len)
{
    fill_array(a, len, 0);
}


int* init_rand_array(int len)
{
    int * arr = (int*) malloc(sizeof(int) * len);
    get_randint_array(arr, len);
    return arr;
}

int* init_zero_array(int len)
{
    int * arr = (int*) malloc(sizeof(int) * len);
    fill_array_zero(arr, len);
    return arr;
}

// 返回第一个找到的元素的下标
int linear_search(int* arr, int len, int d)
{
    for(int i = 0 ; i< len; i ++)
    {
        if(*(arr + i) == d)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(int* arr, int len)
{

}

int get_element(int* arr, int len, int i)
{
    if( i < 0 || i > len - 1)
    {
        return -1; // 没有找到
    }
    else
    {
        int d = *(arr + i);
        return d;
    }
}

int set_element(int* arr, int len, int i, int d)
{
    if( i < 0 || i > len)
    {
        return -1;
    }
    else
    {
        *(arr + i) = d;
        return 0;
    }
}


void bubble_sort(int* arr, int len)
{
    for(int i = 0; i < len - 1; i ++)
    {

        for(int j = 0; j < len - i - 1; j ++)
        {
            if(*(arr + j) > *(arr + j + 1))
            {
                // swap;
                int temp = *(arr + j);
                *(arr + j) = * (arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int partation(int* arr, int low, int high)
{
    // 关键是找到 pivot
    // 思路怎么又忘了呢, 不是昨天学了一天么
    // 哈哈 最终还是成功的想了起来, 完成了快速排序
    int i = low - 1;
    int pv = *(arr + high);

    for(int j = low; j < high; j ++)
    {
        if(*(arr + j) < pv)
        {
            i += 1;
            int temp = *(arr + i);
            *(arr + i) = *(arr + j);
            *(arr + j) = temp;
        }
    }
    // swap
    int temp = *(arr + i + 1);
    *(arr + i + 1) = *(arr + high);
    *(arr + high) = temp;
    // return pivot
    return i + 1;
}

void quick_sort(int* arr, int low, int high)
{
    if(low < 0 || high < low)
    {
        // break
    }
    else
    {
        // 算法复杂度是 O(log(N))
        int p = partation(arr, low, high);
        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

void merge_sort(int* arr, int len)
{

}

int main(char* argv, int argc)
{
    srand(time(NULL));


    int len = 10;
    int* arr1 = init_rand_array(len);
    int* arr2 = init_zero_array(len);

    // 插入数据
    set_element(arr2, len, 0, 99);
    set_element(arr2, len, len-1, 88);
    quick_sort(arr1, 0, len - 1);
    print_int_array(arr1, len);
}