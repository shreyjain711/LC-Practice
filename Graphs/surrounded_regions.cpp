// ***Problem Desc***: capture all islands that are covered by Xs on all 4 sides

// ***only Os that will survive are islands that are touching the edges, do dfs from edges on Os, turn rest to Xs [O(m.n) time | O(m.n) space]***:
void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& board) {
    if (i<0 || i>= board.size() || j<0 || j>= board[0].size()
        || board[i][j] == 'X' || visited[i][j]) return;
    visited[i][j] = 1;
    int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    for(int a=0; a<4; ++a)
        dfs(i+dx[a], j+dy[a], visited, board);
}
void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));

    for (int i=0; i<m; ++i) {dfs(i, 0, visited, board); dfs(i, n-1, visited, board);}
    for (int i=0; i<n; ++i) {dfs(0, i, visited, board); dfs(m-1, i, visited, board);}

    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            if (!visited[i][j]) board[i][j] = 'X';
    return;
}
