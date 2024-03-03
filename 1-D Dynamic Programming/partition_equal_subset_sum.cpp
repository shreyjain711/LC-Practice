// ***Problem Desc***: given an arr, is it possible to partition it into 2 sub arrs of equal sum

// ***Won't work: sort and sliding window approach***: e.g. [2,3,4,8,9,14] -> 2,4,14 makes the equal sum partition but not possible with sliding window

/*
***Memoization - dfs would give 2<sup>n</sup> solution, i.e. each elem can/cannot be part of. Use memoisation with that [O(n<sup>2</sup>) time | O(n<sup>2</sup>) space]***:
  - we memoize if a sum t can be formed from the given array from elems including or after index i (dp[i][t])
*/
bool dfs (vector<vector<int>>&dp, vector<int> &nums, int i, int t) {
    if (i>=nums.size() || t<0) return 0;
    if (!t) return 1;
    if (dp[i][t] == -1) {
        dp[i][t] = dfs(dp, nums, i+1, t);
        if (!dp[i][t]) dp[i][t] = dfs(dp, nums, i+1, t-nums[i]);
    }
    return dp[i][t];
}
bool canPartition(vector<int>& nums) {
    int n=nums.size(), target = accumulate(nums.begin(), nums.end(), 0); 
    if (target%2) return 0; target>>=1;
    vector<vector<int>> cache(n, vector<int>(target+1, -1));
    return dfs(cache, nums, 0, target);
}

// ***make hashset with all possible vals, check if can form target [O(n.sum(n)) time| O(sum(n)) space]***:
bool canPartition(vector<int>& nums) {
    int n=nums.size(), target = accumulate(nums.begin(), nums.end(), 0); 
    if (target%2) return 0; target>>=1;
    unordered_set<int> canForm; canForm.insert(0);
    for (int n:nums) {
        unordered_set<int> canFormNext;
        for (int i: canForm) {
            if (i+n == target) return 1;
            canFormNext.insert(i); canFormNext.insert(i+n);
        } canForm = canFormNext;
    }
    return 0;
}

// ***instead of hashset, use bitset, each bit specifies if its index can be formed as a sum [O(n) time | O(sum(n)) space]***:
bool canPartition(vector<int>& nums) {
    int n=nums.size(), target = accumulate(nums.begin(), nums.end(), 0); 
    if (target%2) return 0; target>>=1;
    bitset<20001> canForm; canForm[0]=1;
    for (int n:nums) canForm |= canForm << n;
    return canForm[target];
}
