// ***Problem Desc***: given string w1, find min steps reqd to make it w2 -> steps are insert, del, replace

// ***Brute [O(3<sup>n</sup>) time | O(n1) space]***: backtracking, at each step can either replace if needed or insert/del from w1

// ***Memoising, can store min dist from index i1,i2; min dist = replace (not if match) i.e. i1+1,i2+1 OR insert i.e. i2+1 OR del i.e. i1+1 [O(n1.n2) time | O(n1.n2) space]***:
int dfs (int i1, int i2, string &w1, string &w2, vector<vector<int>> &dp) {
    if (i1==w1.size()) dp[i1][i2] = w2.size()-i2;      // insert remaining
    else if (i2==w2.size()) dp[i1][i2] = w1.size()-i1; // delete extra
    else if (dp[i1][i2] != -1) return dp[i1][i2];      // return cached
    else {
        dp[i1][i2] = min(
                        (w1[i1]==w2[i2]?0:1) + dfs(i1+1, i2+1, w1, w2, dp),
                        min(1+dfs(i1+1, i2, w1, w2, dp), 1+dfs(i1, i2+1, w1, w2, dp))
                    ); // replace (not if match) OR delete/insert
    } return dp[i1][i2];
}
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1,-1));
    return dfs (0, 0, word1, word2, dp);
}

// ***2D, dp[i][j] = min dist w1 0..i1, w2 0..i2; if chars same, =i-1,j-1, if replace +1 to same, if del +1 to i,j-1, if add +1 to i-1,j [O(n1.n2) time | O(n1.n2) space]***:
int tabular (string &w1, string &w2, vector<vector<int>> &dp) {
    int l1=w1.size(), l2=w2.size();
    for (int i=0; i<=l1; i++) dp[i][0] = i;
    for (int i=0; i<=l2; i++) dp[0][i] = i;

    for (int i1=1; i1<=l1; i1++) {
        for (int i2=1; i2<=l2; i2++) {
            dp[i1][i2] = min(
                            (w1[i1-1]==w2[i2-1]?0:1) + dp[i1-1][i2-1],
                            1+min(dp[i1][i2-1], dp[i1-1][i2])
                        );
        }
    } return dp[l1][l2];
}
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1,-1));
    return tabular(word1, word2, dp);
}
