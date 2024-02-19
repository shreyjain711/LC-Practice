// ***Problem Desc***: if tree q is subtree of p, i.e. exact tree q exists in p (shouldn't have more children)
// ***check if root node same, if not then check the left and right subtrees for being the target subtree [O(n<sup>2</sup>) time | O(n<sup>2</sup>) space]***:
bool isIdentical(TreeNode* p, TreeNode* q) {
    if (!p && !q) return 1; else if (!p || !q) return 0;
    return p->val == q->val && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) return 0;
    return isIdentical(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
