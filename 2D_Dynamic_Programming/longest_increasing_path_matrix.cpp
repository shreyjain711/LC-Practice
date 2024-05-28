// ***Problem Desc***: given matrix, find the longest increasing path 

// ***go across the matrix and cache the results for each cell [O(n.m) time | O(n.m) space]***:
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int dfs(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
    if (dp[i][j]) return dp[i][j];
    for (int d=0; d<4; ++d) {
        int x = i+dx[d], y = j+dy[d];
        if (x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size()) continue;
        if (matrix[x][y] > matrix[i][j])
            dp[i][j] = max(dp[i][j], 1+dfs(x, y, dp, matrix));
    } 
    dp[i][j] = max(dp[i][j],1);
    return dp[i][j];
}
int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m=matrix.size(), n=matrix[0].size(), ans=1; vector<vector<int>> dp(m, vector<int>(n));
    for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) ans = max(ans, dfs(i, j, dp, matrix));
    return ans;
}
