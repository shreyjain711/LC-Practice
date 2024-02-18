// ***Problem Desc***: kth elem in inorder traversal

// ***recursive, keep an int to track which elem curr recur call is on in inorder traversal [O(n) time | O(n) space]***:
void helper(TreeNode* root, int &k, int& ans) {
    if (!root) return;
    helper(root->left, k, ans); 
    k--; if (!k) {ans = root->val; return;}
    helper(root->right, k, ans); 
}

int kthSmallest(TreeNode* root, int k) {
    int ans; helper(root, k, ans); return ans;
}
