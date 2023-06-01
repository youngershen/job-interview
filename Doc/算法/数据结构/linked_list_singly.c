#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<stdbool.h>
#define MIN 10
#define MAX 100
#define BUFF_SIZE 10

/**
这个文件是一个单链表的实现, 其实就是最简单
最常见的单链表的实现.

包括结构体, 以及相关的若干函数等, 作为快速
入门, 或者复习, 是足够的.

但是如果要详细学习数据结构, 就必须深入
去研究了.
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
    i = rand() % 89 + min;  // 生成 2 位随机整数
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

typedef struct node{

    int data;
    struct node* next;
    int head; // 是否是表头
    int len; // 如果是表头则会记录链表长度

} NODE, *LINKED_LIST;


LINKED_LIST init_rand_linked_list(int len)
{
    // len 表示这个随机单链表的长度

    LINKED_LIST head = (LINKED_LIST)malloc(sizeof(NODE));
    NODE * prev;

    for(int i = 0 ; i < len; i ++)
    {
        if( i == 0 )
        {
            int i = get_randint(MIN, MAX);
            head->data = i;
            prev = head;
        }
        else
        {
            NODE * node = (NODE * ) malloc(sizeof(NODE));
            node->data = get_randint(MIN, MAX);
            prev->next = node;
            prev = node;
        }
    }
    prev->next = NULL;
    return head;
}

void print_linked_list(LINKED_LIST list)
{
    printf("\r\nPrint Linked List :\r\n");
    NODE * node = list;

    do
    {
        if(node->next == NULL)
        {
            printf("%d", node->data);
        }
        else
        {
            printf("%d, ", node->data);
        }
        node = node->next;

    }while( node!= NULL);
}

// 链表头部插入算法
// 直接生成节点, 并将节点的 next
// 指向当前链表的头部即可
// 很明显时间复杂度为 O(1)
LINKED_LIST push_linked_list(LINKED_LIST list, int item)
{
    NODE * node = (NODE * ) malloc(sizeof(NODE));
    node->data = item;
    node->next = list;
    return node;
}

// 链表尾部插入
void append_linked_list(LINKED_LIST list, int item)
{
    NODE * node = (NODE * ) malloc(sizeof(NODE));
    node->data = item;
    node->next = NULL;

    NODE * tail = list;
    while(tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = node;
}

// 链表任意位置的插入
int insert_linked_list(LINKED_LIST list, int pos, int item)
{

}

int main(char* argv, int argc)
{
    srand(time(NULL));
    LINKED_LIST head = init_rand_linked_list(10);
    print_linked_list(head);

    printf("\r\nPush to linked list\r\n");
    head = push_linked_list(head, 1000);
    print_linked_list(head);

    printf("\r\nAppend to linked list\r\n");
    append_linked_list(head, 1000);
    print_linked_list(head);

}
