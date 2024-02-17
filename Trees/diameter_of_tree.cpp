// ***Problem Desc***: diameter = longest path in any two nodes of tree; might not even include root
// ***With a helper, at each node determine max diameter till now and diameter incl this node [O(n) time | O(n) space (recursion stack space)]***:
pair<int,int> diameterDepthHelper(TreeNode* root) {
    if (!root) return {0, 0};
    pair<int,int> left = diameterDepthHelper(root->left), right = diameterDepthHelper(root->right);
    return { (max(max(left.first, right.first), left.second + right.second)), 
             (1 + max(left.second, right.second))};
}
int diameterOfBinaryTree(TreeNode* root) {
    return diameterDepthHelper(root).first;
}
