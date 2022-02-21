void mirror(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    root *temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}