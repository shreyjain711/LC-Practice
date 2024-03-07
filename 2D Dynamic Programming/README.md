# Problem Set

### ***[Unique Paths](https://leetcode.com/problems/unique-paths/)***:
- ***Problem Desc***: starting from 0,0 go to m,n; can go down or right, how many unique paths possible
- ***Brute [O((m+n)! / m!.n!) time | O((m+n)<sup>2</sup>) space]***: backtracking, go on each path
- ***store num of ways to reach each row and keep on iteratively calculating with reference reln dp[i][j] = dp[i-1][j] + dp[i][j-1] [O(m.n) time | O(n) space]***
  ```cpp
  int uniquePaths(int m, int n) {
      vector<int> curr(n, 1), next(n, 1);
      for (int i=1; i<m; ++i) {
          for(int j=1; j<n; j++) {
              next[j] = next[j-1] + curr[j];
          } curr = next;
      } return curr[n-1];
  }
  ```

### ***[Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)***:
- ***Problem Desc***: given two string, find longest common subseq
- ***dp[i][j] = LCS till 0..i in str1 and 0..j in str2, dp[i][j] = max(dp[i-1][j],dp[i][j-1]) and if str1[i]==str2[j] ->1+dp[i-1][j-1] [O(n1.n2) time | O(n1.n2) space]***
  ```cpp
  int longestCommonSubsequence(string text1, string text2) {
      int n1 = text1.size(), n2 = text2.size();
      int lcs[n1][n2]; memset(lcs, 0x0, sizeof lcs);
      lcs[0][0] = text1[0] == text2[0];
      for (int i=1; i<n1; ++i) lcs[i][0] = max((int)(text1[i]==text2[0]), lcs[i-1][0]);
      for (int i=1; i<n2; ++i) lcs[0][i] = max((int)(text1[0]==text2[i]), lcs[0][i-1]);

      for (int i=1; i<n1; ++i) {
          for (int j=1; j<n2; ++j) {
              lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
              if (text1[i] == text2[j]) 
                  lcs[i][j] = max(1+lcs[i-1][j-1], lcs[i][j]);
          } 
      } return lcs[n1-1][n2-1];
  }
  ```

### ***[Best Time to Buy And Sell Stock With Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```

### ***[Coin Change II](https://leetcode.com/problems/coin-change-ii/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```

### ***[Target Sum](https://leetcode.com/problems/target-sum/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```

### ***[Interleaving String](https://leetcode.com/problems/interleaving-string/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```

### ***[Longest Increasing Path In a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```

### ***[Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```

### ***[Edit Distance](https://leetcode.com/problems/edit-distance/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```

### ***[Burst Balloons](https://leetcode.com/problems/burst-balloons/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```

### ***[Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)***:
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
  ```
