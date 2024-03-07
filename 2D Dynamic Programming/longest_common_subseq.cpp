// ***Problem Desc***: given two string, find longest common subseq

// ***dp[i][j] = LCS till 0..i in str1 and 0..j in str2, dp[i][j] = max(dp[i-1][j],dp[i][j-1]) and if str1[i]==str2[j] ->1+dp[i-1][j-1] [O(n1.n2) time | O(n1.n2) space]***
int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size(), n2 = text2.size();
    int lcs[n1][n2]; memset(lcs, 0x0, sizeof lcs);
    lcs[0][0] = text1[0] == text2[0];
    for (int i=1; i<n1; ++i) lcs[i][0] = max((int)(text1[i]==text2[0]), lcs[i-1][0]);
    for (int i=1; i<n2; ++i) lcs[0][i] = max((int)(text1[0]==text2[i]), lcs[0][i-1]);

    for (int i=1; i<n1; ++i) {
        for (int j=1; j<n2; ++j) {
            lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            if (text1[i] == text2[j]) 
                lcs[i][j] = max(1+lcs[i-1][j-1], lcs[i][j]);
        } 
    } return lcs[n1-1][n2-1];
}
