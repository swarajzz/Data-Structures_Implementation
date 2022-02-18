#include <iostream>
#include <queue>
#include "TreeNode.h"

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root's data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

int countNodes(TreeNode<int> *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int count = 1;
    for (int i = 0; i < head->children.size(); i++)
    {
        count += countNodes(head->children[i]);
    }
    return count;
}

int sumNodes(TreeNode<int> *head)
{
    if (head == NULL)
    {
        return 0;
    }
    int sum = head->data;
    for (int i = 0; i < head->children.size(); i++)
    {
        sum += sumNodes(head->children[i]);
    }
    return sum;
}

int maxOfNodes(TreeNode<int> *head)
{
    int maxi = head->data;
    for (int i = 0; i < head->children.size(); i++)
    {
        maxi = max(maxi, maxOfNodes(head->children[i]));
    }
    return maxi;
}

// Height of a tree
int heightTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        height = max(height, heightTree(root->children[i]));
    }

    return height + 1;
}

void printAtLevelK(TreeNode<int> *root, int k)
{
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    cout << countNodes(root) << endl;
    cout << sumNodes(root) << endl;
    cout << maxOfNodes(root) << endl;
    cout << heightTree(root) << endl;
    printAtLevelK(root, 2);
}