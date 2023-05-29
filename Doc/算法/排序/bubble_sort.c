#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void bubble_sort(int* a, int l)
{
    for(int i = 0 ; i < l; i ++)
    {
        for(int n = 0; n < l - i; n++)
        {
            if(*(a + n) > *(a + n + 1))
            {
                int temp = *(a + n);
                *(a + n) = *(a + n + 1);
                *(a + n + 1) = temp;
            }

        }
    }
}

int main(int argc, char** argv)
{
    srand(time(NULL));  // 使用当前时间作为种子来生成随机数

    int len = 5;
    int a[len];
    get_randint_array(a, len);
    print_int_array(a, len);

    bubble_sort(a, len);
    print_int_array(a, len);


    printf("%d", a[0]);
    return 0;
}