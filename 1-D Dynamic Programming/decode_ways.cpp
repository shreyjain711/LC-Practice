// ***Problem Desc***: given a string containing only digits, find num of ways it can be read; 1 = A, so 0 can't be read

// ***1D dp, dp[i] = num of ways to decode str till ith pos (non-incl); dp[i] = dp[i-1](if i can be decoded) + dp[i-2] (if i-2 i-1 can be dec) [O(n) time | O(n) space]***:
bool canDecode(string s, int i, int len) {
    if (s[i] == '0') return 0;
    if (len == 2 && (s[i]>'2' || s[i] == '2' && s[i+1] > '6')) return 0;
    return 1;
}
int numDecodings(string s) {
    int n = s.size(), decos[n+1]; memset(decos, 0, sizeof decos);
    if (!canDecode(s, 0, 1)) return 0; 
    decos[0] = 1; decos[1] = 1;
    for (int i=2; i<=n; i++) {
        if (canDecode(s, i-1, 1)) decos[i] += decos[i-1];
        if (canDecode(s, i-2, 2)) decos[i] += decos[i-2];
        if (!decos[i]) return 0;
    }
    return decos[n];
}
