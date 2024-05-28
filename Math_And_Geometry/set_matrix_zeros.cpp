// ***Problem Desc***: given matrix of size m,n -> for any cell 0, set its entire row and col 0

// ***Store flags in separate row col arrs and then apply the flag [O(m.n) time | O(m+n) space]***:
void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size(), n=matrix[0].size(); bitset<200>rows, cols;
    for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (!matrix[i][j]) {rows[i]=1; cols[j]=1;}
    for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (rows[i] || cols[j]) matrix[i][j] = 0;
}
  
// ***find if first row and col have a 0, i.e. they will be 0, then use them as flag; if a cell 0,i = 0 then all cells in the row made 0, at end make first row col 0s [O(m.n) time | O(1) space]***:
void setZeroes(vector<vector<int>>& matrix) {
    int m=matrix.size(), n=matrix[0].size(); bool isFirstRow0=0, isFirstCol0=0;
    for (int i=0; i<m; ++i) if (!matrix[i][0]) isFirstRow0=1;
    for (int i=0; i<n; ++i) if (!matrix[0][i]) isFirstCol0=1;

    for (int i=1; i<m; ++i) for(int j=1; j<n; ++j) if(!matrix[i][j]) matrix[0][j]=matrix[i][0]=0;
    for (int i=1; i<m; i++) for(int j=1;j<n;j++) if(!matrix[i][0]||!matrix[0][j]) matrix[i][j]=0;

    if (isFirstRow0) for (int i=0; i<m; ++i) matrix[i][0] = 0;
    if (isFirstCol0) for (int i=0; i<n; ++i) matrix[0][i] = 0;
}
