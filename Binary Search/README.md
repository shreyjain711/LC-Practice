### [**Binary Search**](https://leetcode.com/problems/binary-search/): Ologn search on sorted arr
- ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
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

### [**Search a 2D Matrix**](https://leetcode.com/problems/search-a-2d-matrix/): Ologm*logn time, O1 space
- ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
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

### [**Koko Eating Bananas**](https://leetcode.com/problems/koko-eating-bananas/):
- ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```

### [**Find Minimum In Rotated Sorted Array**](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/):
- ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```

### [**Search In Rotated Sorted Array**](https://leetcode.com/problems/search-in-rotated-sorted-array/):
- ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```

### [**Time Based Key Value Store**](https://leetcode.com/problems/time-based-key-value-store/):
- ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```

### [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/):
- ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
  ```
