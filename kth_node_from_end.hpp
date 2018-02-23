// 面试题22：链表中倒数第k个结点
// 题目：输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，
// 本题从1开始计数，即链表的尾结点是倒数第1个结点。例如一个链表有6个结点，
// 从头结点开始它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个结点是
// 值为4的结点。

#include <cstdio>
#include ".\Utilities\List.h"

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
    if(pListHead == nullptr || k == 0)
        return nullptr;

    ListNode *start = pListHead;
    ListNode *end = pListHead;

    for(unsigned int i = 0; i < k; ++i)//这里<k很重要，别弄错,和后面的循环是配套使用的
    {
        if(end == nullptr)
            return nullptr;
        else
            end = end->m_pNext;
    }

    while(end)
    {
        end = end->m_pNext;
        start = start->m_pNext;
    }

    return start;
}

// ====================测试代码====================
// 测试要找的结点在链表中间
void kth_node_from_end_Test1()
{
    printf("=====kth_node_from_end_Test1 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = FindKthToTail(pNode1, 2);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的尾结点
void kth_node_from_end_Test2()
{
    printf("=====kth_node_from_end_Test2 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode* pNode = FindKthToTail(pNode1, 1);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试要找的结点是链表的头结点
void kth_node_from_end_Test3()
{
    printf("=====kth_node_from_end_Test3 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode* pNode = FindKthToTail(pNode1, 5);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试空链表
void kth_node_from_end_Test4()
{
    printf("=====kth_node_from_end_Test4 starts:=====\n");
    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(nullptr, 100);
    PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void kth_node_from_end_Test5()
{
    printf("=====kth_node_from_end_Test5 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(pNode1, 6);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

// 测试输入的第二个参数为0
void kth_node_from_end_Test6()
{
    printf("=====kth_node_from_end_Test6 starts:=====\n");
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = FindKthToTail(pNode1, 0);
    PrintListNode(pNode);

    DestroyList(pNode1);
}

int test_kth_node_from_end()
{
    kth_node_from_end_Test1();
    kth_node_from_end_Test2();
    kth_node_from_end_Test3();
    kth_node_from_end_Test4();
    kth_node_from_end_Test5();
    kth_node_from_end_Test6();

    return 0;
}

