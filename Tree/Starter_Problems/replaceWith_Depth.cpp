// Replace each node with its depth value
void helper(TreeNode<int> *root, int depth)
{
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        helper(root->children[i], depth + 1);
    }
}

void replaceWithDepth(TreeNode<int> *root)
{
    int depth = 0;
    helper(root, depth);
}
