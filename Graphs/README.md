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
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Surrounded Regions](https://leetcode.com/problems/surrounded-regions/)***:
- ***Problem Desc***: capture all islands that are covered by Xs on all 4 sides
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### **[Walls And Gates](https://leetcode.ca/all/286.html)**:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Course Schedule](https://leetcode.com/problems/course-schedule/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)***: 
- ***Problem Desc***: given courses and pre-reqs, determine what order can all be done in if possible → Topological sort covers both problems
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Redundant Connection](https://leetcode.com/problems/redundant-connection/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
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
