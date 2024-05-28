// ***Problem Desc***: given arr with -ve, 0, +ve nums, find max prod of a sub array

// ***Brute, calculate all subarrays' products [O(n<sup>2</sup>) time | O(1) space]***

// ***1D dp, iter over arr, store min max for each and calc at curr, reset taken care of [O(n) time | O(n) space]***:
int maxProduct(vector<int>& nums) {
    int n = nums.size(), ans=nums[0]; vector<vector<int>> minMax(n,vector<int>(2));
    minMax[0][0] = minMax[0][1] = nums[0];
    for (int i=1; i<n; ++i) {
        int a = minMax[i-1][0] * nums[i], b = minMax[i-1][1] * nums[i];
        minMax[i][0] = min(min(a, b), nums[i]);
        minMax[i][1] = max(max(a, b), nums[i]);
        ans = max(ans, minMax[i][1]);
    }
    return ans;
}

// ***store only min max from prev iter, don't store arr [O(n) time | O(1) space]***:
int maxProduct(vector<int>& nums) {
    int n = nums.size(), ans, prevMin, prevMax; 
    prevMin = prevMax = nums[0]; ans = prevMax;   
    for (int i=1; i<n; ++i) {
        int a = prevMax * nums[i], b = prevMin * nums[i];
        prevMin = min(min(a, b), nums[i]);
        prevMax = max(max(a, b), nums[i]);
        ans = max(ans, prevMax);
    }
    return ans;
}

/* 
  ***Alternate, calc continuous max prod from left(0) and right(n-1), if in iter prevMax = 0, reset to 1 [O(n) time | O(1) space]***:
    - works as subarr will happen for sure from either left or right -> e.g. [3,-1,4]
*/
int maxProduct(vector<int>& nums) {
    int n = nums.size(), ans=-1e6, prevMax=1; 
    for (int i=0; i<n; ++i) {
        prevMax *= nums[i];
        ans = max(ans, prevMax);
        if (!prevMax) prevMax = 1;
    } prevMax = 1;
    for (int i=n-1; i>=0; --i) {
        prevMax *= nums[i];
        ans = max(ans, prevMax);
        if (!prevMax) prevMax = 1;
    }
    return ans;
}
