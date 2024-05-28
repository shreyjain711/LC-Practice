// ***Problem Desc***: starting from 0,0 go to m,n; can go down or right, how many unique paths possible

// ***Brute [O((m+n)! / m!.n!) time | O((m+n)<sup>2</sup>) space]***: backtracking, go on each path

// ***store num of ways to reach each row and keep on iteratively calculating with reference reln dp[i][j] = dp[i-1][j] + dp[i][j-1] [O(m.n) time | O(n) space]***
int uniquePaths(int m, int n) {
    vector<int> curr(n, 1), next(n, 1);
    for (int i=1; i<m; ++i) {
        for(int j=1; j<n; j++) {
            next[j] = next[j-1] + curr[j];
        } curr = next;
    } return curr[n-1];
}
