// ***Problem Desc***: invert -> left becomes right, right becomes left
// ***Recursively invert right and left subtrees, reverse pointers [O(n) time | O(1) space]***:
TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* temp = root->right;
    invertTree(root->left); invertTree(root->right);
    root->right = root->left; root->left = temp;
    return root;
}
