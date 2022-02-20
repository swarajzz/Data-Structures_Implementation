// Node with max sum
TreeNode<int> *maxChildSum(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *x = maxChildSum(root->children[i]);
        int xsum = x->data;
        
        for (int i = 0; i < x->children.size(); i++)
        {
            xsum += x->children[i]->data;
        }

        if (xsum > sum)
        {
            ans = x;
            sum = xsum;
        }
    }
    return ans;
}
