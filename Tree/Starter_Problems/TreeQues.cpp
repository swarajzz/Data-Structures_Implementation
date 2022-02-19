#include "TreeNode.h"
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
    if (root == NULL)
    {
        return 0;
    }
    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }
    return count;
}

// Total number of nodes in a generic tree
int sumNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumNodes(root->children[i]);
    }
    return sum;
}

// Maximum node in a generic tree
int maxOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int maxi = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        maxi = max(maxi, maxOfNodes(root->children[i]));
    }
    return maxi;
}

// Height of a generic tree
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

// Print tree at level k or depth k
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
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

// Print leaf nodes in a generic tree
int leafNodes(TreeNode<int> *root)
{
    int leaf = 0;
    if (root->children.empty())
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        leaf += leafNodes(root->children[i]);
    }

    return leaf;
}

TreeNode<int> *maxChild(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *x = maxChild(root->children[i]);
        int xsum = x->data;
        for (int i = 0; i < x->children.size(); i++)
        {
            xsum += x->children[i]->data;
        }

        if (xsum > sum)
        {
            sum = xsum;
            ans = x;
        }
    }
    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    // cout << countNodes(root) << endl;
    // cout << sumNodes(root) << endl;
    // cout << maxOfNodes(root) << endl;
    // cout << heightTree(root) << endl;
    // printAtLevelK(root, 2);
    // cout << endl;
    // cout << leafNodes(root) << endl;
    cout << maxChild(root) -> data << endl;
}