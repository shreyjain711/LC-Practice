### ***[Binary Search](https://leetcode.com/problems/binary-search/)***: Ologn search on sorted arr
- ***Problem Desc***: binary search
- ***Brute [O(n) time | O(1) space]***: search linearly
- ***Binary Search[O(logn) time | O(1) space]***:
  - lo = mid+1 and hi = mid-1 make sure there's no being stuck at the ans
  ```cpp
  int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1, mid;

        while (lo <= hi) {
            mid = lo + (hi-lo)/2;
            if (nums[mid] > target)
                hi = mid-1;
            else if (nums[mid] < target)
                lo = mid+1;
            else return mid;
        }
        return -1;
    }
  ```

### ***[Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)***: Ologm*logn time, O1 space
- ***Problem Desc***: search in a sorted matrix, each row's min is more than last row's max; every row is sorted too
- ***Brute [O(m.n) time | O(1) space]***: search linearly
- ***Search linearly across 0..m*n [O(log(m.n)) time | O(1) space]***: convert linear index to matrix index
  ```cpp
  int getLinear(vector<vector<int>>& matrix, int index) {
      return matrix[index/matrix[0].size()][index%matrix[0].size()];
  }

  bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = matrix[0].size(), lo = 0, hi = m*n-1, mid, t;
      while (lo <= hi) {
          mid = lo + (hi-lo)/2; t = getLinear(matrix, mid);
          if (t < target) lo = mid+1;
          else if (t > target) hi = mid-1;
          else return 1;
      }
      return 0;
  }
  ```
- ***Find right, then right column [O(log(m.n)) time | O(1) space]***: more variables, less neat
  ```cpp
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int m = matrix.size(), n = matrix[0].size();
      int lo_r = 0, hi_r = m-1, lo_c = 0, hi_c = n-1, mid_r, mid_c;
      while (lo_r <= hi_r && lo_c <= hi_c) {
          mid_r = lo_r + (hi_r-lo_r)/2;
          if (matrix[mid_r][lo_c] <= target && matrix[mid_r][hi_c] >= target) {
              mid_c = lo_c + (hi_c-lo_c)/2;
              if (matrix[mid_r][mid_c] < target) lo_c = mid_c + 1;
              else if (matrix[mid_r][mid_c] > target) hi_c = mid_c - 1;
              else return 1;
          } else if (matrix[mid_r][lo_c] > target) hi_r = mid_r - 1;
          else lo_r = mid_r + 1;
      }
      return 0;
  }
  ```

### ***[Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/)***:
- ***Problem Desc***: koko eats k bananas in an hour. has to finish all piles in h hours. time taken for each pile = ceil(pile/speed)
- ***Brute [O(p.max(p)) time | O(1) space]***: try each speed from 1...max(p)
- ***Binary search for the right speed[O(p.log(max(p))) time | O(1) space]***:
  ```cpp
  int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9, mid, ans = 1e9;
        long long t;
        while (lo <= hi) {
            mid = lo + (hi-lo)/2; t = 0;
            for (int p: piles) t += ceil(p/(double)mid);
            if (t <= h) {
                ans = min(ans, mid);
                hi = mid - 1;
            } else lo = mid + 1;
        }
        return ans;
    }
  ```

### ***[Find Minimum In Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)***:
- ***Problem Desc***: array has only unique values, rotated ```1..n``` times
- ***Brute [O(n) time | O(1) space]***: search linearly
- ***Binary search[O(logn) time | O(1) space]***: go towards the part that isn't sorted (i.e. mid > high)
  ```cpp
  int findMin(vector<int>& nums) {
      int l=0, h=nums.size()-1, m;
      while (l<h) {
          m=(l+h)/2;
          if (nums[m]>nums[h]) l=m+1;
          else h=m;
      } return nums[l];
  }
  ```

- ***[Find Mininmum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)***: can have duplicate elements
- ***Binary search[O(logn) time | O(1) space]***: go towards the part that isn't sorted (i.e. mid > high), but when don't know which part is sorted, hi-- e.g. 5,5,1,5,5
  ```cpp
  int findMin(vector<int>& nums) {
      int lo = 0, hi = nums.size()-1, mid, ans = nums[0];
      while (lo <= hi) {
          mid = (hi+lo)/2; ans = min(ans, nums[mid]);
          if (nums[hi] < nums[mid]) lo = mid + 1;
          else if (nums[lo] > nums[mid]) hi = mid-1;
          else hi--;
      }
      return ans;
  }
  ```


### ***[Search In Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)***:
- ***Problem Desc***: 
- ***Brute [O(n) time | O(1) space]***: linear search
- ***Binary[O(logn) time | O(1) space]***:
  - check if mid is the target, return if yes
  - if right half is sorted
    - if target in that range, move there, else move to the left half
  - else
    - if target in the sorted left's range, move there else to the right
  ```cpp
  int search(vector<int>& nums, int target) {
      int lo = 0, hi = nums.size()-1, mid;
      while (lo <= hi) {
          mid = lo + (hi-lo)/2;
          if (nums[mid] == target) return mid;
          
          if (nums[mid] < nums[hi]) {
              if (nums[mid] < target && target <= nums[hi]) lo = mid+1;
              else hi = mid-1;
          } else {
              if (nums[lo] <= target && target < nums[mid]) hi = mid-1;
              else lo = mid+1;
          }
      }
      return -1;
  }
  ```

### ***[Time Based Key Value Store](https://leetcode.com/problems/time-based-key-value-store/)***:
- ***Problem Desc***: for each key, at diff timestamps diff vals will be set. when get called for a particular timestamp, return val at its lower_bound ts
- ***Brute [O(n) time | O(1) space]***: search linearly for the right time
- ***binary search for lower bound [O(logn) time | O(1) space]***:
  ```cpp
  unordered_map<string, vector<pair<int, string>>> cache;
  TimeMap() {
      cache.clear();
  }
  
  void set(string key, string value, int timestamp) {
      cache[key].push_back({timestamp, value});
  }
  
  string get(string key, int timestamp) {
      return search(cache[key], timestamp);

  }

  string search(vector<pair<int, string>> &list, int timestamp) {
      string ans;
      int lo = 0, hi = list.size()-1, mid;
      while (lo <= hi) {
          mid = lo + (hi-lo)/2;
          if (list[mid].first < timestamp) {
              ans = list[mid].second;
              lo = mid + 1;
          } else if (list[mid].first > timestamp) {
              hi = mid - 1;
          } else {
              ans = list[mid].second;
              break;
          }
      }
      return ans;
  }
  ```

### ***[Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/)***:
- ***Problem Desc***: two arrays are sorted, find median if the two were merged
- ***Brute [O(m+n) time | O(m+n) space]***: actually merge the arrays and then find
- ***Binary search for the merge point in arr1, mathematically get arr2's point [O(logn) time | O(1) space]***:
  - make sure arr1 is shorter or equal to arr2
  - after finding m1, determine val of m2 ( = total/2 - m1)
  - then the pts of split will be m1-1, m1 and m2-1, m2 (if they exist, else INT_MIN/MAX)
  - determine if positions aren't median satisfying i.e. if val[m1-1] > val[m2] (move leftwards) or val[m1] < val[m2-1] (move right)
  ```cpp
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      int m=nums1.size(), n=nums2.size(); 
      if (m>n) return findMedianSortedArrays(nums2,nums1);
      int l1=0, h1=m, m1, m2;
      while (l1<=h1) {
          m1 = (h1+l1)/2;
          m2 = (n+m)/2 - m1; 
          int a1 = m1>0 ? nums1[m1-1] : INT_MIN,
              b1 = m1<m ? nums1[m1] : INT_MAX,
              a2 = m2>0 ? nums2[m2-1] : INT_MIN,
              b2 = m2<n ? nums2[m2] : INT_MAX;
          if (a1 > b2) {
              h1 = m1-1;
          } else if (a2 > b1) {
              l1 = m1+1;
          } else {
              return (m+n)%2 ? min(b1, b2) : (max(a1, a2) + min(b1, b2))/2.0;
          }
      } return 0;
  }
  ```
