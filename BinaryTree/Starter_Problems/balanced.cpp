/* Is the binary tree balanced */

// int height(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return 0;
//     }

//     return 1 + height(root->left) + height(root->right);
// }

// bool isBalanced(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }

//     int lh = height(root->left);
//     int rh = height(root->right);

//     if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
//     {
//         return true;
//     }

//     return false;
// }

pair<int, bool> heightBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, bool> ans;
        ans.first = 0;
        ans.second = true;
        return ans;
    }

    pair<int, bool> leftAns = heightBalanced(root->left);
    pair<int, bool> rightAns = heightBalanced(root->right);

    int height = 1 + max(leftAns.first, rightAns.first);
    bool balanced = false;
    if (abs(leftAns.first - rightAns.first) <= 1 && leftAns.second &&& rightAns.second)
    {
        balanced = true;
    }

    pair<int, bool> ans;
    ans.first = height;
    ans.second = balanced;

    return ans;
}
