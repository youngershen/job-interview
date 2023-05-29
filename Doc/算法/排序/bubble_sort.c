#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
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

    bool swapped;
    for(int i = 0 ; i < l - 1; i ++)
    {
        swapped = false;
        for(int n = 0; n < l - i - 1 ; n++)
        {
            if(*(a + n) > *(a + n + 1))
            {
                int temp = *(a + n);
                *(a + n) = *(a + n + 1);
                *(a + n + 1) = temp;
                swapped = true;
            }
        }
        // 如果在一次循环当中没有个元素的位置被交换
        // 那么就说明数组已经有序了, 就不需要接下来的循环了, 所以直接 break
        if(!swapped) break;
    }
}

int main(int argc, char** argv)
{
    srand(time(NULL));  // 使用当前时间作为种子来生成随机数

    int len = 10;
    int a[len];
    get_randint_array(a, len);
    printf("\r\n");
    printf("Before Sort: \r\n\r\n");
    print_int_array(a, len);
    bubble_sort(a, len);

    printf("\r\n");

    printf("After Sort: \r\n\r\n");
    print_int_array(a, len);

    return 0;
}