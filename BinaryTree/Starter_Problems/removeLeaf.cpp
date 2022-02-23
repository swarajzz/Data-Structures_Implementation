/* Remove leaf nodes */
BinaryTreeNode<int> * removeLeaf(BinaryTreeNode<int>* root){
    if(root == NULL){
        return root;
    }

    if(!root -> left && !root -> right){
        delete root;
        return NULL;
    }

    root -> left = removeLeaf(root -> left);
    root -> right = removeLeaf(root -> right);

    return root;
}