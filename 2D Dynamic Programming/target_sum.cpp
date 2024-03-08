// ***Problem Desc***: given a list of nums, either use them as +ve or -ve to reach the target; how many ways to form target

// ***Brute [O(2<sum>n</sum>) time | O(n) space]***: backtracking, use as +ve and then -ve, at end see if target reached

// ***memoisation, store num ways to reach a sum t from nums indexed i..n-1, modified knapsack as decision is +ve/-ve (not 1/0) [O(n.target) time | O(n.target) space]***:
map<pair<int,int>, int> dp;
int dfs(int i, int t, vector<int>& nums) {
    if (i==nums.size()) { return (t==0);}
    if (dp.find({i,t})!=dp.end()) return dp[{i,t}];
    dp[{i,t}] = dfs(i+1, t-nums[i], nums) + dfs(i+1, t+nums[i], nums);
    return dp[{i,t}];
}
int findTargetSumWays(vector<int>& nums, int target) {
    return dfs(0, target, nums);
}

/*
***Math makes task to find subset of nums to add to (target+sumAll)/2; becomes 0-1 knapsack []***:
  - Sum(+ve) - Sum(-ve) = target -> adding sumAll (i.e. sum(+ve) + sum(-ve)) to both sides -> 2 * sum(+ve) = target + sumAll -> sum(+ve) = (target + sumAll)/2
  - so t+sumAll can't be odd or sumAll can't be < t
  - go decreasing order in inner loop, otherwise would end up using same coin multiple times
*/
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(begin(nums), end(nums), 0);
    if (sum<target || (target+sum)%2) return 0;
    target = (target+sum)>>1;
    int dp[target+1]; memset(dp, 0, sizeof dp); dp[0]=1;
    for (int n:nums)
        for (int i=target; i>=n; --i) 
        // go opp, target..n, since 0/1, if forward, will be unbounded
            dp[i] += dp[i-n];
    return dp[target];
}
