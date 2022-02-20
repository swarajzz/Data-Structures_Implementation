#include <iostream>
#include "../TreeNode.h"
#include <climits>
#include <queue>

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

int countNodes(TreeNode<int> *root)
{
    int count = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }

    return count;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout << countNodes(root) << endl;
}