// ***Problem Desc***: given preorder traversal and inorder traversal, form tree

/*
***recursive [O(n) time | O(n) space]***:
  - in each recursive call, keep a preorderIndex, this is the node currently being formed in each call (preorder supports this order)
  - can split for left and right subtree by finding index of preorderIndex node in inorder array, that point's left elements are in left and right ones in right subtree
*/
TreeNode* buildTreeHelper(vector<int>& pre, vector<int>& in, int &preI, int i, int j) {
    if (i>j || j>=in.size()) return NULL;
    int s = i; while (in[s] != pre[preI]) s++;
    preI++;
    return new TreeNode(pre[preI-1], 
                        buildTreeHelper(pre, in, preI, i, s-1),
                        buildTreeHelper(pre, in, preI, s+1, j));
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int i = 0; return buildTreeHelper(preorder, inorder, i, 0, inorder.size()-1);
}
