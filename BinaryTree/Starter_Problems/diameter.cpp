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

int height(BinaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

// int diameter(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     int option1 = height(root->left) + height(root->right);
//     int option2 = diameter(root->left);
//     int option3 = diameter(root->right);

//     return max(option1, max(option2, option3));
// }

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int height = 1 + max(leftAns.first, rightAns.first);
    int diameter = max(leftAns.first + rightAns.first, max(leftAns.second, rightAns.second));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

int main(){
    BinaryTreeNode<int> * root = takeInputLevelWise();
    pair<int, int> ans = heightDiameter(root);

    cout << "Height :" << ans.first << endl;
    cout << "Diameter :" << ans.second << endl;

}