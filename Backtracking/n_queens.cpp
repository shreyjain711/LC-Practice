// ***Problem Desc***: given n, place n queens on an nxn grid such that none can kill each other

// ***backtracking: maintain board, go over each row and in each row each col, add in a queen if board still valid, continue; (check only prev i,same j & diagonals up-left and up-right [O(n!) time | O(n<sup>2</sup>) space]***:
vector<vector<string>> solveNQueens(int n) {
    if (n==2||n==3) return {};
    vector<vector<string>> boards; vector<string> board(n, string(n,'.'));
    backtrack(0, n, board, boards); return boards;
}
void backtrack(int i, int &n, vector<string> &board, vector<vector<string>> &boards) {
    if (i==n) {boards.push_back(board); return;}
    for (int j=0; j<n; j++) {
        board[i][j] = 'Q';
        if (isValid(i, j, board)) backtrack(i+1, n, board, boards);
        board[i][j] = '.';
    }
}
bool isValid(int &i, int &j, vector<string>&board) {
    int n = board.size();
    for (int d=1; d<=i; d++) {
        if (board[i-d][j]=='Q') return 0;
        if (j-d>=0 && board[i-d][j-d] == 'Q') return 0;
        if (j+d<n && board[i-d][j+d] == 'Q') return 0;
    } return 1;
}
