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
- ***Brute [O() time | O() space]***:
- ***[O() time | O() space]***:
  ```cpp
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
