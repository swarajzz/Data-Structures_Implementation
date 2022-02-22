/* Build tree using inorder and preorder */
BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;

    for (int i = inS; i <= inE; i++)
    {
        if (in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;

    int rInS = rootIndex + 1;
    int rInE = inE;
    int rPreS = lPreE + 1;
    int rPreE = preE;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);

    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
}

BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

/* Alternative Method */

// int preIndex = 0;
// BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE)
// {
//     if (inS > inE)
//     {
//         return NULL;
//     }

//     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(pre[preIndex++]);

//     int inIndex;
//     for (int i = inS; i <= inE; i++)
//     {
//         if (in[i] == root->data)
//         {
//             inIndex = i;
//             break;
//         }
//     }

//     root->left = buildTreeHelper(in, pre, inS, inIndex - 1);
//     root->right = buildTreeHelper(in, pre, inIndex + 1, inE);

//     return root;
// }
