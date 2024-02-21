// ***Problem Desc***: given a word and a crossword board, find if it exists anywhere
/*
***backtracking: traverse over grid, dfs from each cell, if letter of string matches then continue dfs, keep track of visited  [O(m.n.3<sup>len</sup>) time | O(len) space]***:
  - optimization: reverse word if its last letter occurs less frequently than the first -> few dfs calls this way
*/

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
bool backtrack(int i, int j, int &m, int &n, int si, string &word,
                vector<vector<bool>> &visited, vector<vector<char>>&  board) {
    if (si == word.size()) return 1;
    if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || board[i][j] != word[si]) return 0;
    for (int a=0; a<4; ++a) {
        visited[i][j] = 1;
        if (backtrack(i+dx[a], j+dy[a], m, n, si+1, word, visited, board)) return 1;
        visited[i][j] = 0;
    }
    return 0;
}
bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();

    // optimization: reverse word if its last letter 
    // occurs less frequently than first letter
    int len = word.size(), firstChar = 0, lastChar = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(board[i][j] == word[0]) firstChar++;
            else if(board[i][j] == word[len-1]) lastChar++;
        }
    }
    if(firstChar > lastChar) reverse(word.begin(), word.end());

    vector<vector<bool>> visited(m, vector<bool>(n));
    for (int i=0; i<m; ++i) 
        for (int j=0; j<n; ++j) 
            if (backtrack(i, j, m, n, 0, word, visited, board)) 
                return 1;
    return 0;
}
