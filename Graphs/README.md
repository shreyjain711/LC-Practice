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
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Max Area of Island](https://leetcode.com/problems/max-area-of-island/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
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
