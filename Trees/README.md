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
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
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
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:    

### ***[Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Kth Smallest Element In a Bst](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Construct Binary Tree From Preorder And Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
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
