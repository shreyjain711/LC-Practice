// ***Problem Desc***: return arr with each elem = prod of all elem except at curr index
// ***brute [O() time | O() space]***: multiply across the array except when i==j
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, 1);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (i!=j) ans[i] *= nums[j];
        }
    }
    return ans;
}

// ***Left multiply then right [O(n) time | O(1) space]***: calc cumulative multiplication from left then, do same from right
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size(), temp = 1;
    vector<int> ans(n, 1);
    for (int i=0; i<n; ++i) {
        ans[i] *= prod;
        temp *= nums[i];
    } temp = 1;
    for (int i = n-1; i>=0; --i) {
        ans[i] *= prod;
        temp *= nums[i];
    }
    return ans;
}
