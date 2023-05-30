#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
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

//  两个下标交换的 partation
int partation2(int * a, int low, int high)
{
    int left = low;
    int right = high;
    int pivot = *(a + high);


    while(low < high)
    {
        while(*(a + left) < pivot)
            left+=1;

        while(*(a + right) > pivot)
            right -= 1;


        if(left >= right)
        {
            printf("found\r\n");
            return right;
        }

        printf("swap\r\n");
        int temp = *(a + left);
        *(a + left) = *(a + right);
        *(a + right) = temp;
    }

}

// 一个下标交换的 partation
int partation1(int * a, int low, int high)
{
    // pivot 的位置
    int index = low - 1;
    // 取数组的末尾值为 pivot
    // 这个时候 high 即为 pivot 的下标
    // 最后交换的时候 使用 high 与实际的位置的值进行交换
    int pivot = *(a + high);

    // 在循环中进行比较和替换
    for(int i = low; i < high ; i ++)
    {
        if(*(a + i) < pivot)
        {
            // 只要当前的值小于 pivot, 那么位置就自增一
            index += 1;
            int temp = *(a + index);
            *(a + index) = * (a + i);
            *(a + i) = temp;
        }
    }

    int temp = * ( a + index + 1);
    *(a + index + 1) = *(a + high);
    *(a + high) = temp;

    return index + 1;
}

void quick_sort(int* a, int low, int high)
{
    if(low >= 0 && high >= 0 && high > low)
    {
        int pivot = partation1(a, low, high);
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

