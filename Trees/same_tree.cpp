// ***Problem Desc***: given trees are identical
// ***Recur, check node val and then both sides [O(n) time | O(n) space]***:
bool isSameTree(TreeNode* p, TreeNode* q) {
  if (!p && !q) return 1;
  else if (!p || !q) return 0;
  return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
