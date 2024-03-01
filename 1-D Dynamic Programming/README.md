# Problem Set

### ***[Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)***: ways to reach n, can take 1 or 2 Len step at once
- ***Problem Desc***: num of ways to reach nth steo if can take 1 or 2 len steps at once
- ***init array with 0, 1 elem = 1, then each elem = sum of prev two [O(n) time | O(n) space]***:
  ```cpp
  int climbStairs(int n) {
      vector<int> ways(n+1);
      ways[0] = ways[1] = 1;
      for (int i=2; i<=n; i++) ways[i] = ways[i-1] + ways[i-2];
      return ways[n];
  }
  ```
- ***need only prev two vals, use int for them instead of arr [O(n) time | O(1) space]***:
  ```cpp
  int climbStairs(int n) {
      int wayP=1, wayPP=1, ans=1;
      for (int i=2; i<=n; i++) {
          ans = wayP + wayPP;
          wayPP = wayP;
          wayP = ans;
      }
      return ans;
  }
  ```

### ***[Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)***: each step has a cost, min cost to reach top
- ***Problem Desc***: climbing each step has a cost, can go to next or the next to next from any stair, can start from 0/1; what min cost to climb the n stairs
- ***to reach nth stair (goal to reach n+1, so arr of sz n+1) cost = min of cost of climbing from st n-1 or st n-2 [O(n) time | O(n) space]***:
  ```cpp
  int minCostClimbingStairs(vector<int>& cost) {
      int n=cost.size(); vector<int> minC(n+1);
      for (int i=2; i<=n; ++i)
          minC[i] = min(minC[i-1] + cost[i-1], minC[i-2] + cost[i-2]);
      return minC[n];
  }
  ```
- ***Since need only prev two vals for the curr step, store only those [O(n) time | O(1) space]***:
  ```cpp
  int minCostClimbingStairs(vector<int>& cost) {
      int n=cost.size(), prev1 = 0, prev2 = 0, ans = 0;
      for (int i=2; i<=n; ++i) {
          ans = min (prev1 + cost[i-1], prev2 + cost[i-2]);
          prev2 = prev1;
          prev1 = ans;
      }
      return ans;
  }
  ```

### ***[House Robber](https://leetcode.com/problems/house-robber/)***:
- ***Problem Desc***: given list of cash in each house in a line; can't rob 2 adjacent houses; what's max loot possible
- ***keep track of max steal if stolen from curr (=prev no stolen + curr val) and max if not stolen from curr (=max prev steal and no steal) [O(n) time | O(n) space]***:
  ```cpp
  int rob(vector<int>& nums) {
      int n = nums.size(); vector<vector<int>> dp(n+1, vector<int>(2)); 
      // 0th row for max if stole from this house
      // 1st for if didn't steal from this house
      dp[1][0] = nums[0]; 
      for (int i=2; i<=n; ++i) {
          dp[i][0] = dp[i-1][1] + nums[i-1];
          dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
      }
      return max(dp[n][0], dp[n][1]);
  }
  ```
- ***tracking of only vals from prev index is reqd so use ints and not arr [O(n) time | O(1) space]***:
  ```cpp
  int rob(vector<int>& nums) {
      int n = nums.size();
      int robIt=0, leaveIt=0;
      for (int i=0; i<n; ++i) {
          int leaveCurr = max(robIt, leaveIt);
          robIt = nums[i] + leaveIt;
          leaveIt = leaveCurr;
      }
      return max(robIt, leaveIt);
  }
  ```

### ***[House Robber II](https://leetcode.com/problems/house-robber-ii/)***:
- ***Problem Desc***: houses are in a ring, can't rob adjacent houses
- ***Run sol from 0..n-2 and 1..n-1, since in the best case can include the numbers from only one of the houses at ends [O(n) time | O(1) space]***:
  ```cpp
  int rob(vector<int>&nums, int start, int end) {
      int robIt=0, leaveIt=0;
      for (int i=start; i<end; ++i) {
          int leaveCurr = max(robIt, leaveIt);
          robIt = nums[i] + leaveIt;
          leaveIt = leaveCurr;
      }
      return max(robIt, leaveIt);
  }
  int rob(vector<int>& nums) {
      int n = nums.size(); if (n==1) return nums[0];
      return max(rob(nums, 0, n-1), rob(nums, 1, n));
  }
  ```

### ***[Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Decode Ways](https://leetcode.com/problems/decode-ways/)***: num of. ways for decoding a numeric string into letters
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Coin Change](https://leetcode.com/problems/coin-change/)***: min coins used to form amount X
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)***: KEY: store both min and max and set them as 1 when elem = 0
- ***Problem Desc***:
- ***Sol [O() time | O() space]***
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Word Break](https://leetcode.com/problems/word-break/)***: break string into words from given dict, is possible?    
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
