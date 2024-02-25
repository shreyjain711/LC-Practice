// ***Problem Desc***: given a grid, from which cell can rainwater reach both sides (left & top and right & bottom)

// ***from left and right edge do dfs, mark cells where pacific gets flow, same (right and bottom) for atlantic, ans is where both flows possible [O(m.n) time | O(m.n) space]***:
void dfs(int i, int j, vector<vector<bool>>& waterFlow, vector<vector<int>>& heights) {
    waterFlow[i][j] = 1;
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
    for (int a=0; a<4; ++a) {
        int x = i-dx[a], y = j+dy[a];
        if (x < 0 || y < 0 || x >= heights.size() || y >= heights[0].size() 
            || waterFlow[x][y] || heights[i][j] > heights[x][y]) continue;
        dfs(x, y, waterFlow, heights);
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> ans;
    vector<vector<bool>> pacific(m, vector<bool>(n)), atlantic(m, vector<bool>(n));
    for (int i=0; i<m; ++i) {dfs(i, 0, pacific, heights); dfs(i, n-1, atlantic, heights);} 
    for (int i=0; i<n; ++i) {dfs(0, i, pacific, heights); dfs(m-1, i, atlantic, heights);} 
    for (int i=0; i<m; i++) 
        for (int j=0; j<n; j++) 
            if (pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
    return ans;
}
