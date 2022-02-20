// Second largest in a generic tree
class helper
{
public:
    TreeNode<int> *max;
    TreeNode<int> *smax;

    helper(TreeNode<int> *max, TreeNode<int> *smax)
    {
        this->max = max;
        this->smax = smax;
    }
};

helper secondLargest(TreeNode<int> *root)
{
    if (root == NULL)
    {
        helper r(NULL, NULL);
        return r;
    }

    helper ans(root, NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        helper smallAns = secondLargest(root->children[i]);
        if (ans.max -> data < smallAns.max -> data)
        {
            TreeNode<int> *temp = ans.max;
            ans.max = smallAns.max;
            if (ans.smax == NULL && smallAns.smax == NULL)
            {
                ans.smax = temp;
            }
            else if (ans.smax == NULL)
            {
                ans.smax = (temp->data > smallAns.smax->data) ? temp : smallAns.smax;
            }
            else
            {
                if (ans.smax->data < temp->data)
                {
                    ans.smax = temp;
                }
            }
        }
        else
        {
            if (ans.smax == NULL && smallAns.smax == NULL)
            {
                ans.smax = smallAns.max;
            }

            else if (ans.smax == NULL)
            {
                ans.smax = smallAns.max;
            }

            else
            {
                if (ans.smax->data < smallAns.max->data)
                {
                    ans.smax = smallAns.max;
                }
            }
        }
    }

    return ans;
}
