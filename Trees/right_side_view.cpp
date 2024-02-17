// ***Problem Desc***: list of right most node of each level
// ***Recursive [O(n) time | O(n) space]***: send in lvl, calls are in VRL order so if a level wasn't seen earlier then it's the one visible from right and gets pushed in ans vector
void rightSideViewHelper(vector<int> &ans, TreeNode* root, int lvl) {
    if (!root) return;
    if (ans.size() <= lvl) ans.push_back(root->val);
    rightSideViewHelper(ans, root->right, lvl+1);
    rightSideViewHelper(ans, root->left, lvl+1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans; rightSideViewHelper(ans, root, 0);
    return ans;
}
