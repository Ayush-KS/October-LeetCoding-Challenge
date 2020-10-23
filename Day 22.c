// Minimum Depth of Binary Tree

int min(int a, int b) {
    if(a < b)
        return a;
    return b;
}

int minDepth(struct TreeNode* root){
    if(root == NULL)
        return 0;
    if(!root -> left && !root -> right)
        return 1;
    if(!root -> left)
        return 1 + minDepth(root -> right);
    if(!root -> right)
        return 1 + minDepth(root -> left);
    else
        return 1 + min(minDepth(root -> right),  minDepth(root -> left));
}