void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

void preorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    inorder(root->left);
    inorder(root->right);
}

void postorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << endl;
}
