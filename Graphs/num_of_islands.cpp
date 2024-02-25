// ***Problem Desc***: count num of islands on a grid
// ***Go across grid, dfs from each, keep track of visited islands to avoid revisiting and count the number of successful dfs [O(m.n) time | O(m.n) space]***:
bool dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid) {
    if (i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || 
        grid[i][j] != '1' || visited[i][j]) return 0;
    visited[i][j] = 1;
    dfs(i+1, j, visited, grid); dfs(i, j+1, visited, grid);
    dfs(i-1, j, visited, grid); dfs(i, j-1, visited, grid);
    return 1;
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            if (dfs(i, j, visited, grid)) 
                ans++;
    return ans;
}
