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
- ***Problem Desc***: str has only upper case chars. Given k, find longest substr of only one letter that can be formed with k replacements 
- ***Brute [O(n<sup>2</sup>) time | O(1) space]***: try each substr
- ***grow window till condition met, move along if not met, grow when met again [O(n) time | O(1) space]***:
  - optimization #1: no need to check for max count letter
    - since in one iteration only this letter's count is increasing so only this letter can be the contender for maxCount
  - optimization #2: move window along, no need to shrink
    - decreasing window size by only one ensure the window size remains same
    - window grows and it moves along the string till it can grow again
    - No need to decrease window size with while loop since ans can be a window bigger in size than ones already detected
  ```cpp
  int characterReplacement(string s, int k) {
      int counts[26]; memset(counts, 0, sizeof(counts));
      int j = 0, res = 0, maxCount = 0;
      for (int i = 0; i < s.size(); i++) {
          counts[s[i]-'A']++;

          // optimization #1: no need to check for max count letter
          maxCount = max(maxCount, counts[s[i]-'A']); 

          // optimization #2: move window along, no need to shrink
          if (i-j+1 - maxCount > k) counts[s[j++]-'A']--;
          
          res = max(res, i-j+1);
      }
      return res;
  }
  ```

### [Permutation In String](https://leetcode.com/problems/permutation-in-string/):
- ***Problem Desc***: given s1 and s2. check if a permutation of s1 exists in s2 as a substring
- ***Brute [O(s1.s2) time | O(1) space]***: check each s1 length substring for a match
- ***Make a window of size s1 on s2, keep moving till match found [O(s1+s2) time | O(1) space]***:
  ```cpp
  bool compareCounts(vector<int> &c1, vector<int> &c2) {
      for (int i=0; i<26; ++i) if (c1[i] != c2[i]) return 0;
      return 1;
  }

  bool checkInclusion(string s1, string s2) {
      if (s1.size() > s2.size()) return 0;
      vector<int> c1(26), c2(26);
      for (char c: s1) c1[c-'a']++;
      for (int i = 0; i<s1.size(); ++i) c2[s2[i]-'a']++;
      if (compareCounts(c1, c2)) return 1;

      for (int i = s1.size(); i<s2.size(); i++) {
          c2[s2[i]-'a']++; c2[s2[i-s1.size()]-'a']--;
          if (compareCounts(c1, c2)) return 1;
      }
      return 0;
  }
  ```

### [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/):
- ***Problem Desc***: find substring in s that has all chars of str t
- ***Brute [O(n<sup>3</sup>) time | O(1) space]***: try every substring for every char count match
- ***track nums of charCounts that curr window has and shrink or grow as per haves vs needs[O(n) time | O(1) space]***:
  - hashmap to track letters in t (not vector as that doesn't tell if a letter existed or not
  - size of map = needed; init haves = 0
  - track minLen and start point (don't save string it will exceed memory if too long)
  - start i, j from 0
    - if haves == needed then shrink
      - if curr j ptr's char in map, upadte counter and if counter turned negative then one need unmet so haves--
    - else
      - if i's char in map and on incrementing counter its value hits 0 then a need met and haves++
    - check again if haves==needed and minLen > currLen
      - set minLen and start vals
  ```cpp
  string minWindow(string s, string t) {
      unordered_map<char, int> ctr;
      for (auto i: t) ctr[i]--;
      int haves = 0, needed = ctr.size(), minLen = s.length()+1, start = -1;
      for (int i = 0, j = 0; i<s.size() || haves == needed; ) {
          if (haves == needed) { // shrink
              if (ctr.find(s[j]) != ctr.end()) {
                  ctr[s[j]]--; if (ctr[s[j]] < 0) haves--;
              } j++;
          } else {
              if (ctr.find(s[i]) != ctr.end()) {
                  ctr[s[i]]++; if (ctr[s[i]] == 0) haves++;
              } i++;
          }
          if (haves == needed && minLen > i-j) {minLen = i-j; start = j;}
      }
      return (start!=-1) ? s.substr(start, minLen) : "";
  }
  ```

### [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/):
- ***Problem Desc***: a window of size k slides over an array of size n. for each window give its max element
- ***Brute [O(k.(n-k)) time | O(1) space]***: for each window check max linearly
- ***once a max elem seen, then the ones smaller before it are no longer of use[O(n) time | O(k) space]***:
  - maintain a deque, a monotonically decreasing deque
    - we push to its back and get ans from the front
  - firstly, we push the curr elem (start i, j from 0)
    - first pop while the back elem is < the curr elem
  - then we push in the elem
  - then if front elem no longer in the window then we remove it
    - no need for while since only one such elem can be there in an iter
  ```cpp
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int> q; // no need to store both val and i, get val from nums
      vector<int> ans;
      for (int i = 0, j = 0; i<nums.size(); i++) {
          while (q.size() && nums[q.back()] < nums[i]) q.pop_back();
          q.push_back(i);
          if (q.size() && q.front() < j) q.pop_front();
          if (i >= k-1) {
              ans.push_back(nums[q.front()]); j++;
          }
      }
      return ans;
  }
  ```
