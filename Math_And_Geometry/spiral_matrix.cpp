// ***Problem Desc***: print the clockwise spiral order of matrix

// ***have left, right, top, bottom pointers, go L->R (at T), T done so ++, T->B (at R), R--, R->L (at B), B--, B->T (at L), L++; keep going till L<=R & T<=B [O(m.n) time | O(1) space]***:
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans; int m=matrix.size(), n=matrix[0].size();
    for (int l = 0, r = n-1, t = 0, b = m-1; l<=r && t<=b; ) {
        for (int i=l; i<=r; ++i) ans.push_back(matrix[t][i]); t++;
        for (int i=t; i<=b; ++i) ans.push_back(matrix[i][r]); r--;
        if (t<=b) for (int i=r; i>=l; --i) ans.push_back(matrix[b][i]); b--;
        if (l<=r) for (int i=b; i>=t; --i) ans.push_back(matrix[i][l]); l++;
    } return ans;
}
