int countNodes(TreeNode<int> *root)
{
    int count = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }

    return count;
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout << countNodes(root) << endl;
}