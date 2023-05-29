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

void take_partation(int * a, int low, int high)
{
    // pivot 的位置
    int index = low - 1;
    // 取数组的末尾值为 pivot
    int pivot = *(a + high);

    // 在循环中进行比较和替换
    for(int i = low; i < high ; i ++)
    {
        if(*(a + i) < pivot)
        {
            // 只要当前的值小于 pivot, 那么位置就自增一
            index += 1;
        }
    }

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

    printf("\r\n");
    printf("Before Sort: \r\n");

    printf("\r\n");
    print_int_array(arr, len);
    printf("\r\n");

    printf("After Sort: \r\n");
    printf("\r\n");
    print_int_array(arr, len);
}

