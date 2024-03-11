# Problem Set

### ***[Unique Paths](https://leetcode.com/problems/unique-paths/)*** [Shortest Path]:
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

### ***[Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)*** [LCS]:
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

### ***[Coin Change II](https://leetcode.com/problems/coin-change-ii/)*** [Unbounded Knapsack]:
- ***Problem Desc***: given coins, find num of ways to make up given amount 
- ***Brute [O(c<sup>amount</amount>) time | O(amount) space]***: backtracking, use diff coins till reach sum >= amount
- ***dp[i][j] num of ways to make j amount with with coins 0..i, dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]] [O(c.amount) time | O(c.amount) space]***
  ```cpp
  int change(int amount, vector<int>& coins) {
      sort(begin(coins), end(coins));
      int n = coins.size(), dp[n][amount+1]; memset(dp, 0, sizeof dp); 
      for (int i=0; i<n; ++i) dp[i][0] = 1;
      for (int i=coins[0]; i<=amount; i+=coins[0]) dp[0][i] = 1;
      for (int c=1; c<n; c++) 
          for(int i=0; i<=amount; ++i) 
              dp[c][i] = dp[c-1][i] + ((i-coins[c]>=0) ? dp[c][i-coins[c]] : 0);
      return dp[n-1][amount];
  }
  ```
- ***Use a 1D array of amount+1 len, don't need to add the numWays till i-1 coin, just add dp[j-coins[i]] if j-coin[i] is +ve [O(c.amount) time | O(amount) space]***:
  ```cpp
  int change(int amount, vector<int>& coins) {
      sort(begin(coins), end(coins));
      int n = coins.size(), dp[amount+1]; memset(dp, 0, sizeof dp); dp[0] = 1;
      for (int c=0; c<n; c++) 
          for(int i=0; i<=amount; ++i) 
              dp[i] += ((i-coins[c]>=0) ? dp[i-coins[c]] : 0);
      return dp[amount];
  }
  ```

### ***[Target Sum](https://leetcode.com/problems/target-sum/)*** [0-1 Knapsack]:
- ***Problem Desc***: given a list of nums, either use them as +ve or -ve to reach the target; how many ways to form target
- ***Brute [O(2<sum>n</sum>) time | O(n) space]***: backtracking, use as +ve and then -ve, at end see if target reached
- ***memoisation, store num ways to reach a sum t from nums indexed i..n-1, modified knapsack as decision is +ve/-ve (not 1/0) [O(n.target) time | O(n.target) space]***:
  ```cpp
  map<pair<int,int>, int> dp;
  int dfs(int i, int t, vector<int>& nums) {
      if (i==nums.size()) { return (t==0);}
      if (dp.find({i,t})!=dp.end()) return dp[{i,t}];
      dp[{i,t}] = dfs(i+1, t-nums[i], nums) + dfs(i+1, t+nums[i], nums);
      return dp[{i,t}];
  }
  int findTargetSumWays(vector<int>& nums, int target) {
      return dfs(0, target, nums);
  }
  ```
- ***Math makes task to find subset of nums to add to (target+sumAll)/2; becomes 0-1 knapsack []***:
  - Sum(+ve) - Sum(-ve) = target -> adding sumAll (i.e. sum(+ve) + sum(-ve)) to both sides -> 2 * sum(+ve) = target + sumAll -> sum(+ve) = (target + sumAll)/2
  - so t+sumAll can't be odd or sumAll can't be < t
  - go decreasing order in inner loop, otherwise would end up using same coin multiple times
  ```cpp
  int findTargetSumWays(vector<int>& nums, int target) {
      int sum = accumulate(begin(nums), end(nums), 0);
      if (sum<target || (target+sum)%2) return 0;
      target = (target+sum)>>1;
      int dp[target+1]; memset(dp, 0, sizeof dp); dp[0]=1;
      for (int n:nums)
          for (int i=target; i>=n; --i) 
          // go opp, target..n, since 0/1, if forward, will be unbounded
              dp[i] += dp[i-n];
      return dp[target];
  }
  ```

### ***[Interleaving String](https://leetcode.com/problems/interleaving-string/)***:
- ***Problem Desc***: given 2 strings, s1 and s2, determine if s3 is formed by interleaving s1 and s2
- ***Brute [O(2<sup>m+n</sup>) time | O(m+n) space]***: backtracking
- ***Caching with backtracking, if the current ind in s1 is eq to i1+i2 in s3 then can go forward there, sim in s2, cache the result [O(m.n) time | O(m.n) space]***
  ```cpp
  map<pair<int, int>, bool> dp;
  bool dfs(int i1, int i2, string &s1, string &s2, string &s3) {
      if (i1==s1.size()&&i2==s2.size()) return 1;
      if (dp.find({i1,i2}) != dp.end()) return dp[{i1,i2}];
      dp[{i1,i2}] = 0;
      if (i1<s1.size() && s1[i1] == s3[i1+i2]) dp[{i1, i2}] |= dfs(i1+1, i2, s1,s2,s3);
      if (i2<s2.size() && s2[i2] == s3[i1+i2]) dp[{i1, i2}] |= dfs(i1, i2+1, s1,s2,s3);
      return dp[{i1,i2}];
  }
  bool isInterleave(string s1, string s2, string s3) {
      if (s1.size()+s2.size() != s3.size()) return 0;
      return dfs(0,0,s1,s2,s3);
  }
  ```
- ***go from back to front, dp[i][j] = 1 if i..m and j..n makes up i+j..m+n [O(m.n) time | O(m.n) space]***
  - dp[i][j] = 1 if s1[i] matches and dp[i+1][j] was true
  - Or if s2[j] matches and dp[i][j+1] was true
  ```cpp
  bool isInterleave(string s1, string s2, string s3) {
      int n1 = s1.size(), n2 = s2.size(), dp[n1+1][n2+1];
      if (n1+n2!=s3.size()) return 0;
      memset(dp, 0, sizeof dp); dp[n1][n2] = 1;
      for (int i=n1; ~i; --i) {
          for (int j=n2; ~j; --j) {
              if (i<n1 && s1[i]==s3[i+j] && dp[i+1][j]) dp[i][j] = 1;
              if (j<n2 && s2[j]==s3[i+j] && dp[i][j+1]) dp[i][j] = 1;
          }
      } return dp[0][0];
  }
  ```
- ***Don't need to keep results in grid, we go over the same array repeatedly [O(m.n) time | O(n) space]***:
  ```cpp
  bool isInterleave(string s1, string s2, string s3) {
      int n1 = s1.size(), n2 = s2.size(), dp[n2+1];
      if (n1+n2!=s3.size()) return 0;
      memset(dp, 0, sizeof dp); dp[n2] = 1;
      for (int i=n1; ~i; --i) 
          for (int j=n2; ~j; --j) 
              if (!dp[j] && j<n2 && s2[j]==s3[i+j] && dp[j+1]) dp[j] = 1;
      return dp[0];
  }
  ```

### ***[Longest Increasing Path In a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)***:
- ***Problem Desc***: given matrix, find the longest increasing path 
- ***go across the matrix and cache the results for each cell [O(n.m) time | O(n.m) space]***:
  ```cpp
  int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
  int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
      if (dp[i][j]) return dp[i][j];
      for (int d=0; d<4; ++d) {
          int x = i+dx[d], y = j+dy[d];
          if (x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size()) continue;
          if (matrix[x][y] > matrix[i][j])
              dp[i][j] = max(dp[i][j], 1+dfs(x, y, dp, matrix));
      } 
      dp[i][j] = max(dp[i][j],1);
      return dp[i][j];
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
      int m=matrix.size(), n=matrix[0].size(), ans=1; vector<vector<int>> dp(m, vector<int>(n));
      for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) ans = max(ans, dfs(i, j, dp, matrix));
      return ans;
  }
  ```

### ***[Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)***:
- ***Problem Desc***: given string s and t, find num of total subseq of s that can form t
- ***Brute [O(2<sup>s</sup>) time | O(s) space]***: bracktracking, for each char in s, we either include it if it's the next char in the t string or we don't in our subseq
- ***Memoisation, cache the outputs from the brute technique [O(s.t) time | O(s.t) space]***
  ```cpp
  int dfs (int si, int ti, string &s, string &t, vector<vector<int>>&dp) {
      if (ti==t.size()) return 1;
      if (s.size()-si < t.size()-ti) return 0;
      if (dp[si][ti] != -1) return dp[si][ti];
      dp[si][ti] = dfs(si+1, ti, s, t, dp);
      if (t[ti] == s[si]) dp[si][ti] += dfs(si+1, ti+1, s, t, dp);
      return dp[si][ti];
  }
  int numDistinct(string s, string t) {
      vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
      return dfs(0, 0, s, t, dp);
  }
  ```
- ***For incr len of t, we keep going over s; we store for curr len of t and prev; c[i] = c[i-1], if s[i]==t[j] then +p[i-1] [O(s.t) time | O(s.t) space]***
  - c[i] = c[i-1] -> dp[si][ti] = dp[si+1][ti] i.e. if I could form X subseq till the prev char in s then the current non-matching char will keep the count same
  - if the current char of s is matching the curr last char of t then using this char,
    - we can have successful subseqs that'll be equal to the num possible without the curr chars, i.e. p[i-1]
  ```cpp
  int numDistinct(string s, string t) {
      int m=s.size(), n=t.size(); vector<int> curr(m+1), prev(m+1, 1);
      for (int j=1; j<=n; ++j) {
          for (int i=1; i<=m; ++i) {
              curr[i] = curr[i-1]%(int)1e9 + (s[i-1]==t[j-1] ? prev[i-1]%(int)1e9 : 0);
          } prev = curr;
      }
      return curr[m];
  }
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
