# Problem Set

### ***[Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)***:
- ***Problem Desc***: invert -> left becomes right, right becomes left
- ***Recursively invert right and left subtrees, reverse pointers [O(n) time | O(n) space (recursion stack space)]***:
  ```cpp
  TreeNode* invertTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* temp = root->right;
    invertTree(root->left); invertTree(root->right);
    root->right = root->left; root->left = temp;
    return root;
  }
  ```


### ***[Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)***:
- ***Problem Desc***: find max depth of tree
- ***Recursive: depth at curr lvl = 1+max(depthLeft, depthRight) [O(n) time | O(n) space (recursion stack space)]***: 
  ```cpp
  int maxDepth(TreeNode* root) {
      if (!root) return 0;
      return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
  ```

### ***[Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)***:
- ***Problem Desc***: diameter = longest path in any two nodes of tree; might not even include root
- ***With a helper, at each node determine max diameter till now and diameter incl this node [O(n) time | O(n) space (recursion stack space)]***:
  ```cpp
  pair<int,int> diameterDepthHelper(TreeNode* root) {
      if (!root) return {0, 0};
      pair<int,int> left = diameterDepthHelper(root->left), right = diameterDepthHelper(root->right);
      return { (max(max(left.first, right.first), left.second + right.second)), 
               (1 + max(left.second, right.second))};
  }
  int diameterOfBinaryTree(TreeNode* root) {
      return diameterDepthHelper(root).first;
  }
  ```

### ***[Balanced Binary Tree](https://leetcode.com/problems/balanced-binary-tree/)***:
- ***Problem Desc***: height-balanced, i.e. for any node, diff b/w height left and right subtrees <= 1
- ***Sol [O(n) time | O(n) space]***:
  ```cpp
  int helper(TreeNode* root, bool &isB) {
      if (!root) return 0;
      int leftH = helper(root->left, isB), rightH = helper(root->right, isB);
      if (abs(leftH - rightH) > 1) isB = 0;
      return max(leftH, rightH) + 1;
  }
  bool isBalanced(TreeNode* root) {
      bool isB = 1; helper(root, isB); return isB;
  }
  ```

### ***[Same Tree](https://leetcode.com/problems/same-tree/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)***:
- ***Problem Desc***: level order is accessing each level one by one
- ***Recursive, with a referenced vec of vecs to store [O(n) time | O(n) space]***:
  ```cpp
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
  ```
- ***iterative, with queues [O(n) time | O(n) space]***:
  ```cpp
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
  ```


### ***[Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)***:
- ***Problem Desc***: Find LCA in a BST
- ***Recursive, if both elems < root then look left, if > root then right else root is the ans [O(logn) time | O(logn) space]***:
  ```cpp
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      int rV = root->val, pV = p->val, qV = q->val;
      
      if (rV > pV && rV > qV) return lowestCommonAncestor(root->left, p, q);
      if (rV < pV && rV < qV) return lowestCommonAncestor(root->right, p, q);
      
      return root;
  }
  ```
- ***Iterative, same as above but with a while loop [O(logn) time | O(1) space]***:
  ```cpp
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
  ```

### ***[Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)***:
- ***Problem Desc***: list of right most node of each level
- ***Recursive [O(n) time | O(n) space]***: send in lvl, calls are in VRL order so if a level wasn't seen earlier then it's the one visible from right and gets pushed in ans vector
  ```cpp
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
  ```
- ***iterative, with queues [O(n) time | O(n) space]***: do level order, the last back node of the queue is the right side view

### ***[Count Good Nodes In Binary Tree](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)***:
- ***Problem Desc***: good node is one which doesn't have any node with value greater than it in its path to the root
- ***Recur, from root start, if see a node with val less than max till now then not good else is [O(n) time | O(n) space]***:
  ```cpp
  void helper(TreeNode *root, int mx, int &ans) {
      if (!root) return;
      if (root->val >= mx) {ans++; mx = root->val;}
      helper(root->left, mx, ans); helper(root->right, mx, ans);
  }

  int goodNodes(TreeNode* root) {
      int ans = 0; helper(root, -1e5, ans); return ans;
  }
  ```

### ***[Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)***:
- ***Problem Desc***: validate for each node that its left subtree's max is less than the node and right subtree min more than it
- ***get min and max of each subtree back and then validate [O(n) time | O(n) space]***:
  ```cpp
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
  ```

### ***[Kth Smallest Element In a Bst](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)***:
- ***Problem Desc***: kth elem in inorder traversal
- ***recursive, keep an int to track which elem curr recur call is on in inorder traversal [O(n) time | O(n) space]***:
  ```cpp
  void helper(TreeNode* root, int &k, int& ans) {
      if (!root) return;
      helper(root->left, k, ans); 
      k--; if (!k) {ans = root->val; return;}
      helper(root->right, k, ans); 
  }
  int kthSmallest(TreeNode* root, int k) {
      int ans; helper(root, k, ans); return ans;
  }
  ```

### ***[Construct Binary Tree From Preorder And Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)***:
- ***Problem Desc***: given preorder traversal and inorder traversal, form tree
- ***recursive [O(n) time | O(n) space]***:
  - in each recursive call, keep a preorderIndex, this is the node currently being formed in each call (preorder supports this order)
  - can split for left and right subtree by finding index of preorderIndex node in inorder array, that point's left elements are in left and right ones in right subtree
  ```cpp
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
  ```

### ***[Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)***:
- ***Problem Desc***: max of sums of all possible paths, even one node will do. Can be -ve
- ***Recursive [O(n) time | O(n) space]***: at each node, we store maxSumPath using curr node by val + max(0, from left) + max(0, from right); we return the max path sum from either of left or right subtrees
  ```cpp
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
  ```

### ***[Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
