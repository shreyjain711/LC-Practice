// ***Problem Desc***: given n, place n queens on an nxn grid such that none can kill each other

/*
***backtracking: maintain arr to store col pos, arr pos = row pos; [O(n!) time | O(n<sup>2</sup>) space]***:
  - add in a queen on a possible col val, validate board, if at end, generate board from arr and store 
*/
bool isValidBoard (vector<int>&qPos) {
    for(int i = 0; i<qPos.size(); ++i) {
        int q1c = qPos[i];
        for(int j=i+1; j<qPos.size(); ++j) {
            int q2c = qPos[j];
            int rDiff = abs(i-j), cDiff = abs(q1c - q2c);
            if (!rDiff || !cDiff || cDiff == rDiff) return 0;
        }
    } return 1;
}
vector<string> makeBoard(vector<int>&qPos, int n) {
    string emptyRow = ""; for(int i=0; i<n; ++i) emptyRow += '.';
    vector<string> ans(n, emptyRow);
    for (int i=0; i<n; ++i) ans[i][qPos[i]] = 'Q';
    return ans;
}
void backtrack(int n, vector<int>&qPos, vector<vector<string>> &board) {
    if (!isValidBoard(qPos)) return;
    if (qPos.size() == n) {
        board.push_back(makeBoard(qPos, n));
        return;
    }
    for (int i=0; i<n; i++) {
        qPos.push_back(i); 
        backtrack(n, qPos, board);
        qPos.pop_back();
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> board;
    vector<int> queenPos;
    backtrack(n, queenPos, board);
    return board;
}
