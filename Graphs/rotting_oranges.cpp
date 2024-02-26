// ***Problem Desc***: given a grid with oranges, fresh and rotten, find out if and how soon all oranges will be rotted -> fresh ones next to rotten ones rot in 1 min

// ***BFS, keep all rotten oranges in the queue, rot their adjacent fresh oranges and push into Q, keep track of num of times this is done [O(m.n) time | O(m.n) space]***:
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size(), fresh = 0, mins = 0;
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    queue<vector<int>> q;
    
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) 
            if (grid[i][j]==2) q.push({i, j}); 
            else if (grid[i][j]==1) fresh++;
    
    while (!q.empty()) {
        queue<vector<int>> temp; 
        bool anyConverted = 0;
        while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1]; q.pop();
            for (int i=0; i<4; ++i) {
                int a = x+dx[i], b = y+dy[i];
                if (a>=0 && b>=0 && a<m && b<n && grid[a][b]==1) {
                    temp.push({a,b}); grid[a][b]=2; fresh--;
                    anyConverted = 1;
                }
            }
        } q = temp;
        if (anyConverted) mins++;
    }
    return !fresh ? mins : -1;
}
