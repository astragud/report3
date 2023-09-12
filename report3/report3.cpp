#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

typedef struct TreeNode
{
    int data;
    struct TreeNode* left, * right;
} TreeNode;

//       1
//   2       7
// 3   6  8    9
//4 5        10 11
TreeNode n8 = { 4, NULL, NULL };
TreeNode n9 = { 5, NULL, NULL };
TreeNode n10 = { 10, NULL, NULL };
TreeNode n11 = { 11, NULL, NULL };
TreeNode n5 = { 6, NULL, NULL };
TreeNode n6 = { 8, NULL, NULL };
TreeNode n7 = { 9,  &n10, &n11 };

TreeNode n4 = { 3, &n8, &n9 };
TreeNode n3 = { 7, &n6, &n7 };
TreeNode n2 = { 2, &n4, &n5 };
TreeNode n1 = { 1, &n2, &n3 };
TreeNode* root = &n1;

//전위
void preorder_tree(TreeNode* root)
{
    if (root)
    {
        printf("[%d] ", root->data); // 노드 방문
        preorder_tree(root->left); // 왼쪽서브트리 순회
        preorder_tree(root->right); // 오른쪽서브트리 순회
    }
}

//중위
void inorder_tree(TreeNode* root)
{
    if (root)
    {
        inorder_tree(root->left); // 왼쪽서브트리 순회
        printf("[%d] ", root->data); // 노드 방문
        inorder_tree(root->right); // 오른쪽서브트리 순회
    }
}

//후위
void postorder_tree(TreeNode* root)
{
    if (root)
    {
        postorder_tree(root->left); // 왼쪽 서브 트리 순회
        postorder_tree(root->right); // 오른쪽 서브 트리 순회
        printf("[%d] ", root->data); // 노드 방문
    }
}

//전위
void preorder_array(int tree[], int index)
{
    if (index >= SIZE || tree[index] == -1 || tree[index] == NULL)
    {
        return;
    }
    printf("[%d] ", tree[index]); // 현재 노드를 처리
    preorder_array(tree, 2 * index + 1); // 왼쪽 서브트리를 재귀적으로 순회
    preorder_array(tree, 2 * index + 2); // 오른쪽 서브트리를 재귀적으로 순회
}

//중위
void inorder_array(int tree[], int index)
{
    if (index >= SIZE || tree[index] == -1 || tree[index] == NULL)
    {
        return;
    }
   
    inorder_array(tree, 2 * index + 1); // 왼쪽 서브트리를 재귀적으로 순회
    printf("[%d] ", tree[index]); // 현재 노드를 처리합니다
    inorder_array(tree, 2 * index + 2); // 오른쪽 서브트리를 재귀적으로 순회
}

//후위
void postorder_array(int tree[], int index)
{
    if (index >= SIZE || tree[index] == -1 || tree[index] == NULL)
    {
        return;
    }
    postorder_array(tree, 2 * index + 1); // 왼쪽 서브트리를 재귀적으로 순회
    postorder_array(tree, 2 * index + 2); // 오른쪽 서브트리를 재귀적으로 순회  
    printf("[%d] ", tree[index]); // 현재 노드를 처리
}

int main()
{
    int tree[SIZE] = { 1, 2, 7, 3, 6, 8, 9, 4, 5, NULL, NULL, NULL, NULL, 10, 11};

    printf("<Linked Tree>\n");
    printf("1.전위 순회\n");
    preorder_tree(root);
    printf("\n\n");
    printf("2.중위 순회\n");
    inorder_tree(root);
    printf("\n\n");
    printf("3.후위 순회\n");
    postorder_tree(root);
    printf("\n\n");

    printf("<Array Tree>\n");
    printf("1.전위 순회\n");
    preorder_array(tree, 0);
    printf("\n\n");
    printf("2.중위 순회\n");
    inorder_array(tree, 0);
    printf("\n\n");
    printf("3.후위 순회\n");
    postorder_array(tree, 0);
    printf("\n\n");
    return 0;
}