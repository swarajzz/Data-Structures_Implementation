// Total number of nodes
int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int count = 1;
    count += numNodes(root->left);
    count += numNodes(root->right);

    return count;

    // return 1 + numNodes(root -> left) + numNodes(root -> right);
}
