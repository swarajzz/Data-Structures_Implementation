#include <iostream>
#include "../BinaryTreeNode_Class.h"
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

int sumNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + sumNodes(root->left) + sumNodes(root->right);
}

int main(){
    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << sumNodes(root);
}