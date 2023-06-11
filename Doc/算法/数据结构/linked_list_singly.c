#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
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
LINKED_LIST push(LINKED_LIST list, int item)
{
    NODE * node = (NODE * ) malloc(sizeof(NODE));
    node->data = item;
    node->next = list;
    return node;
}

// 链表尾部插入
void append(LINKED_LIST list, int item)
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

int get_length(LINKED_LIST list)
{
    NODE * head = list;
    int len = 1;
    while(head->next != NULL)
    {
        len += 1;
        head = head->next;
    }

    return len;
}

// 链表任意位置元素之后插入
int insert(LINKED_LIST list, int pos, int item)
{
    int len = get_length(list);

    if(pos < 0 || pos > len - 1)
    {
        // 插入失败
        return -1;
    }

    // find pos
    NODE * pos_node = list;
    int i = 0;
    while(i != pos && pos_node->next != NULL)
    {
        i += 1;
        pos_node = pos_node->next;
    }

    // create new node
    NODE * new_node = (NODE * ) malloc(sizeof(NODE));
    new_node->data = item;

    // set new node's next
    if(pos_node->next != NULL)
    {
        new_node->next = pos_node->next;
        pos_node->next = new_node;
    }
    else
    {
        new_node->next = NULL;
        pos_node->next = new_node;
    }

    return 0;
}


// 获取链表的最后一个节点
// 复杂度为  O(n)
NODE* get_last_node(LINKED_LIST head)
{
    NODE * node = head;

    while(node->next != NULL)
    {
        node = node->next;
    }
    return node;
}

// 搜索具有某个特定值的节点
// 并返回找到的第一个节点
// 复杂度 O(n)
NODE* search(LINKED_LIST head, int value)
{
    NODE * node = head;

    while(node->next != NULL && node->data != value)
    {
        node = node->next;
    }

    if(node->data == value)
    {
        return node;
    }
    else
    {
        return NULL;
    }
}

NODE * pop_front(LINKED_LIST head)
{

}

NODE * pop_back(LINKED_LIST head)
{

}


/*
 *
 * 从链表中删除某个节点
 * 方法是找到该节点的父节点
 * 将父节点的 next 指针指向 node 的 next
 * 所指向的节点即可
 * 最后需要 free 掉 node 指向的节点
 *
 */
int remove_node(LINKED_LIST head, NODE* node)
{

}

// 删除指定位置的 node 并返回
NODE* remove_index(LINKED_LIST head, int index)
{

}

int main(char* argv, int argc)
{
    srand(time(NULL));
    LINKED_LIST head = init_rand_linked_list(10);
    print_linked_list(head);

    printf("\r\n\r\nPush to linked list\r\n");
    head = push(head, 1000);
    print_linked_list(head);

    printf("\r\n\r\nAppend to linked list\r\n");
    append(head, 1000);
    print_linked_list(head);

    printf("\r\n\r\nGet Length: \r\n");
    int len = get_length(head);
    printf("Length: %d", len);

    printf("\r\n\r\nInsert Linked list:\r\n");
    insert(head,11 , 999);
    print_linked_list(head);

    printf("\r\n\r\nGet last node: \r\n");
    NODE * node = get_last_node(head);
    printf("Last node value is %d\r\n", node->data);

    printf("\r\n\r\nSearch:\r\n");
    NODE * node2 = search(head, 999);
    if(node2 != NULL)
    {
        printf("Search result is %d\r\n", node2->data);
    }
    else
    {
        printf("Search not found\r\n");
    }

}
