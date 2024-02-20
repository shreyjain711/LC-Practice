# Problem Set

### ***[Subsets](https://leetcode.com/problems/subsets/)***:
- ***Problem Desc***: make all possible subsets of given array
- ***Brute [O(2<sup>n</sup>) time | O(1) space]***: each elem can either be present or not be present, so 2^n possible combinations/subsets
- ***Recursively, push curr arr into ans, add curr elem into curr arr and the call again for next index, on return pop the curr elem [O(n<sup>2</sup>) time | O(n2) space]***:
  ```cpp
  void backtrack(int i, vector<int> &curr, vector<int> &nums, vector<vector<int>>& ans) {
      ans.push_back(curr);
      for(int j=i; j<nums.size();++j){
          curr.push_back(nums[j]);
          backtrack(j+1, curr, nums, ans);
          curr.pop_back();
      }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans; vector<int> curr;
      backtrack(0, curr, nums, ans);
      return ans;
  }
  ```

### ***[Combination Sum](https://leetcode.com/problems/combination-sum/)***:
- ***Problem Desc***: given an arr of distince +ve nums, find all possible combinations of its elems (with replacement) that sum up to a given number
- ***Brute [O(2<sup>n</sup> time | O(1) space]***: try every elem once and then restart, no backtracking
- ***backtracking [O(n<sup>2</sup>) time | O(n) space]***:
  ```cpp
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans; vector<int> curr;
      backtrack(0, target, curr, candidates, ans);
      return ans;
  }

  void backtrack(int i, int remaining, vector<int> &curr, 
                  vector<int>& nums, vector<vector<int>> &ans) {
      if (remaining<=0) {
          if (!remaining) ans.push_back(curr);
          return;
      }
      
      for(int j = i; j<nums.size(); ++j) {
          curr.push_back(nums[j]); remaining -= nums[j];
          backtrack(j, remaining, curr, nums, ans);
          curr.pop_back(); remaining += nums[j];
      }
  }
  ```

### ***[Permutations](https://leetcode.com/problems/permutations/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Subsets II](https://leetcode.com/problems/subsets-ii/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Word Search](https://leetcode.com/problems/word-search/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[N Queens](https://leetcode.com/problems/n-queens/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
