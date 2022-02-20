// Search element in a generic tree
bool containsX(TreeNode<int> *root, int x)
{
    if (root->data == x)
    {
        return true;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        if (containsX(root->children[i], x) == true)
        {
            return true;
        }
    }

    return false;
}
