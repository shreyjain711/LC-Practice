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
- ***Problem Desc***: given string, find its longest palindrome substr
- ***Brute, check for every substr [O(n<sup>3</sup>) time | O(1) space]***
- ***2D DP, table reps if sub str from i..j is a palin, iter diagonally (right) by increasing len, i=0, j=i+len [O(n<sup>2</sup>) time | O(<sup>2</sup>) space]***:
  ```cpp
  string longestPalindrome(string s) {
      int n = s.size(), ansStart = 0, ansLen = 1; 
      bool isPalin[n][n]; memset(isPalin, 0x1, sizeof isPalin);

      for (int len = 1; len<n; len++) {
          for (int i=0, j; i<n-len; ++i) {
              j = i+len;
              isPalin[i][j] = 0;
              if ((i>j || isPalin[i+1][j-1]) && s[i]==s[j]) {
                  isPalin[i][j]=1;
                  if (ansLen < len+1) {ansStart=i; ansLen=len+1;}
              }
          }
      }
      return s.substr(ansStart, ansLen);
  }
  ```
- ***Expand from each elem rightwards till chars same, then expand both sides if same, i moves to where the curr elem's repeat ends [O(n<sup>2</sup>) time | O(n) space]***:
  - DP approach will take (n.n-1)/2 steps, this practically takes lesser even tho same complexity
  - i moves to point where curr elem's repeat ends because all of the variants with the same char at centre would already be calculated
    - no point trying for odd len from here either as the longest palin will keep all same chars at centre regardless if the centre gets odd len or even
  ```cpp
  string longestPalindrome(string s) {
      int n = s.size(), ansStart = 0, ansLen = 1; 
      
      for (int i = 0; i<n-1; i++) {
          int l = i-1, r=i;
          while(r<n && s[i]==s[r]) { //expand centre rightwards till same chars
              if(ansLen < r-i+1) {ansLen=r-i+1; ansStart=i;} 
              r++;
          } i=r-1; // we move i to point where the same char existence ends
          while (l>=0 && r<n && s[l]==s[r]) { // expand on both sides
              if(ansLen < r-l+1) {ansLen = r-l+1; ansStart=l;}
              l--;r++;
          }
      }
      return s.substr(ansStart, ansLen);
  }
  ```

### ***[Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)***:
- ***Problem Desc***: count num of palindromic substrs in a given str
- ***Brute, check each [O(n<sup>3</sup>) time | O(1) space]***
- ***make a 2d dp, it tell if substr from i to j is a palindrome, go by the right diagonal, incre len each iter [O(n<sup>2</sup>) time | O(n<sup>2</sup>) space]***:
  ```cpp
  int countSubstrings(string s) {
      int n = s.size(), numPalins=n; 
      bool isPalin[n][n]; memset(isPalin, 0x1, sizeof isPalin);
      
      for (int l=1; l<n; ++l) {
          for (int i=0, j=i+l; i<n-l; ++i, ++j) {
              isPalin[i][j] = 0;
              if (isPalin[i+1][j-1] && s[i]==s[j]) {
                  isPalin[i][j] = 1; numPalins++;
              }
          }
      }
      
      return numPalins;
  }
  ```
- ***Expand, for both odd and even len, from each pos in str [O(n<sup>2</sup>) time | O(1) space]***:
  ```cpp
  void countPalins(int &numPalins, string s, int start, int end) {
      while (start>=0 && end<s.size() && s[start] == s[end]) {numPalins++; start--; end++;}
  }
  int countSubstrings(string s) {
      int n = s.size(), numPalins=0; 
      for (int i=0; i<n; ++i) {
          countPalins(numPalins, s, i, i);
          countPalins(numPalins, s, i, i+1);
      }
      return numPalins;
  }
  ```

### ***[Decode Ways](https://leetcode.com/problems/decode-ways/)***: num of. ways for decoding a numeric string into letters
- ***Problem Desc***: given a string containing only digits, find num of ways it can be read; 1 = A, so 0 can't be read
- ***1D dp, dp[i] = num of ways to decode str till ith pos (non-incl); dp[i] = dp[i-1](if i can be decoded) + dp[i-2] (if i-2 i-1 can be dec) [O(n) time | O(n) space]***:
  ```cpp
  bool canDecode(string s, int i, int len) {
      if (s[i] == '0') return 0;
      if (len == 2 && (s[i]>'2' || s[i] == '2' && s[i+1] > '6')) return 0;
      return 1;
  }
  int numDecodings(string s) {
      int n = s.size(), decos[n+1]; memset(decos, 0, sizeof decos);
      if (!canDecode(s, 0, 1)) return 0; 
      decos[0] = 1; decos[1] = 1;
      for (int i=2; i<=n; i++) {
          if (canDecode(s, i-1, 1)) decos[i] += decos[i-1];
          if (canDecode(s, i-2, 2)) decos[i] += decos[i-2];
          if (!decos[i]) return 0;
      }
      return decos[n];
  }
  ```

### ***[Coin Change](https://leetcode.com/problems/coin-change/)***: min coins used to form amount X
- ***Problem Desc***: given n coins of diff value, find min number of coins required to total upto given amount X
- ***1D DP, 0..amount, each cell = min num reqd to form amount; starting from 0, iterate over each coin and mark vals accordingly [O(amount.c) time | O(amount) space]***:
  ```cpp
  int coinChange(vector<int>& coins, int amount) {
      if (!amount) return 0;
      int dp[amount+1]; memset(dp, 0, sizeof dp);
      for (int i=0; i<=amount; ++i) {
          if (!i || dp[i]) {
              for (int c: coins) {
                  long sum = i+(long)c;
                  if (sum <= amount) 
                      dp[sum] = dp[sum] ? min(dp[sum], 1+dp[i]) : dp[i]+1;
              }
          }
      }
      return dp[amount] ? dp[amount] : -1;
  }
  ```

### ***[Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)***: KEY: store both min and max and set them as 1 when elem = 0
- ***Problem Desc***: given arr with -ve, 0, +ve nums, find max prod of a sub array
- ***Brute, calculate all subarrays' products [O(n<sup>2</sup>) time | O(1) space]***
- ***1D dp, iter over arr, store min max for each and calc at curr, reset taken care of [O(n) time | O(n) space]***:
  ```cpp
  int maxProduct(vector<int>& nums) {
      int n = nums.size(), ans=nums[0]; vector<vector<int>> minMax(n,vector<int>(2));
      minMax[0][0] = minMax[0][1] = nums[0];
      for (int i=1; i<n; ++i) {
          int a = minMax[i-1][0] * nums[i], b = minMax[i-1][1] * nums[i];
          minMax[i][0] = min(min(a, b), nums[i]);
          minMax[i][1] = max(max(a, b), nums[i]);
          ans = max(ans, minMax[i][1]);
      }
      return ans;
  }
  ```
- ***store only min max from prev iter, don't store arr [O(n) time | O(1) space]***:
  ```cpp
  int maxProduct(vector<int>& nums) {
      int n = nums.size(), ans, prevMin, prevMax; 
      prevMin = prevMax = nums[0]; ans = prevMax;   
      for (int i=1; i<n; ++i) {
          int a = prevMax * nums[i], b = prevMin * nums[i];
          prevMin = min(min(a, b), nums[i]);
          prevMax = max(max(a, b), nums[i]);
          ans = max(ans, prevMax);
      }
      return ans;
  }
  ```
- ***Alternate, calc continuous max prod from left(0) and right(n-1), if in iter prevMax = 0, reset to 1 [O(n) time | O(1) space]***:
  - works as subarr will happen for sure from either left or right -> e.g. [3,-1,4]
  ```cpp
  int maxProduct(vector<int>& nums) {
      int n = nums.size(), ans=-1e6, prevMax=1; 
      for (int i=0; i<n; ++i) {
          prevMax *= nums[i];
          ans = max(ans, prevMax);
          if (!prevMax) prevMax = 1;
      } prevMax = 1;
      for (int i=n-1; i>=0; --i) {
          prevMax *= nums[i];
          ans = max(ans, prevMax);
          if (!prevMax) prevMax = 1;
      }
      return ans;
  }
  ```

### ***[Word Break](https://leetcode.com/problems/word-break/)***: break string into words from given dict, is possible?    
- ***Problem Desc***: break string to words from the given dict
- ***1D boor arr to rep if breaking word till ith pos possible; at each pos, go upto dictWordLen back, if in dict remaining can be broken = 1 [O(len.dictWordLen) time | O(len) space]***:
  ```cpp
  bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> dict(wordDict.begin(), wordDict.end());
      int n = s.size(); vector<bool> canBreak(n+1, 0); canBreak[0] = 1;
      for (int i=1; i<=n; ++i) {
          int j = i-1;
          while (j>=0 && i-j<=20 && !canBreak[i]) {
              if (dict.find(s.substr(j, i-j)) != dict.end()) {
                  canBreak[i] = canBreak[j];
              } j--;
          }
      }
      return canBreak[n];
  }
  ```

### ***[Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)***:
- ***Problem Desc***: given unsorted arr, find len of longest possible increasing subsequence
- ***Brute, recursive, each elem can exist or not exist [O(2<sup>n</sup>) time | O(n) space]***
- ***iterate and check the LIS len at the curr elem comparing it with the elems before it and their LIS lens [O(n<sup>2</sup>) time | O(n) space]***:
  ```cpp
  int lengthOfLIS(vector<int>& nums) {
      int n = nums.size(), ans=1; vector<int> lisLen(n, 1);
      for (int i=0; i<n; ++i) {
          for (int j=0; j<i; ++j) 
              if (nums[i] > nums[j]) lisLen[i] = max(lisLen[i], lisLen[j]+1);
          ans = max(ans, lisLen[i]);
      }
      return ans;
  }
  ```
- ***form the LIS, keep going over the arr, if elem > lis end then insert, else replace the one that should be replaced by it [O(n.logn) time | O() space]***:
  - at any point when lower bound replacement happens, the lis seq isn't the actual ans rather it's just sure to expand only in valid cases
    - e.g. 1 3 5 7 .. if 2 comes, it replaces 3.
      - if 9 comes next then it adds to the seq and the actual ans will be 1,3,5,7,9 however we'll have 1,2,5,7,9
      - this ensures instead of 3 we have 2, i.e. the lowest possible value however the seq len is still the valid one
  ```cpp
  int lengthOfLIS(vector<int>& nums) {
      int n = nums.size(); vector<int> lis; lis.push_back(nums[0]);
      for (int i=1; i<n; ++i) {
          if (nums[i] > lis.back()) lis.push_back(nums[i]);
          else lis[lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin()] = nums[i];
      }
      return lis.size();
  }
  ```

### ***[Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)***:
- ***Problem Desc***: given an arr, is it possible to partition it into 2 sub arrs of equal sum
- ***Won't work: sort and sliding window approach***: e.g. [2,3,4,8,9,14] -> 2,4,14 makes the equal sum partition but not possible with sliding window
- ***Memoization - dfs would give 2<sup>n</sup> solution, i.e. each elem can/cannot be part of. Use memoisation with that [O(n<sup>2</sup>) time | O(n<sup>2</sup>) space]***:
  - we memoize if a sum t can be formed from the given array from elems including or after index i (dp[i][t])
  ```cpp
  bool dfs (vector<vector<int>>&dp, vector<int> &nums, int i, int t) {
      if (i>=nums.size() || t<0) return 0;
      if (!t) return 1;
      if (dp[i][t] == -1) {
          dp[i][t] = dfs(dp, nums, i+1, t);
          if (!dp[i][t]) dp[i][t] = dfs(dp, nums, i+1, t-nums[i]);
      }
      return dp[i][t];
  }
  bool canPartition(vector<int>& nums) {
      int n=nums.size(), target = accumulate(nums.begin(), nums.end(), 0); 
      if (target%2) return 0; target>>=1;
      vector<vector<int>> cache(n, vector<int>(target+1, -1));
      return dfs(cache, nums, 0, target);
  }
  ```
- ***make hashset with all possible vals, check if can form target [O(n.sum(n)) time| O(sum(n)) space]***:
  ```cpp
  bool canPartition(vector<int>& nums) {
      int n=nums.size(), target = accumulate(nums.begin(), nums.end(), 0); 
      if (target%2) return 0; target>>=1;
      unordered_set<int> canForm; canForm.insert(0);
      for (int n:nums) {
          unordered_set<int> canFormNext;
          for (int i: canForm) {
              if (i+n == target) return 1;
              canFormNext.insert(i); canFormNext.insert(i+n);
          } canForm = canFormNext;
      }
      return 0;
  }
  ```
- ***instead of hashset, use bitset, each bit specifies if its index can be formed as a sum [O(n) time | O(sum(n)) space]***:
  ```cpp
  bool canPartition(vector<int>& nums) {
      int n=nums.size(), target = accumulate(nums.begin(), nums.end(), 0); 
      if (target%2) return 0; target>>=1;
      bitset<20001> canForm; canForm[0]=1;
      for (int n:nums) canForm |= canForm << n;
      return canForm[target];
  }
  ```
