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

class helper
{
public:
    TreeNode<int> *max;
    TreeNode<int> *smax;

    helper(TreeNode<int> *max, TreeNode<int> *smax)
    {
        this->max = max;
        this->smax = smax;
    }
};

helper secondLargest(TreeNode<int> *root)
{
    if (root == NULL)
    {
        helper r(NULL, NULL);
        return r;
    }

    helper ans(root, NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        helper smallAns = secondLargest(root->children[i]);
        if (ans.max -> data < smallAns.max -> data)
        {
            TreeNode<int> *temp = ans.max;
            ans.max = smallAns.max;
            if (ans.smax == NULL && smallAns.smax == NULL)
            {
                ans.smax = temp;
            }
            else if (ans.smax == NULL)
            {
                ans.smax = (temp->data > smallAns.smax->data) ? temp : smallAns.smax;
            }
            else
            {
                if (ans.smax->data < temp->data)
                {
                    ans.smax = temp;
                }
            }
        }
        else
        {
            if (ans.smax == NULL && smallAns.smax == NULL)
            {
                ans.smax = smallAns.max;
            }

            else if (ans.smax == NULL)
            {
                ans.smax = smallAns.max;
            }

            else
            {
                if (ans.smax->data < smallAns.max->data)
                {
                    ans.smax = smallAns.max;
                }
            }
        }
    }

    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    helper ans = secondLargest(root);
    cout << ans.max->data << endl;
    cout << ans.smax->data << endl;
}