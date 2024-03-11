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

/*
***For incr len of t, we keep going over s; we store for curr len of t and prev; c[i] = c[i-1], if s[i]==t[j] then +p[i-1] [O(s.t) time | O(s.t) space]***
  - c[i] = c[i-1] -> dp[si][ti] = dp[si+1][ti] i.e. if I could form X subseq till the prev char in s then the current non-matching char will keep the count same
  - if the current char of s is matching the curr last char of t then using this char,
    - we can have successful subseqs that'll be equal to the num possible without the curr chars, i.e. p[i-1]
*/
int numDistinct(string s, string t) {
    int m=s.size(), n=t.size(); vector<int> curr(m+1), prev(m+1, 1);
    for (int j=1; j<=n; ++j) {
        for (int i=1; i<=m; ++i) {
            curr[i] = curr[i-1]%(int)1e9 + (s[i-1]==t[j-1] ? prev[i-1]%(int)1e9 : 0);
        } prev = curr;
    }
    return curr[m];
}
