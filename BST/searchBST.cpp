#include <iostream>
#include "../BinaryTree/BinaryTreeNode_Class.h"
#include <queue>
using namespace std;

// Take input level-wise
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root's data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int leftChildData;
        cout << "Enter left child data of " << front->data << endl;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(leftChild);
            front->left = leftChild;
        }

        int rightChildData;
        cout << "Enter right child data of " << front->data << endl;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(rightChild);
            front->right = rightChild;
        }
    }

    return root;
}

int searchBST(BinaryTreeNode<int> *root, int target)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == target)
    {
        return true;
    }

    if(root -> data > target){
        return searchBST(root -> left, target);
    }

    if(root -> data <= target){
       return searchBST(root -> right, target);
    }

    return false;
}

int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << searchBST(root, 2);
}