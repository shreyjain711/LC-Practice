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
  - ***Problem Desc***: array, unsorted, find unique combinations of 3 elem adding to 0
  - ***Brute [O(n<sup>3</sup>) time | O(1) space]***: pick each one and try; 3rd degree nesting loops -> this will still give repeat triplets
  - ***Sort, pick first and rest is two sum ii [O(n<sup>2</sup>) time | O(1) space]***:
    - sort to ensure no repeats, for first elem, go over each
    - stop going once hit a positive num since two nums greater than that can't make sum 0
    - do not pick a first elem if its previous is equal as for this first value, all pairs will already be accounted for
    - for the next two elem, in the rest of the array, use two pointer approach as in two sum ii
    - when match found, move left pointer enough so that it's not the same as the value where the match happened
      - need not move right as well as that'll automatically adjust to ensure no repeat value
    ```cpp
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i<n; ++i) {
            if (nums[i] > 0) break;
            if (i>0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i], l = i+1, r = n-1;
            while (l<r) {
                int tempSum = nums[l]+nums[r];
                if (tempSum < target) l++;
                else if (tempSum > target) r--;
                else {
                    ans.push_back({-target, nums[l++], nums[r--]});
                    while(nums[l] == nums[l-1] && l<r) l++;
                }
            }
        }
        return ans;
    }
    ```

### **[Container with Most Water](https://leetcode.com/problems/container-with-most-water/)**: bars of diff heights give, find biggest container they can make
  - ***Problem Desc***: each pos has a wall, using two walls from the whole array, what's the greatest volume container that can be formed
  - ***Brute [O(n<sup>2</sup>) time | O(1) space]***: try each wall with other
  - ***[O(n) time | O(1) space]***: in each turn, either - move left forward if its lower than the right else move right backwards. Chaning to smaller wall offers possibility of a higher volume
    ```cpp
    int maxArea(vector<int>& height) {
        int maxArr = 0, i = 0, j = height.size()-1;
        while (i<j) {
            maxArr = max(maxArr, min(height[i], height[j]) * (j-i));
            if (height[i] < height[j]) ++i;
            else --j;
        }
        return maxArr;
    }
    ```

### **[Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)**: normal variant, height of indices given in arr, find trapped water
  - ***Problem Desc***: each location in an array is a wall of the given height -> what's the water that will be trapped if it were to rain an infinite amount
  - ***Brute [O(n) time | O(n) space]***: get max on left and max on right and their min is the height that can be retained ata pos
    ```cpp
    int trap(vector<int>& height) {
        int n = height.size(), minWall[n], ans = 0;
        memset(minWall, 0, sizeof(minWall));

        for (int i = 1; i<n-1; ++i) 
            minWall[i] = max(height[i-1], minWall[i-1]);
        
        for (int i = n-2; i>=0; --i)
            minWall[i] = min(minWall[i], max(height[i+1], minWall[i+1]));

        for (int i = 0; i<n; ++i) {
            cout << i << " " << minWall[i] << " " << max(0, minWall[i]-height[i]) << endl;
            ans += max(0, minWall[i]-height[i]);
        }
        
        return ans;
    }
    ```
  - ***[O(n) time | O(1) space]***: start from pointers on both ends, if left pointer's prev maxLeft is less than maxRight then max water retention would be as per maxLeft, no need to calc till curr position from the right side as well
    ```cpp
    int trap(vector<int>& h) {
        int n = h.size(), ans = 0;
        int l = 1, r = n-2, mL = h[0], mR = h[n-1];
        
        while (l<=r) {
            if (mL < mR) {
                ans += max(0, mL-h[l]);
                mL = max(mL, h[l]);
                l++;
            } else {
                ans += max(0, mR-h[r]);
                mR = max(mR, h[r]);
                r--;
            }
        }
        
        return ans;
    }
    ```
