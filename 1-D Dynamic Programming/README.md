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
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[House Robber](https://leetcode.com/problems/house-robber/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[House Robber II](https://leetcode.com/problems/house-robber-ii/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
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
