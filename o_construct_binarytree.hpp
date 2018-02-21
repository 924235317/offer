#include ".\Utilities\BinaryTree.h"
#include <exception>
#include <cstdio>

// ������7���ؽ�������
// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
// ���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
// 2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
// ͼ2.6��ʾ�Ķ��������������ͷ��㡣

BinaryTreeNode* ConstructCore
(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder
);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(!preorder || !inorder || length <=0)
    {
        return nullptr;
    }

    return ConstructCore(preorder, preorder+length-1,
                         inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore
(
    int* start_preorder, int* end_preorder,
    int* start_inorder, int* end_inorder
)
{
    //Find root value
    int root_value = start_preorder[0];
    BinaryTreeNode* new_tree = new BinaryTreeNode;
    new_tree->m_nValue = root_value;
    new_tree->m_pLeft = new_tree->m_pRight = nullptr;

    //Find left tree length
    int *root_inorder = start_inorder;
    while(root_inorder <= end_inorder && *root_inorder != root_value)
        ++root_inorder;

    if(root_inorder == end_inorder && *root_inorder != root_value)
        return nullptr;


    //construct left child tree
    int left_length = root_inorder - start_inorder;
    int *left_preorder_end = start_inorder + left_length;//left child tree
    if(left_length > 0)
    {
        new_tree->m_pLeft = ConstructCore(start_preorder+1, left_preorder_end,
                                          start_inorder, root_inorder-1);
    }

    //construct right child tree
    if(left_length < end_preorder - start_preorder)
    {
        new_tree->m_pRight = ConstructCore(start_preorder+left_length+1, end_preorder,
                                           root_inorder+1, end_inorder);
    }


    return new_tree;
}


// ====================���Դ���====================
void binary_constructe_Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// ��ͨ������
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8
void binary_constructe_Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    binary_constructe_Test("Test1", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//           /
//          2
//         /
//        3
//       /
//      4
//     /
//    5
void binary_constructe_Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    binary_constructe_Test("Test2", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//             \
//              2
//               \
//                3
//                 \
//                  4
//                   \
//                    5
void binary_constructe_Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    binary_constructe_Test("Test3", preorder, inorder, length);
}

// ����ֻ��һ�����
void binary_constructe_Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    binary_constructe_Test("Test4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3
//         / \     / \
//        4   5   6   7
void binary_constructe_Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    binary_constructe_Test("Test5", preorder, inorder, length);
}

// �����ָ��
void binary_constructe_Test6()
{
    binary_constructe_Test("Test6", nullptr, nullptr, 0);
}

// ������������в�ƥ��
void binary_constructe_Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    binary_constructe_Test("Test7: for unmatched input", preorder, inorder, length);
}

int test_binary_constructe()
{
    binary_constructe_Test1();
    binary_constructe_Test2();
    binary_constructe_Test3();
    binary_constructe_Test4();
    binary_constructe_Test5();
    binary_constructe_Test6();
    binary_constructe_Test7();

    return 0;
}
