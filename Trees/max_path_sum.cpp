// ***Problem Desc***: max of sums of all possible paths, even one node will do. Can be -ve

// ***Recursive [O(n) time | O(n) space]***: at each node, we store maxSumPath using curr node by val + max(0, from left) + max(0, from right); 
// we return the max path sum from either of left or right subtrees
int maxPathSumHelper(int &ans, TreeNode* root) {
    if (!root) return INT_MIN;
    
    int leftSum = max(0, maxPathSumHelper(ans, root->left));
    int rightSum = max(0, maxPathSumHelper(ans, root->right));
    ans = max(ans, root->val + leftSum + rightSum);

    return root->val + max(leftSum, rightSum);
}

int maxPathSum(TreeNode* root) {
    if (!root) return 0;
    int ans = -1e5;
    return max(ans, maxPathSumHelper(ans, root));
}
