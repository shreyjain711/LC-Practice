// ***Problem Desc***: given coins, find num of ways to make up given amount 

// ***Brute [O(c<sup>amount</amount>) time | O(amount) space]***: dfs

// ***dp[i][j] num of ways to make j amount with with coins 0..i, dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]] [O(c.amount) time | O(c.amount) space]***
int change(int amount, vector<int>& coins) {
    sort(begin(coins), end(coins));
    int n = coins.size(), dp[n][amount+1]; memset(dp, 0, sizeof dp); 
    for (int i=0; i<n; ++i) dp[i][0] = 1;
    for (int i=coins[0]; i<=amount; i+=coins[0]) dp[0][i] = 1;
    for (int c=1; c<n; c++) 
        for(int i=0; i<=amount; ++i) 
            dp[c][i] = dp[c-1][i] + ((i-coins[c]>=0) ? dp[c][i-coins[c]] : 0);
    return dp[n-1][amount];
}

// ***Use a 1D array of amount+1 len, don't need to add the numWays till i-1 coin, just add dp[j-coins[i]] if j-coin[i] is +ve [O(c.amount) time | O(amount) space]***:
int change(int amount, vector<int>& coins) {
    sort(begin(coins), end(coins));
    int n = coins.size(), dp[amount+1]; memset(dp, 0, sizeof dp); dp[0] = 1;
    for (int c=0; c<n; c++) 
        for(int i=0; i<=amount; ++i) 
            dp[i] += ((i-coins[c]>=0) ? dp[i-coins[c]] : 0);
    return dp[amount];
}
