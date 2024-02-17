// ***Problem Desc***: level order is accessing each level one by one
// ***Recursive, with a referenced vec of vecs to store [O(n) time | O(n) space]***:
void levelOrderHelper(vector<vector<int>> &ans, TreeNode* root, int lvl) {
    if (!root) return;
    levelOrderHelper(ans, root->left, lvl+1);
    if (ans.size() < lvl+1) ans.resize(lvl+1);
    ans[lvl].push_back(root->val);
    levelOrderHelper(ans, root->right, lvl+1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    levelOrderHelper(ans, root, 0);
    return ans;
}

// ***iterative, with queues [O(n) time | O(n) space]***:
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans; int i=0;
    if(!root) return ans;
    queue<TreeNode*> curr; curr.push(root);
    while (!curr.empty()) {
        queue<TreeNode*> next;
        ans.resize(i+1);
        while (!curr.empty()) {
            cout<<i<<endl;
            TreeNode* n = curr.front(); curr.pop();
            ans[i].push_back(n->val);
            if (n->left) next.push(n->left);
            if (n->right) next.push(n->right);
        }
        curr = next;
        i++;
    }
    return ans;
}
