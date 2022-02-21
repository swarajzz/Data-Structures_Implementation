#include <iostream>
#include "BinaryTreeNode_Class.h"
using namespace std;

void printTree(BinaryTreeNode<int> *root)
{
    cout << root->data;

    if (root->left != NULL)
    {
        printTree(root->left);
    }

    if (root->right != NULL)
    {
        printTree(root->right);
    }
}

int main()
{
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;

    printTree(root);
}