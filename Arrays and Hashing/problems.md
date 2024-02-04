# Problem Set

### [Contains duplicate](https://leetcode.com/problems/contains-duplicate/)
  - ***Problem desc***: return true if array contains a duplicate (value appears at least twice) else false
  
  - ***Hashmap [O(n) time | O(n) space]***: keep saving in unordered set
      ```cpp
      bool containsDuplicate(vector<int>& nums) {
          unordered_map<int, bool> m;
          for (int i = 0; i<nums.size(); ++i) {
              if (m.find(nums[i]) != m.end()) return true;
              m[nums[i]] = true;
          }
          return false;
      }```
  - ***Hashset [O(nlogn) time | O(n) space]***: insert into set (or initiate with), insert takes O(logn) time
  - ***Sort and compare [O(n.logn) time | O(1) space]***: sort and compare adjoining elements
      ```cpp
      bool containsDuplicate(vector<int>& nums) {
          sort(nums.begin(), nums.end());
          for (int i = 0; i<nums.size()-1; ++i) 
              if (nums[i] == nums[i+1]) return true;
          return false;
      }
      ```
  - ***Brute [O(n<sup>2</sup>) time | O(1) space]***: pick each element and iterate through next ones
      ```cpp
      bool containsDuplicate(vector<int>& nums) {
          for (int i = 0; i<nums.size(); ++i) {
              for (int j = i+1; j<nums.size(); ++j) {
                  if (nums[i] == nums[j]) return true;
              }
          }
          return false;
      }
      ```
</details>

### [**Valid Anagram**](https://leetcode.com/problems/valid-anagram/): Find if pair of strings have same chars
  - ***Problem Desc***: return true if strings are anagram
  - ***Brute [O(nlogn) time| O(1) space]***: Sort and compare
    ```cpp
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
    ```
  - ***Count Chars and compare [O(n) time | O(1) space]***:
    ```cppp
    bool isAnagram(string s, string t) {
        int count[26]; memset(count, 0, sizeof(count));
        for(char c : s) count[c - 'a']++;
        for(char c : t) count[c - 'a']--;
        for(int i : count) if (i) return false;
        return true;
    }
    ```

### **[Two Sum](https://leetcode.com/problems/two-sum/)**: return indices of elements that add up to a target val, exactly one sol confirmed
  - ***Problem Desc***: which two indexes add to target; only one solution exists
  - ***Brute [O(n<sup>2</sup>) time | O(1) space]***:
    ```cppp
    vector<int> BRUTE_twoSum(vector<int>& nums, int target) {
        for(int i = 0; i<nums.size(); ++i) {
            for(int j = i+1; j<nums.size(); ++j) {
                if (nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {};
    }
    ```

  - ***hashmap [O(n) time | O(n) space]***: keep a hashmap, check if complement of current elem exists, keep adding elem till it doesn't
    ```cpp
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i<nums.size(); ++i) {
            if (m.find(target-nums[i]) != m.end()) 
                return {i, m[target-nums[i]]};
            
            m[nums[i]] = i;
        }
        return {};
    }
    ```
    
### [**Group Anagrams**](https://leetcode.com/problems/group-anagrams/): vector of strings given, make sets of anagrams

### **[Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)**: given n elem, give k most freq (answer unique)

### [**Product of Array Except Self**](https://leetcode.com/problems/product-of-array-except-self/)

### **[Valid Sudoku](https://leetcode.com/problems/valid-sudoku/)**:

### **[Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/)**: get an arr of strs, each str can have any character. Serialize it into a single string and then decode it as well

### **[Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/):** given arr, find longest consecutive seq possible (i.e. if arr was sorted)
