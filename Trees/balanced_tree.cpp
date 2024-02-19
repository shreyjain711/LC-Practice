// ***Problem Desc***: height-balanced, i.e. for any node, diff b/w height left and right subtrees <= 1
// ******Recur, for each node, bring back height of left and right subtrees, compare, validate and return height [O(n) time | O(n) space]***:
int helper(TreeNode* root, bool &isB) {
    if (!root) return 0;
    int leftH = helper(root->left, isB), rightH = helper(root->right, isB);
    if (abs(leftH - rightH) > 1) isB = 0;
    return max(leftH, rightH) + 1;
}
bool isBalanced(TreeNode* root) {
    bool isB = 1; helper(root, isB); return isB;
}
