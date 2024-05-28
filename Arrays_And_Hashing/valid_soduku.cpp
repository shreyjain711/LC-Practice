// ***Problem Desc***: return arr with each elem = prod of all elem except at curr index

// ***brute [O((m+n).m.n time) | O(1) space]***: for each element check if row, col and block is valid

// ***hashset [O(m.n) time | O(m+n) space]***: make a hashset for each of the 9 rows and cols and the blocks too
bool isValidSudoku(vector<vector<char>>& board) {
    int counter = 0;
    vector<unordered_set<int>> rows(9), columns(9), blocks(9);
    
    for(int i = 0; i<9; ++i) {
        for(int j = 0; j<9; ++j) {
            if (board[i][j] != '.') {
                counter++;
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                blocks[3*(i/3) + j/3].insert(board[i][j]);
            }
        }
    }

    int c_r = 0, c_c = 0, c_b = 0;
    for (int i = 0; i<9; ++i) {
        c_r += rows[i].size();
        c_c += columns[i].size();
        c_b += blocks[i].size();
    }

    return c_r == counter && c_c == counter && c_b == counter;
}

// ***bit manipulation [O(m.n) time | O(m+n) space]***:
bool isValidSudoku(vector<vector<char>>& board) {
    vector<int> rows(9,0), columns(9,0), blocks(9,0);
    
    for(int i = 0; i<9; ++i) {
        for(int j = 0; j<9; ++j) {
            if (board[i][j] == '.') continue;
            int t = board[i][j]-'0';

            if (rows[i] & 1<<t) return false;
            rows[i] |= 1<<t;
            
            if (columns[j] & 1<<t) return false;
            columns[j] |= 1<<t;
            
            if (blocks[3*(i/3) + j/3] & 1<<t) return false;
            blocks[3*(i/3) + j/3] |= 1<<t;
        }
    }

    return 1;
}
