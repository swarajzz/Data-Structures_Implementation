// Check if a node is present in a binary tree
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return x;
    }

    return isNodePresent(root -> left, x) || isNodePresent(root -> right, x);
}
