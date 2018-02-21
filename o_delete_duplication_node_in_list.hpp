// ������18��������ɾ���������ظ��Ľ��
// ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿���磬��ͼ3.4��a�����ظ�
// ��㱻ɾ��֮��������ͼ3.4��b����ʾ��

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
            //����ж��ر��ر���Ҫ
            //��Ϊ�������ֲ�ͬ���������Ҫɾ����ʱ��pre����������Ҫɾ����pre��
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


// ====================���Դ���====================
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

// ĳЩ������ظ���
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

// û���ظ��Ľ��
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

// ����һ�����֮���������н���ֵ����ͬ
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

// ���н���ֵ����ͬ
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

// ���н�㶼�ɶԳ���
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

// �����������֮��������㶼�ɶԳ���
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

// ������ֻ���������ظ��Ľ��
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

// �����ֻ��һ�����
void delete_duplicated_node_in_list_Test8()
{
    ListNode* pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1 };
    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// �����ֻ�������ظ��Ľ��
void delete_duplicated_node_in_list_Test9()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    delete_duplicated_node_in_list_Test("delete_duplicated_node_in_list_Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// ������
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
