// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

#include <stdio.h>

struct BinaryTreeNode_
{
    int                    m_nValue;
    BinaryTreeNode_*        m_pLeft;
    BinaryTreeNode_*        m_pRight;
    BinaryTreeNode_*        m_pParent;
};

BinaryTreeNode_* GetNext(BinaryTreeNode_* pNode)
{
    if(!pNode)
        return nullptr;

    BinaryTreeNode_ *next = nullptr;


    if(pNode->m_pRight)//has right child node
    {
        next = pNode->m_pRight;
        while(next->m_pLeft)
            next = next->m_pLeft;
    }
    else if(pNode->m_pParent)//dont have right child node, if is parents node's left child
    {
        BinaryTreeNode_ *parent = pNode->m_pParent;
        BinaryTreeNode_ *current = pNode;
        while(parent && current == parent->m_pRight)
        {
            current = parent;
            parent = parent->m_pParent;
        }
        next = parent;
    }
    return next;
}

BinaryTreeNode_* CreateBinaryTreeNode_(int value)
{
    BinaryTreeNode_* pNode = new BinaryTreeNode_();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode_* pParent, BinaryTreeNode_* pLeft, BinaryTreeNode_* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;

        if(pLeft != nullptr)
            pLeft->m_pParent = pParent;
        if(pRight != nullptr)
            pRight->m_pParent = pParent;
    }
}

void PrintTreeNode(BinaryTreeNode_* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);

        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else
            printf("left child is null.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else
            printf("right child is null.\n");
    }
    else
    {
        printf("this node is null.\n");
    }

    printf("\n");
}

void PrintTree(BinaryTreeNode_* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            PrintTree(pRoot->m_pLeft);

        if(pRoot->m_pRight != nullptr)
            PrintTree(pRoot->m_pRight);
    }
}

void DestroyTree(BinaryTreeNode_* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode_* pLeft = pRoot->m_pLeft;
        BinaryTreeNode_* pRight = pRoot->m_pRight;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}

// ====================测试代码====================
void GetNext_Test(char* testName, BinaryTreeNode_* pNode, BinaryTreeNode_* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    BinaryTreeNode_* pNext = GetNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void GetNext_Test1_7()
{
    BinaryTreeNode_* pNode8 = CreateBinaryTreeNode_(8);
    BinaryTreeNode_* pNode6 = CreateBinaryTreeNode_(6);
    BinaryTreeNode_* pNode10 = CreateBinaryTreeNode_(10);
    BinaryTreeNode_* pNode5 = CreateBinaryTreeNode_(5);
    BinaryTreeNode_* pNode7 = CreateBinaryTreeNode_(7);
    BinaryTreeNode_* pNode9 = CreateBinaryTreeNode_(9);
    BinaryTreeNode_* pNode11 = CreateBinaryTreeNode_(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    GetNext_Test("Test1", pNode8, pNode9);
    GetNext_Test("Test2", pNode6, pNode7);
    GetNext_Test("Test3", pNode10, pNode11);
    GetNext_Test("Test4", pNode5, pNode6);
    GetNext_Test("Test5", pNode7, pNode8);
    GetNext_Test("Test6", pNode9, pNode10);
    GetNext_Test("Test7", pNode11, nullptr);

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void GetNext_Test8_11()
{
    BinaryTreeNode_* pNode5 = CreateBinaryTreeNode_(5);
    BinaryTreeNode_* pNode4 = CreateBinaryTreeNode_(4);
    BinaryTreeNode_* pNode3 = CreateBinaryTreeNode_(3);
    BinaryTreeNode_* pNode2 = CreateBinaryTreeNode_(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    GetNext_Test("Test8", pNode5, nullptr);
    GetNext_Test("Test9", pNode4, pNode5);
    GetNext_Test("Test10", pNode3, pNode4);
    GetNext_Test("Test11", pNode2, pNode3);

    DestroyTree(pNode5);
}

//        2
//         3
//          4
//           5
void GetNext_Test12_15()
{
    BinaryTreeNode_* pNode2 = CreateBinaryTreeNode_(2);
    BinaryTreeNode_* pNode3 = CreateBinaryTreeNode_(3);
    BinaryTreeNode_* pNode4 = CreateBinaryTreeNode_(4);
    BinaryTreeNode_* pNode5 = CreateBinaryTreeNode_(5);

    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    GetNext_Test("Test12", pNode5, nullptr);
    GetNext_Test("Test13", pNode4, pNode5);
    GetNext_Test("Test14", pNode3, pNode4);
    GetNext_Test("Test15", pNode2, pNode3);

    DestroyTree(pNode2);
}

void GetNext_Test16()
{
    BinaryTreeNode_* pNode5 = CreateBinaryTreeNode_(5);

    GetNext_Test("Test16", pNode5, nullptr);

    DestroyTree(pNode5);
}

int test_next_node_in_binarytrees()
{
    GetNext_Test1_7();
    GetNext_Test8_11();
    GetNext_Test12_15();
    GetNext_Test16();
}
