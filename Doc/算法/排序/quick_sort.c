#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MIN 10
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

void take_partation()
{

}

void quick_sort(int* a, int l)
{

}

int main(int* argv, int argc)
{

    srand(time(NULL));
    int len = 10;
    int arr[len];
    get_randint_array(arr, len);
    printf("Before Sort: \r\n");
    print_int_array(arr, len);
    printf("After Sort: \r\n");
    print_int_array(arr, len);
}

