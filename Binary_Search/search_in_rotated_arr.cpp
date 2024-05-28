// ***Brute [O(n) time | O(1) space]***: linear search

/*
***Binary[O(logn) time | O(1) space]***:
  - check if mid is the target, return if yes
  - if right half is sorted
    - if target in that range, move there, else move to the left half
  - else
    - if target in the sorted left's range, move there else to the right
*/

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
