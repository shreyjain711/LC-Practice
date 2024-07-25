// ***Problem Desc***: given string s and t, find num of total subseq of s that can form t

// ***Brute [O(2<sup>s</sup>) time | O(s) space]***: bracktracking, for each char in s, we either include it if it's the next char in the t string or we don't in our subseq

// ***Memoisation, cache the outputs from the brute technique [O(s.t) time | O(s.t) space]***
int dfs (int si, int ti, string &s, string &t, vector<vector<int>>&dp) {
    if (ti==t.size()) return 1;
    if (s.size()-si < t.size()-ti) return 0;
    if (dp[si][ti] != -1) return dp[si][ti];
    dp[si][ti] = dfs(si+1, ti, s, t, dp);
    if (t[ti] == s[si]) dp[si][ti] += dfs(si+1, ti+1, s, t, dp);
    return dp[si][ti];
}
int numDistinct(string s, string t) {
    vector<vector<int>> dp(s.length()+1, vector<int>(t.length()+1, -1));
    return dfs(0, 0, s, t, dp);
}

// ***dp[i][j] = dp[i-1][j] + if s[i-1]==t[j-1] then +dp[i-1][j-1] [O(s.t) time | O(s.t) space]***: incr s' len and each time val can be as much as it was with s-1 and t or if last char of both match then s-1, t-1 too
int numDistinct(string s, string t) {
    int m=s.size(), n=t.size(); vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    // return helper(0, 0, s, t, dp);
    for (int i=0; i<=m; i++) dp[i][0]=1;
    for (int i=1; i<=m; i++) 
        for (int j=1; j<=n; j++) 
            dp[i][j] = (dp[i-1][j] + (s[i-1]==t[j-1] ? dp[i-1][j-1] : 0)) % ((int)1e9+7);
    return dp[m][n];
}
