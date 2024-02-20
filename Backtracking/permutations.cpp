// ***Problem Desc***: given an array, generate all permutations of its elements

/*
  - ***backtracking, swap i, j pairs for generating permutations [O(n.n!) time | O(n!) space]***:
  - j goes from i...end: not from i+1 since no swapped version is also a permutation
  - recursive call gets from i+1 and not from j+1 since for j>i+1, the swaps with i+1th elem get ruled out
*/
  void backtrack(int i, vector<int>& nums, vector<vector<int>>& ans) {
      if (i==nums.size()) {ans.push_back(nums);}
      for(int j = i; j<nums.size(); ++j) {
          swap(nums[i], nums[j]);
          backtrack(i+1, nums, ans);
          swap(nums[i], nums[j]);
      }
  }
  vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans; 
      backtrack(0, nums, ans);
      return ans;
  }
