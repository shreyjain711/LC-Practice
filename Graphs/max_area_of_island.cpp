// ***Problem Desc***: given grid with islands (represented by 1s), find the max aread of island 
// ***Go across grid, dfs from each, keep track of visited islands to avoid revisiting and return the addition of dfs from all 4 sides [O(m.n) time | O(m.n) space]***:
int dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
    if (i<0 || j<0 || i>=grid.size() || j>= grid[0].size() || 
        grid[i][j] != 1 || visited[i][j]) return 0;
    visited[i][j] = 1;

    return 1 + dfs(i+1, j, visited, grid) + dfs(i, j+1, visited, grid)
            + dfs(i-1, j, visited, grid) + dfs(i, j-1, visited, grid);
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            ans = max(ans, dfs(i, j, visited, grid));
    return ans;    
}
