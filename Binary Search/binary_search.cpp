// ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell

// ***Brute [O(n) time | O(1) space]***: search linearly

// ***Binary Search[O(logn) time | O(1) space]***:
//    - lo = mid+1 and hi = mid-1 make sure there's no being stuck at the ans
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
