// ***Problem Desc***: Find LCA in a BST
// ***Recursive, if both elems < root then look left, if > root then right else root is the ans [O(logn) time | O(logn) space]***:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int rV = root->val, pV = p->val, qV = q->val;
    
    if (rV > pV && rV > qV) return lowestCommonAncestor(root->left, p, q);
    if (rV < pV && rV < qV) return lowestCommonAncestor(root->right, p, q);
    
    return root;
}

// ***Iterative, same as above but with a while loop [O(logn) time | O(1) space]***:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int pV = p->val, qV = q->val;
    while (root) {
        int rV = root->val;
        if (rV > pV && rV > qV) root = root->left;
        else if (rV < pV && rV < qV) root = root->right;
        else return root;
    }
    return root;
}
