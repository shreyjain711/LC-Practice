// ***Problem Desc***: given grid, water rises by 1 per time unit; how much time till we can swim from 0,0 to n-1,n-1

// ***minQ+bfs gets us to evaluate the soonest in reach grid cells first and before starting the visit, the curr time gets updated [O(n<sup>2</sup>.logn) time | O(n<sup>2</sup>) space]***:
int swimInWater(vector<vector<int>>& grid) {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int n=grid.size(), t=max(grid[0][0], grid[n-1][n-1]);
    
    vector<vector<bool>> visited(n, vector<bool>(n)); visited[0][0] = 1;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minQ; 
    
    minQ.push({0, 0, 0});
    while (!minQ.empty()) {
        int currT = minQ.top()[0], currX = minQ.top()[1], currY = minQ.top()[2]; 
        minQ.pop(); t = max(t, currT);
        for (int i=0; i<4; ++i) {
            int x = currX+dx[i], y = currY+dy[i];
            if (x==n-1 && y==n-1) return t;
            if (x>=0 && x<n && y>=0 && y<n && !visited[x][y]) 
                {visited[x][y]=1; minQ.push({grid[x][y], x, y});}
        }
    } return t;
}
