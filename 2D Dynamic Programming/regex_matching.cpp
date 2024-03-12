// ***Problem Desc***: given a string s and regex pattern p, check if s is a match

// ***Brute [O(2<sup>n+m</sup>) time | O(n) space]***: backtracking with checking if each char of the string is to be taken as part of current pattern variable

/*
***cache the results of backtracking  [O(n.m) time | O(n.m) space]***
  - if p end, s also end
  - if last char p then check match
  - else if next *, skip * || incl char and then (skip * || not skip *)
  - else check for curr char match and continue
*/
bool dfs (int i, int j, string &s, string &p, vector<vector<int>>&dp) {
    if (i>s.size()) return 0;
    if (dp[i][j] == -1) {
        if (j==p.size()) dp[i][j] = i==s.size();
        else if (j==p.size()-1) {
            dp[i][j] = i==s.size()-1 && (s[i]==p[j] || p[j]=='.');
        } else if (p[j+1] == '*') {
            dp[i][j] = dfs(i, j+2, s, p, dp) || 
                        ((p[j]=='.' || s[i]==p[j]) && 
                            (dfs(i+1, j, s, p, dp) || dfs(i+1, j+2, s, p, dp)));
        } else {
            dp[i][j] = (s[i]==p[j] || p[j]=='.') && dfs(i+1, j+1, s, p, dp);
        }
    } return dp[i][j];
}
bool isMatch(string s, string p) {
    vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1,-1));
    return dfs(0, 0, s, p, dp);
}
