# Problem Set

### ***[Number of Islands](https://leetcode.com/problems/number-of-islands/)***:
- ***Problem Desc***: count num of islands on a grid
- ***Go across grid, dfs from each, keep track of visited islands to avoid revisiting and count the number of successful dfs [O(m.n) time | O(m.n) space]***:
  ```cpp
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
  ```

### ***[Clone Graph](https://leetcode.com/problems/clone-graph/)***:
- ***Problem Desc***: given a undirected graph, clone it
- ***Iterative bfs, clone map maintain and keep pointing according and check if already visited [O(V+E) time | O(V+E) space]***:
  ```cpp
  Node* cloneGraph(Node* node) {
      unordered_map<Node*, Node*> cloneMap;
      unordered_set<Node*> visited;
      queue<Node*> bfs; 
      if (node) bfs.push(node);
      while (!bfs.empty()) {
          Node* curr = bfs.front(); bfs.pop();
          if (visited.find(curr) != visited.end()) continue;
          visited.insert(curr);
          if(cloneMap.find(curr) == cloneMap.end()) cloneMap[curr] = new Node(curr->val);
          for (auto neighbor: curr->neighbors) {
              bfs.push(neighbor);
              if(cloneMap.find(neighbor) == cloneMap.end()) 
                  cloneMap[neighbor] = new Node(neighbor->val);
              cloneMap[curr]->neighbors.push_back(cloneMap[neighbor]);
          }
      }
      return (cloneMap.size()) ? cloneMap[node] : NULL;
  }
  ```
- ***Recursive, check if it already exists in clone map, if not then create clone node, put  in map, set neighbors recursively [O(V+E) time | O(V+E) space]***:
  ```cpp
  unordered_map<Node*, Node*> cloneMap;
  Node* cloneGraph(Node* node) {
      if (!node) return NULL;
      if (cloneMap.count(node)) return cloneMap[node];
      cloneMap[node] = new Node(node->val);
      for (auto neighbor : node->neighbors)
          cloneMap[node]->neighbors.push_back(cloneGraph(neighbor));
      return cloneMap[node];
  }
  ```

### ***[Max Area of Island](https://leetcode.com/problems/max-area-of-island/)***:
- ***Problem Desc***: given grid with islands (represented by 1s), find the max aread of island 
- ***Go across grid, dfs from each, keep track of visited islands to avoid revisiting and return the addition of dfs from all 4 sides [O(m.n) time | O(m.n) space]***:
  ```cpp
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
  ```

### ***[Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/)***: 
- ***Problem Desc***: given a grid, from which cell can rainwater reach both sides (left & top and right & bottom)
- ***from left and right edge do dfs, mark cells where pacific gets flow, same (right and bottom) for atlantic, ans is where both flows possible [O(m.n) time | O(m.n) space]***:
  ```cpp
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
  ```

### ***[Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)***:
- ***Problem Desc***: capture all islands that are covered by Xs on all 4 sides
- ***only Os that will survive are islands that are touching the edges, do dfs from edges on Os, turn rest to Xs [O(m.n) time | O(m.n) space]***:
  ```cpp
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
  ```

### ***[Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)***:
- ***Problem Desc***: given a grid with oranges, fresh and rotten, find out if and how soon all oranges will be rotted -> fresh ones next to rotten ones rot in 1 min
- ***BFS, keep all rotten oranges in the queue, rot their adjacent fresh oranges and push into Q, keep track of num of times this is done [O(m.n) time | O(m.n) space]***:
  ```cpp
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
  ```

### **[Walls And Gates](https://leetcode.ca/all/286.html)**:
- ***Problem Desc***: grid has empty rooms (val=INT_MAX), gates (0) and walls(-1); for each empty cell, have to mark distance from nearest gate
- ***BFS from gates, update empty cell each keeping track of loop num as distance; updated cells become the next level for execution [O(m.n) time | O(m.n) space]***:
  ```cpp
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
  ```

### ***[Course Schedule](https://leetcode.com/problems/course-schedule/)***:
- ***Problem Desc***: given num of courses and list of prerequisties between the courses, determine if doing all possible
- ***Topological sort, when removing a course from Q reduce numCourses to track num left, also check for cycle, return 1 if no courses left [O(n.p) time | O(n.p) space]***:
  ```cpp
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      vector<vector<int>> preReqAL(numCourses); vector<int> inDegree(numCourses);
      for (auto preReq: prerequisites) {
          preReqAL[preReq[0]].push_back(preReq[1]); inDegree[preReq[1]]++;
      }
      queue<int> doable;
      for (int i=0; i<numCourses; ++i) if (!inDegree[i]) doable.push(i);
      while (!doable.empty()) {
          int sz = doable.size();
          for (int i=0; i<sz; ++i) {
              int crs = doable.front(); doable.pop(); numCourses--;
              for (int canDo: preReqAL[crs]) {
                  inDegree[canDo]--;
                  if (!inDegree[canDo]) doable.push(canDo);
                  else if (inDegree[canDo] < 0) return 0; // check cycle
              }
          }
      }
      return !numCourses;
  }
  ```
- ***dfs with visit path [O(n*p) time | O(n*p) space]***:
  - make an adjacency list for each course which shows preReqs for each course
  - for each course start a dfs with an empty dfs path
      - if preReqs for the current course are 0 then course can be done → return true
      - if current course already seen in dfs path → cycle exists → return false
      - post checks, add current course to path now
      - dfs over each of the preReqs of the current course → if any false → return false
      - post these dfs calls, clear preReqs for current course since its preReqs all doable
      - remove it from path
      - return true
  ```cpp
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      unordered_map<int, vector<int>> preReqs;
      for (auto link: prerequisites)
          preReqs[link[0]].push_back(link[1]);
      
      unordered_set<int> tempPath;
      for (int i = 0; i<numCourses; i++)
          if (!dfs(i, preReqs, tempPath)) 
              return false;
      
      return true;
  }
  
  bool dfs(int course, unordered_map<int, vector<int>> &preReqs, unordered_set<int> &path) {
      if (preReqs[course].empty()) return true;
      if (path.find(course) != path.end()) return false;
  
      path.insert(course);
      for (auto c: preReqs[course]) {
          if (!dfs(c, preReqs, path)) 
              return false;
      }
      preReqs[course].clear();
      path.erase(course);
      return true;
  }
  ```

### ***[Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)***: 
- ***Problem Desc***: given courses and pre-reqs, determine what order can all be done in if possible
- ***Topological sort, keep adding to vector the courses [O(n.p) time | O(n) space]***:
  ```cpp
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
      vector<int> ans, inDegree(numCourses);
      vector<vector<int>> preReqAL(numCourses);
      queue<int> doable;
      for (auto pre: prerequisites) {inDegree[pre[0]]++; preReqAL[pre[1]].push_back(pre[0]);}
      for (int i=0; i<numCourses; ++i) if (!inDegree[i]) doable.push(i);

      while (!doable.empty()) {
          int sz = doable.size(); 
          for (int i=0; i<sz; i++) {
              int curr = doable.front(); doable.pop();
              ans.push_back(curr);
              for (auto nextCr: preReqAL[curr]) {
                  inDegree[nextCr]--;
                  if (!inDegree[nextCr]) doable.push(nextCr);
                  if (inDegree[nextCr] < 0) return {};
              }
          }
      }
      if (numCourses != ans.size()) return {};
      return ans;
  }
  ```

### ***[Redundant Connection](https://leetcode.com/problems/redundant-connection/)***:
- ***Problem Desc***: given n connections between nodes 1..n; one connection is redundant, graph stays connected even without that edge, find it
- ***union-find algo [O(n) time | O(n) space]***:
  - make an arr with of size n+1, each elem = 0, i.e. not in set
  - iterate over all edges:
    - if both unset elems, use the smallest index as the root for both
    - if one of them unset, point the unset to the others' root
    - if both set, check if root same, i.e. redundant edge, else point the bigger root to smallest (union op)
  ```cpp
  int findRoot(int i, vector<int> &dsu) {
      if (dsu[i] == i) return i;
      dsu[i] = findRoot(dsu[i], dsu);
      return dsu[i];
  }
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      vector<int> dsu(edges.size()+1), ans;

      for (auto e: edges) {
          if (!dsu[e[0]] && !dsu[e[1]]) { 
              // union and use smaller elem for root
              dsu[e[0]] = dsu[e[1]] = min(e[0], e[1]); 
          } else if (!dsu[e[0]] || !dsu[e[1]]) { 
              // union, max gets rid of unset (0) elem
              dsu[e[0]] = dsu[e[1]] = max(findRoot(e[0], dsu), findRoot(e[1], dsu)); 
          } else {
              int root1 = findRoot(e[0], dsu), root2 = findRoot(e[1], dsu);
              if (root1 == root2) ans = e;
              // union to keep smaller root
              dsu[root1] = dsu[root2] = min(root1, root2); 
          }
      }
      return ans;
  }
  ```

### ***[Number of Connected Components In An Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)***: 
- ***Problem Desc***: acyclic graph with n nodes and n-1 edges is a tree
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Word Ladder](https://leetcode.com/problems/word-ladder/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
