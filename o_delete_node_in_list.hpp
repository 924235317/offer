// ������18��һ������O(1)ʱ��ɾ��������
// ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ����
// ��㡣

#include <cstdio>
#include ".\Utilities\List.h"

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
    if(!pListHead || !pToBeDeleted)
        return;

    ListNode *p1 = *pListHead;
    ListNode *p2 = p1->m_pNext;

    if(p1 == pToBeDeleted)//�ر���Ҫ
    {
        *pListHead = p2;
        return;
    }

    while(p2)
    {
        if(p2 == pToBeDeleted)
        {
            p1->m_pNext = p2->m_pNext;
            return;
        }

        p1 = p2;
        p2 = p2->m_pNext;
    }
}


// ====================���Դ���====================
void delete_node_in_list_Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);

    printf("The result list is: \n");
    PrintList(pListHead);
}

// �������ж����㣬ɾ���м�Ľ��
void delete_node_in_list_Test1()
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

    delete_node_in_list_Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void delete_node_in_list_Test2()
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

    delete_node_in_list_Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
void delete_node_in_list_Test3()
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

    delete_node_in_list_Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void delete_node_in_list_Test4()
{
    ListNode* pNode1 = CreateListNode(1);

    delete_node_in_list_Test(pNode1, pNode1);
}

// ����Ϊ��
void delete_node_in_list_Test5()
{
    delete_node_in_list_Test(nullptr, nullptr);
}

int test_delete_node_in_list()
{
    delete_node_in_list_Test1();
    delete_node_in_list_Test2();
    delete_node_in_list_Test3();
    delete_node_in_list_Test4();
    delete_node_in_list_Test5();

    return 0;
}
