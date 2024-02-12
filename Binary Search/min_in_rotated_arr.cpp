// ***Problem Desc***: array has only unique values, rotated ```1..n``` times
// ***Brute [O(n) time | O(1) space]***: search linearly

// ***Binary search[O(logn) time | O(1) space]***: go towards the part that isn't sorted (i.e. mid > high)
int findMin(vector<int>& nums) {
    int lo = 0, hi = nums.size()-1, mid, ans = nums[0];
    while (lo <= hi) {
        mid = (hi+lo)/2; ans = min(ans, nums[mid]);
        if (nums[hi] < nums[mid]) lo = mid + 1;
        else hi = mid-1;
    }
    return ans;
}

// ***[Find Mininmum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)***: can have duplicate elements
// ***Binary search[O(logn) time | O(1) space]***: go towards the part that isn't sorted (i.e. mid > high), but when don't know which part is sorted, hi-- e.g. 5,5,1,5,5
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
