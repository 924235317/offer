// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

#include <cstdio>
#include "./Utilities/list.h"

ListNode* MeetingNode(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;

    ListNode *slow = pHead;
    ListNode *quick = pHead;

    while(slow && quick)
    {
        slow = slow->m_pNext;
        quick = quick->m_pNext;

        if(quick != nullptr)
            quick = quick->m_pNext;

        if(slow == quick)
            return slow;
    }
    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if(pHead == nullptr)
        return nullptr;

    ListNode *meet_node = MeetingNode(pHead);

    if(meet_node == nullptr)
        return nullptr;
    else
        cout << "meet" << endl;
    cout << "meet value: " << (int)meet_node->m_nValue << endl;

    ListNode *tmp = meet_node->m_pNext;//这里要注意，必须是next 否则下面的循环直接就终止了
    int num_of_loop = 1;//最少是一个，不能从零开始！！！！！！1
    while(tmp != meet_node)
    {
        ++num_of_loop;
        tmp = tmp->m_pNext;
    }
    cout << "num: " << num_of_loop << endl;

    ListNode *entry = pHead;
    ListNode *pos = pHead;
    for(int i = 0; i < num_of_loop; ++i)
        pos = pos->m_pNext;

    while(pos != entry)
    {
        pos = pos->m_pNext;
        entry = entry->m_pNext;
    }

    return entry;
}

    // ==================== entry_node_list_loop_Test Code ====================
void entry_node_list_loop_Test(char* entry_node_list_loop_TestName, ListNode* pHead, ListNode* entryNode)
{
    if(entry_node_list_loop_TestName != nullptr)
        printf("%s begins: ", entry_node_list_loop_TestName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// A list has a node, without a loop
void entry_node_list_loop_Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    entry_node_list_loop_Test("entry_node_list_loop_Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void entry_node_list_loop_Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    entry_node_list_loop_Test("entry_node_list_loop_Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop
void entry_node_list_loop_Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode3);

    entry_node_list_loop_Test("entry_node_list_loop_Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
void entry_node_list_loop_Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode1);

    entry_node_list_loop_Test("entry_node_list_loop_Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop
void entry_node_list_loop_Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode5);

    entry_node_list_loop_Test("entry_node_list_loop_Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop
void entry_node_list_loop_Test6()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    entry_node_list_loop_Test("entry_node_list_loop_Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void entry_node_list_loop_Test7()
{
    entry_node_list_loop_Test("entry_node_list_loop_Test7", nullptr, nullptr);
}

int test_entry_node_list_loop()
{
    entry_node_list_loop_Test1();
    entry_node_list_loop_Test2();
    entry_node_list_loop_Test3();
    entry_node_list_loop_Test4();
    entry_node_list_loop_Test5();
    entry_node_list_loop_Test6();
    entry_node_list_loop_Test7();

    return 0;
}

