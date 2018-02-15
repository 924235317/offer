// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include "Utilities\List.h"
#include <stack>

void PrintListReversingly_Iteratively(ListNode* pHead)
{
    if(!pHead)
        return;

    std::stack<ListNode *> st;

    ListNode *p = pHead;
    while(p)
    {
        st.push(p);
        p = p->m_pNext;
    }

    while(!st.empty())
    {
        ListNode *pp = st.top();
        printf("%d\n", pp->m_nValue);
        st.pop();
    }
}

void PrintListReversingly_Test(ListNode* pHead)
{
    PrintList(pHead);
    PrintListReversingly_Iteratively(pHead);
    printf("\n");
    //PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void PrintListReversingly_Test1()
{
    printf("\nTest1 begins.\n");

    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    PrintListReversingly_Test(pNode1);

    DestroyList(pNode1);
}

// 只有一个结点的链表: 1
void PrintListReversingly_Test2()
{
    printf("\nTest2 begins.\n");

    ListNode* pNode1 = CreateListNode(1);

    PrintListReversingly_Test(pNode1);

    DestroyList(pNode1);
}

// 空链表
void PrintListReversingly_Test3()
{
    printf("\nTest3 begins.\n");

    PrintListReversingly_Test(nullptr);
}

int test_PrintListReversingly()
{
    PrintListReversingly_Test1();
    PrintListReversingly_Test2();
    PrintListReversingly_Test3();

    return 0;
}
