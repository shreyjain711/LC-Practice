// ***Problem Desc***: given 2 strings, s1 and s2, determine if s3 is formed by interleaving s1 and s2

// ***Brute [O(2<sup>m+n</sup>) time | O(m+n) space]***: backtracking

// ***Caching with backtracking, if the current ind in s1 is eq to i1+i2 in s3 then can go forward there, sim in s2, cache the result [O(m.n) time | O(m.n) space]***
map<pair<int, int>, bool> dp;
bool dfs(int i1, int i2, string &s1, string &s2, string &s3) {
    if (i1==s1.size()&&i2==s2.size()) return 1;
    if (dp.find({i1,i2}) != dp.end()) return dp[{i1,i2}];
    dp[{i1,i2}] = 0;
    if (i1<s1.size() && s1[i1] == s3[i1+i2]) dp[{i1, i2}] |= dfs(i1+1, i2, s1,s2,s3);
    if (i2<s2.size() && s2[i2] == s3[i1+i2]) dp[{i1, i2}] |= dfs(i1, i2+1, s1,s2,s3);
    return dp[{i1,i2}];
}
bool isInterleave(string s1, string s2, string s3) {
    if (s1.size()+s2.size() != s3.size()) return 0;
    return dfs(0,0,s1,s2,s3);
}

/*
***go from back to front, dp[i][j] = 1 if i..m and j..n makes up i+j..m+n [O(m.n) time | O(m.n) space]***
  - dp[i][j] = 1 if s1[i] matches and dp[i+1][j] was true
  - Or if s2[j] matches and dp[i][j+1] was true
*/
bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), dp[n1+1][n2+1];
    if (n1+n2!=s3.size()) return 0;
    memset(dp, 0, sizeof dp); dp[n1][n2] = 1;
    for (int i=n1; ~i; --i) {
        for (int j=n2; ~j; --j) {
            if (i<n1 && s1[i]==s3[i+j] && dp[i+1][j]) dp[i][j] = 1;
            if (j<n2 && s2[j]==s3[i+j] && dp[i][j+1]) dp[i][j] = 1;
        }
    } return dp[0][0];
}

// ***Don't need to keep results in grid, we go over the same array repeatedly [O(m.n) time | O(n) space]***:
bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), dp[n2+1];
    if (n1+n2!=s3.size()) return 0;
    memset(dp, 0, sizeof dp); dp[n2] = 1;
    for (int i=n1; ~i; --i) 
        for (int j=n2; ~j; --j) 
            if (!dp[j] && j<n2 && s2[j]==s3[i+j] && dp[j+1]) dp[j] = 1;
    return dp[0];
}
