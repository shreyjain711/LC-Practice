// ***Problem Desc***: given n coins of diff value, find min number of coins required to total upto given amount X

// ***1D DP, 0..amount, each cell = min num reqd to form amount; starting from 0, iterate over each coin and mark vals accordingly [O(amount.c) time | O(amount) space]***:
int coinChange(vector<int>& coins, int amount) {
    if (!amount) return 0;
    int dp[amount+1]; memset(dp, 0, sizeof dp);
    for (int i=0; i<=amount; ++i) {
        if (!i || dp[i]) {
            for (int c: coins) {
                long sum = i+(long)c;
                if (sum <= amount) 
                    dp[sum] = dp[sum] ? min(dp[sum], 1+dp[i]) : dp[i]+1;
            }
        }
    }
    return dp[amount] ? dp[amount] : -1;
}
