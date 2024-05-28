// ***Problem Desc***: given list of cash in each house in a line; can't rob 2 adjacent houses; what's max loot possible

// ***keep track of max steal if stolen from curr (=prev no stolen + curr val) and max if not stolen from curr (=max prev steal and no steal) [O(n) time | O(n) space]***:
int rob(vector<int>& nums) {
    int n = nums.size(); vector<vector<int>> dp(n+1, vector<int>(2)); 
    // 0th row for max if stole from this house
    // 1st for if didn't steal from this house
    dp[1][0] = nums[0]; 
    for (int i=2; i<=n; ++i) {
        dp[i][0] = dp[i-1][1] + nums[i-1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
    }
    return max(dp[n][0], dp[n][1]);
}

// ***tracking of only prev index is reqd so use ints and not arr [O(n) time | O(1) space]***:
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(2)); 
    int prevSteal=nums[0], prevNoSteal=0, currSteal=nums[0], currNoSteal=0;
    for (int i=2; i<=n; ++i) {
        currSteal = prevNoSteal + nums[i-1];
        currNoSteal = max(prevSteal, prevNoSteal);
        prevNoSteal = currNoSteal; prevSteal = currSteal;
    }
    return max(currSteal, currNoSteal);
}
