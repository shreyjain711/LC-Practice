# Problem Set

### ***[Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)***:
- ***Problem Desc***: given tickets with to and fro given, find the lexically smallest path that uses all tickets, starting from JFK
- ***make adj list and use a multiset instead of vector to store sorted neighbors, start dfs from JFK and go over all its neighbors, erase them from adj then further dfs [O(E.log(V)) time | O(V+E) space]***:
  - the insertion in ans arr of the curr airport should be after the dfs from that node is done
  - at the end of dfs, ans should be reversed
  ```cpp
  vector<string> findItinerary(vector<vector<string>>& tickets) {
      unordered_map<string, multiset<string>> adjMap;
      for (auto t:tickets) adjMap[t[0]].insert(t[1]);
      vector<string> ans;
      dfs ("JFK", ans, adjMap); reverse(ans.begin(),ans.end());
      return ans;
  }
  void dfs (string curr, vector<string> &ans, unordered_map<string, multiset<string>> &adjMap) {
      // if (!adjMap.count(curr)) return; - shouldn't, to push in last stop of path
      while (!adjMap[curr].empty()) {
          string next = *adjMap[curr].begin();
          adjMap[curr].erase(adjMap[curr].begin()); // .erase(next) will remove all instances of next
          dfs(next, ans, adjMap);
      } ans.push_back(curr);
  }
  ```

### ***[Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)***:
- ***Problem Desc***: given points on grid, connect all of them with minimum edge weights (an edge weight is manhattan dis between the two points)
- ***start with 0, store minDis for each pt, init with max, incl the closest pt in MST, change minDis as per newly added pt [O(n<sup>2</sup>) time | O(n) space]***:
  ```cpp
  int minCostConnectPoints(vector<vector<int>>& points) {
      int n=points.size(), nextMinEdge, next;
      bitset<1000> visited; vector<int> minDis(n, INT_MAX); minDis[0]=0;
      while (visited.count()<n) {
          nextMinEdge = INT_MAX;
          for (int i=0; i<n; ++i) {
              if (visited[i]) continue;
              if (minDis[i] < nextMinEdge) {nextMinEdge = minDis[i]; next = i;}
          } visited[next] = 1;
          for (int i=0; i<n; ++i) {
              if (visited[i]) continue;
              minDis[i] = min(minDis[i], 
                              abs(points[i][0]-points[next][0])+abs(points[i][1]-points[next][1]));
          }
      }
      return accumulate(begin(minDis), end(minDis), 0);
  }
  ```

### ***[Network Delay Time](https://leetcode.com/problems/network-delay-time/)***:
- ***Problem Desc***: given network of weighted directed edges, given node to start from, find if all nodes can be connected or not
- ***BFS from source, keep track of minTime for each node, it's inserted into the bfsQ only if a new mintime for neighbor node set [O(E+V.E) time | O(V+E) space]***:
  ```cpp
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<vector<int>>> adjList(n);
      for (auto t:times) adjList[t[0]-1].push_back({t[1]-1, t[2]}); 

      vector<int> minTime(n, INT_MAX); minTime[k-1] = 0;
      queue<vector<int>> bfsQ; bfsQ.push({k-1, 0});

      while (!bfsQ.empty()) {
          int currNode = bfsQ.front()[0], currTime = bfsQ.front()[1]; bfsQ.pop();
          if (currTime > minTime[currNode]) continue;
          for (auto neighbor: adjList[currNode]) {
              int newMinTime = currTime + neighbor[1];
              if (newMinTime < minTime[neighbor[0]]) {
                  minTime[neighbor[0]] = newMinTime;
                  bfsQ.push({neighbor[0], minTime[neighbor[0]]});
              }
          }
      } int m = *max_element(begin(minTime),end(minTime));
      return  m == INT_MAX ? -1 : m;
  }
  ```
- ***Djikstra -> minQ for bfs -> actual signal propogation order gets mimiced as minQ sorted by time -> avoid bfs from unoptimal time nodes [O(E+ElogV) time | O(V+E) space]***:
  - to make use of skipping queue entries in favor of better entries
  - TC was log(V<sup>2</sup>) which converts to 2.log(V) so logV
  ```cpp
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int, int>>> adjList(n);
      for (auto t:times) adjList[t[0]-1].push_back({t[2], t[1]-1}); 

      vector<int> minTime(n, INT_MAX); minTime[k-1] = 0;
      priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> bfsPQ;
      bfsPQ.push({0, k-1});

      while (!bfsPQ.empty()) {
          int currTime = bfsPQ.top().first, currNode = bfsPQ.top().second; bfsPQ.pop();
          if (currTime > minTime[currNode]) continue;
          for (auto neighbor: adjList[currNode]) {
              int newMinTime = currTime + neighbor.first;
              if (newMinTime < minTime[neighbor.second]) {
                  minTime[neighbor.second] = newMinTime;
                  bfsPQ.push({minTime[neighbor.second], neighbor.second});
              }
          }
      } int m = 0; for(int t:minTime) if(m<t) m=t;
      return  m == INT_MAX ? -1 : m;
  }
  ```

### ***[Swim In Rising Water](https://leetcode.com/problems/swim-in-rising-water/)***:
- ***Problem Desc***: given grid, water rises by 1 per time unit; how much time till we can swim from 0,0 to n-1,n-1
- ***minQ+bfs gets us to evaluate the soonest in reach grid cells first and before starting the visit, the curr time gets updated [O(n<sup>2</sup>.logn) time | O(n<sup>2</sup>) space]***:
  ```cpp
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
  ```

### ***[Alien Dictionary](https://leetcode.com/problems/alien-dictionary/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
