// ***Problem Desc***: find max depth of tree
// ***Recursive: depth at curr lvl = 1+max(depthLeft, depthRight) [O(n) time | O(1) space]***: 
int maxDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
