# Problem Set

### **[Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)**: check if str palindrome but consider only alphanumeric chars
  - ***Problem Desc***: string is palin (it has non-alphanumeric characters as well and they don't have to be compared)
  - ***move left and right [O(n) time | O(1) space]***: in each turn, either - move left pointer forward, right pointer backward, or compare
    ```cpp
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        
        while (i<j) {
            if (!isalnum(s[i])) {++i; continue;}
            if (!isalnum(s[j])) {--j; continue;}
            if (toupper(s[i]) != toupper(s[j])) return false;
            i++; j--;
        }
        return true;
    }
    ```

### **[Two Sum II](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)**: array already sorted, exactly one sol exists
  - ***Problem Desc***: array is sorted (non-decreasing order), elems not unique
  - ***Brute [O(n<sup>2</sup>) time | O(1) space]***: compare each elem with another
  - ***Move pointers [O(n) time | O(1) space]***: in each turn, either - move left pointer forward if sum less than target, right pointer backward if sum more, or return pair
    ```cpp
    vector<int> twoSum(vector<int>& nums, int target) {
        int i1 = 0, i2 = nums.size()-1;
        while (i1 < i2) {
            int s = nums[i1]+nums[i2];
            if (s < target) ++i1;
            else if (s > target) --i2;
            else return {i1+1, i2+1};
        }
        return {-1, -1};
    }
    ```

### **[3Sum](https://leetcode.com/problems/3sum/)**: array, unsorted, find unique combinations of 3 elem adding to 0
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
    ```cpp
    
    ```
  - ***[O() time | O() space]***:
    ```cpp
    
    ```

### **[Container with Most Water](https://leetcode.com/problems/container-with-most-water/)**: bars of diff heights give, find biggest container they can make
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
    ```cpp
    
    ```
  - ***[O() time | O() space]***:
    ```cpp
    
    ```

### **[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)**: normal variant, height of indices given in arr, find trapped water
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
    ```cpp
    
    ```
  - ***[O() time | O() space]***:
    ```cpp
    
    ```
