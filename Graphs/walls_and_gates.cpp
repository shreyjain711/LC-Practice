// ***Problem Desc***: grid has empty rooms (val=INT_MAX), gates (0) and walls(-1); for each empty cell, have to mark distance from nearest gate

// ***BFS from gates, update empty cell each keeping track of loop num as distance; updated cells become the next level for execution [O(m.n) time | O(m.n) space]***:
void wallsAndGates(vector<vector<int>>& rooms) {
    int m = rooms.size(), n = rooms[0].size();
    int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    queue<vector<int>> bfsQ;
    for(int i=0; i<m; ++i) for(int j=0; j<n; ++j) if (!rooms[i][j]) bfsQ.push({i,j});

    while(!bfsQ.empty()) {
        queue<vector<int>> nextLevel;
        while(!bfsQ.empty()) {
            int i = bfsQ.front()[0], j = bfsQ.front()[1]; bfsQ.pop();
            for(int a=0; a<4; ++a){
                int x = i+dx[a], y = j+dy[a];
                if (x>=0 && x<m && y>=0 && y<n && rooms[x][y]==INT_MAX) {
                    rooms[x][y] = rooms[i][j] + 1;
                    nextLevel.push({x,y});
                }
            }
        } bfsQ = nextLevel;
    }
}
