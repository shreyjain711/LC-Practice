# Problem Set

### ***[Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)***:
- ***Problem Desc***: invert -> left becomes right, right becomes left
- ***Recursively invert right and left subtrees, reverse pointers [O(n) time | O(1) space]***:
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
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
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
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

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
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
