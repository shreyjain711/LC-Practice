// ***Problem Desc***: given prices of stocks for day 0..n-1, tell max profit possible at the end given after selling we have to wait 1 day before next buy

// ***Brute [O(2<sup>n</sup>) time | O(n) space]***: backtracking, if on cool down then can buy or stay on cooldown, if sold then can sell buy or stay in cooldown, if bought then can sell or hold

// ***1D DP, buy[i] = max(cool[i-1]-prices[i], buy[i-1]), cool = cool[i-1], sell[i-1], sold[i] = buy[i-1]+prices [O(n) time | O(n) space]*** 
int maxProfit(vector<int>& prices) {
    int n=prices.size(); vector<vector<int>> dp(3, vector<int>(n+1)); 
    dp[0][0] = 0; dp[1][0] = -prices[0]; dp[2][0] = INT_MIN;
    for (int i=1; i<=n; ++i) {
        dp[0][i] = max(dp[0][i-1], dp[2][i-1]);
        dp[1][i] = max(dp[1][i-1], dp[0][i-1]-prices[i-1]);
        dp[2][i] = dp[1][i-1] + prices[i-1];
    } return max(dp[0][n], dp[2][n]);
}

// ***Storing prev vals in vars instead of arr, first we calc bought as that uses prev bought and cooling vals, then cooling as that uses cooling and sold, then sold [O(n) time | O(1) space]***:
int maxProfit(vector<int>& prices) {
    int n=prices.size(), cooling=0, bought=-prices[0], sold=INT_MIN;
    for (int i=1; i<n; i++) {
        bought  = max(bought, cooling-prices[i]);
        cooling = max(cooling, sold);
        sold    = bought+prices[i];
    } return max(cooling, sold);
}
