#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MIN 10
#define MAX 100

/**

简介 :

冒牌排序是一种不稳定的排序算法，它的基本思想是通过比较相邻的元素，
将较大的元素逐步向右移动，直到整个序列有序。

冒牌排序的时间复杂度取决于输入数据的规模和序列的起始状态。

对于冒牌排序算法，最坏情况下的时间复杂度为 O(n^2),这是因为在每次迭代中，
需要将当前未排序部分的最大元素移动到已排序部分的末尾，这将花费 O(n)的时间。
因此，当输入数据的规模很大时，冒牌排序的时间复杂度将变得非常高。

实际上，冒牌排序的平均时间复杂度为 O(nlogn),这是因为在每次迭代中，
最多需要移动 n-1 个元素，而且大多数情况是只需要移动 1 个元素。
因此，冒牌排序算法在处理大规模数据时的性能可能会非常好。

需要注意的是，冒牌排序是一种不稳定的排序算法，
因此它不适用于需要保证排序稳定性的情况。
如果需要保证排序稳定性，可以考虑使用其他的排序算法，例如快速排序或归并排序等。

时间复杂度:

最好 : O(n)
最坏 : O(n^2)
平局 : O(n^2)

具体的算法为因为冒泡排序需要循环 n - 1 次,
在 n - 1 次中需要循环的次数数依次为 (n-1) (n-2) .... 1
实际上就是  1 到  n - 1 次, 所以进行计算得出的时间复杂度就为

1 + 2 + 3 + .... (n-1)

使用高斯法合并之后就是 n * (n - 1) / 2 = (n^2 - n) / 2
可以看出比重最高的一项就是 n^2 了,

空间复杂度:

O(1)

因为没有辅助空间的使用, 所以空间复杂度为 O(1)

参考文档:

https://www.geeksforgeeks.org/bubble-sort/
https://www.geeksforgeeks.org/time-and-space-complexity-analysis-of-bubble-sort/

其他:

geeksforgeeks 的文档中还有说到使用递归求解冒泡排序, 也有其他的冒泡排序的变种,
这个可以慢慢研究, 这里只实现了最简单的一个冒泡排序算法.

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
    print_int_array(a, len);

    bubble_sort(a, len);
    print_int_array(a, len);

    return 0;
}