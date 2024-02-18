// ***Problem Desc***: validate for each node that its left subtree's max is less than the node and right subtree min more than it
// ***get min and max of each subtree back and then validate [O(n) time | O(n) space]***:
pair<int, int> helper(TreeNode* root, bool &isValid) {
    if (!isValid) return {0,0};
    pair<int, int> ans = {root->val, root->val}, left, right;
    if (root->left) {
        left = helper(root->left, isValid); 
        ans.first = left.first;
        isValid &= root->val > left.second;
    }
    if (!isValid) return {0,0};
    if (root->right) {
        right = helper(root->right, isValid); 
        ans.second = right.second;
        isValid &= root->val < right.first;
    }
    return ans;
}
bool isValidBST(TreeNode* root) {
    bool isValid = 1; helper(root, isValid); return isValid;
}
