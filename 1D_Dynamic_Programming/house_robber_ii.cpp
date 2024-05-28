// ***Problem Desc***: houses are in a ring, can't rob adjacent houses

// ***Run sol from 0..n-2 and 1..n-1, since in the best case can include the numbers from only one of the houses at ends [O(n) time | O(1) space]***:
int rob(vector<int>&nums, int start, int end) {
    int robIt=0, leaveIt=0;
    for (int i=start; i<end; ++i) {
        int leaveCurr = max(robIt, leaveIt);
        robIt = nums[i] + leaveIt;
        leaveIt = leaveCurr;
    }
    return max(robIt, leaveIt);
}
int rob(vector<int>& nums) {
    int n = nums.size(); if (n==1) return nums[0];
    return max(rob(nums, 0, n-1), rob(nums, 1, n));
}
