#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MIN 10
#define MAX 100

/**

快速排序 一

这里是一个最简单, 最常简的快速排序方法, 也是网络上出现概率最多的版本,
不需要过多解释, 需要注意的就是快速排序是分治法的典型应用, 里面有
一个递归调用, 条件需要注意, 不能写错.

其次就是, 快速排序的核心是 partation 方法至少需要知道两种, 这里是第一种,
quick_sort_2.c 里面是第二种 partaion 的应用

快速排序的核心是找到 pivot 的合理位置, 然后替换, 一直进行下去, 也是分治法
的一种应用, 就是把同类型的问题的规模一直缩小就可以了.

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


// 一个下标交换的 partation
int partation(int * a, int low, int high)
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

    // 在寻找到的 pivot 的位置 index 上
    // 交换 index 与 high 的值
    // 其实就是把 pivot 放到了正确的位置而已

    int temp = * ( a + index + 1);
    *(a + index + 1) = *(a + high);
    *(a + high) = temp;

    return index + 1;
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

