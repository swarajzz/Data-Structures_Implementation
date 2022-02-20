// Next larger element than x
TreeNode<int> *nextLarger(TreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    TreeNode<int> *ans = NULL;
    if (root->data > x)
    {
        ans = root;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp = nextLarger(root->children[i], x);
        if (temp == NULL)
        {
            continue;
        }
        else if (ans == NULL || temp->data < ans->data)
        {
            ans = temp;
        }
    }
    return ans;
}
