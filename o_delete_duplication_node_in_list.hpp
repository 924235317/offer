// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。

#include <cstdio>
#include "./Utilities/list.h"

void DeleteDuplication(ListNode** pHead)
{
    if(!pHead || !*pHead)
        return;

    ListNode *new_head = CreateListNode(-1);
    new_head->m_pNext = *pHead;
    ListNode *node = *pHead;
    ListNode *node_next = node->m_pNext;
    ListNode *node_pre = new_head;


    bool need_delete = false;
    while(node_next)
    {
        if(node->m_nValue == node_next->m_nValue)
        {
            node = node_next;
            node_next = node_next->m_pNext;
            node_pre->m_pNext = node_next;
            need_delete = true;
        }
        else
        {
            //这个判断特别特别重要
            //因为这是两种不同的情况，需要删除的时候，pre不动，不需要删除，pre动
            if(!need_delete)
            {
                node_pre = node;
            }
            else
                need_delete = false;

            node = node_next;
            node_next = node_next->m_pNext;
        }
    }

    *pHead = new_head->m_pNext;
}


// ====================测试代码====================
void delete_duplicated_node_in_list_Test(char* delete_duplicated_node_in_list_TestName, ListNode** pHead, int* expectedValues, int expectedLength)
{
    if(delete_duplicated_node_in_list_TestName != nullptr)
        printf("%s begins: ", delete_duplicated_node_in_list_TestName);

    DeleteDuplication(pHead);

    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != nullptr && index < expectedLength)
    {
        if(pNode->m_nValue != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if(pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
    {
        printf("FAILED. : %d, %d\n", index, expectedLength);
        PrintList(*pHead);
    }

}

// 某些结点是重复的
void delete_duplicated_node_in_list_Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 5 };
    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 没有重复的结点
void delete_duplicated_node_in_list_Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 除了一个结点之外其他所有结点的值都相同
void delete_duplicated_node_in_list_Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2 };
    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 所有结点的值都相同
void delete_duplicated_node_in_list_Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(1);
    ListNode* pNode5 = CreateListNode(1);
    ListNode* pNode6 = CreateListNode(1);
    ListNode* pNode7 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test4", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 所有结点都成对出现
void delete_duplicated_node_in_list_Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(2);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(3);
    ListNode* pNode7 = CreateListNode(4);
    ListNode* pNode8 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test5", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 除了两个结点之外其他结点都成对出现
void delete_duplicated_node_in_list_Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(4);
    ListNode* pNode7 = CreateListNode(5);
    ListNode* pNode8 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2, 4 };
    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 链表中只有两个不重复的结点
void delete_duplicated_node_in_list_Test7()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2 };
    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有一个结点
void delete_duplicated_node_in_list_Test8()
{
    ListNode* pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1 };
    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// 结点中只有两个重复的结点
void delete_duplicated_node_in_list_Test9()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// 空链表
void delete_duplicated_node_in_list_Test10()
{
    ListNode* pHead = nullptr;

    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test10", &pHead, nullptr, 0);
}

int test_delete_duplicated_node_in_list()
{
    delete_duplicated_node_in_list_Test1();
    delete_duplicated_node_in_list_Test2();
    delete_duplicated_node_in_list_Test3();
    delete_duplicated_node_in_list_Test4();
    delete_duplicated_node_in_list_Test5();
    delete_duplicated_node_in_list_Test6();
    delete_duplicated_node_in_list_Test7();
    delete_duplicated_node_in_list_Test8();
    delete_duplicated_node_in_list_Test9();
    delete_duplicated_node_in_list_Test10();

    return 0;
}
