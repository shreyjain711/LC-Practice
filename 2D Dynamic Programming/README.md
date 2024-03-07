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
- ***Problem Desc***: 
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***
  ```cpp
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
