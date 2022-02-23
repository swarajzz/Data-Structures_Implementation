int sumNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + sumNodes(root->left) + sumNodes(root->right);
}
