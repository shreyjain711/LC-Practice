# Problem Set

### [Best Time to Buy And Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/):
- ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
- ***Brute [O(n<sup>2</sup>) time | O(1) space]***: for each elem, try every other elem
- ***keep looking for minimum Price and maximum profit at each step[O(n) time | O(1) space]***:
  ```cpp
  int maxProfit(vector<int>& prices) {
      int minPrice = prices[0], profit = 0;
      for (auto p: prices) {
          profit = max(profit, p - minPrice);
          minPrice = min(minPrice, p);
      }
      return profit;
  }

  /*
   * above is a simpler version of the below code
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, maxPrice = INT_MIN, profit = 0;
        for (auto p: prices) {
            if (p < minPrice) {
                if (maxPrice > minPrice) profit = max(profit, maxPrice-minPrice);
                minPrice = p; maxPrice = INT_MIN;
            } maxPrice = max(maxPrice, p);
            profit = max(profit, maxPrice-minPrice);
        }
        return profit;
    }
  */
  ```

### [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/):
- ***Problem Desc***: longest substring where each char appears only once (chars can be other than alphanumeric vals as well)
- ***Brute [O(n<sup>2</sup>) time | O(1) space]***: make substrings starting from each index
- ***extend window while new chars haven't already appeared in it, contract when char repeated[O(n) time | O(1) space]***:
  ```cpp
  int lengthOfLongestSubstring(string s) {
      int n = s.length(), j = 0, maxLen = 0; 
      bitset<256> cache(0); 
      for (int i = 0; i < n; i++) {
          while (cache[s[i]] && j < i) cache[s[j++]] = 0;
          cache[s[i]] = 1;
          maxLen = max(maxLen, (int)cache.count());
          // replacing (i-j+1) with cache.count()
      }
      return maxLen;
  }
  ```    

### [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/):
- ***Problem Desc***:
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```

### [Permutation In String](https://leetcode.com/problems/permutation-in-string/):
- ***Problem Desc***:
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```

### [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/):
- ***Problem Desc***:
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```

### [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/):
- ***Problem Desc***:
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```
