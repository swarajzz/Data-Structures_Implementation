/* Minimum and maximum in a binary tree */

pair<int, int> minMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }

    pair<int, int> leftAns = minMax(root->left);
    pair<int, int> rightAns = minMax(root->right);

    pair<int, int> ans;
    ans.first = min(root->data, min(leftAns.first, rightAns.first));

    ans.second = max(root->data, max(leftAns.second, rightAns.second));

    return ans;
}
