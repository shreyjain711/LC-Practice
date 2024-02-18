// ***Problem Desc***: good node is one which doesn't have any node with value greater than it in its path to the root
// ***Recur, from root start, if see a node with val less than max till now then not good else is [O(n) time | O(n) space]***:
void helper(TreeNode *root, int mx, int &ans) {
    if (!root) return;
    if (root->val >= mx) {ans++; mx = root->val;}
    helper(root->left, mx, ans); helper(root->right, mx, ans);
}

int goodNodes(TreeNode* root) {
    int ans = 0; helper(root, -1e5, ans); return ans;
}
