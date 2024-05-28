# Problem Set

### ***[Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/)***:
- ***Problem Desc***: given tickets with to and fro given, find the lexically smallest path that uses all tickets, starting from JFK
- ***Sort and then make adjList with a queue; we do dfs and pop the airport being visited, and once dfs back then we push to ans [O(A+TlogT) time | O(T) space]***:
  ```cpp
  vector<string> findItinerary(vector<vector<string>>& tickets) {
      sort(begin(tickets), end(tickets));
      unordered_map<string,queue<string>> adjList; vector<string> ls;
      for (auto t: tickets) adjList[t[0]].push(t[1]);
      dfs("JFK", adjList, ls); reverse(begin(ls), end(ls)); return ls;
  }
  void dfs (string curr, unordered_map<string,queue<string>> &adjList, vector<string> &ls) {
      while(adjList[curr].size()) {
          string next = adjList[curr].front(); adjList[curr].pop();
          dfs (next, adjList, ls);
      } ls.push_back(curr);
  }
  ```

### ***[Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/)***:
- ***Problem Desc***: given points on grid, connect all of them with minimum edge weights (an edge weight is manhattan dis between the two points)
- ***Prim's algo, start from 0th, for each node put all edges (unvisited) in a minQ, pop top till top visited, then top gets added, visit it and continue from there [O(n<sup>2</sup>.logn) time | O(<sup>2</sup>) space]***:
  ```cpp
  int minCostConnectPoints(vector<vector<int>>& points) {
      int i=0, cost = 0, n = points.size(); bitset<1000> visited; visited[0] = 1;
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minQ;
      while (visited.count()<n){
          for (int j=0; j<n; ++j) 
              if (!visited[j])
                  minQ.push({abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), j});
          while (visited[minQ.top().second]) minQ.pop();
          cost += minQ.top().first; 
          i = minQ.top().second; visited[i] = 1; 
          minQ.pop();
      }
      return cost;
  }
  ```
- ***Unoptimised prim - calculating all instead of minHeap - better since n<sup>2</sup> edges exist [O(n<sup>2</sup>) time | O(n) space]***:
  ```cpp
  int minCostConnectPoints(vector<vector<int>>& points) {
      int cost = 0, n = points.size(); bitset<1000> visited; 
      vector<int> minCost(n, INT_MAX); minCost[0] = 0;
      while (visited.count() < n){
          int next, nextDis = INT_MAX;
          for (int i=0; i<n; ++i) 
              if (!visited[i] && minCost[i] < nextDis) 
                  {next=i; nextDis=minCost[i];}
          visited[next] = 1; cost+=nextDis;
          for (int i=0; i<n; ++i)
              if (!visited[i])
                  minCost[i] = min(minCost[i], 
                          abs(points[next][0]-points[i][0]) + abs(points[next][1]-points[i][1]));
      }
      return cost;
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
- ***Djikstra -> minQ for bfs -> actual signal propogation order gets mimiced as minQ sorted by time -> avoid bfs from unoptimal time nodes [O(E+V.logV) time | O(V<sup>2</sup>) space]***:
  - to make use of skipping queue entries in favor of better entries
  - TC would be E+Vlog(V<sup>2</sup>) (in case of a fully connected graph len will be V<sup>2</sup> but total V calls would be made at max) which then converts to E+V.logV
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
- ***Problem Desc***: alien lang uses same letters but diff order; given a dict of alien words telling the order of words, determine the order of letters
- ***compare each word with its next to get an edge between letters; do topological sort from these edges (keep edges & inDegree) [O(numWor.numWorLen + numLet<sup>2</sup>) time | O(numLet) space]***:
  ```cpp
  string alienOrder(vector<string> &words) {
      unordered_map<char, bitset<26>> edges;
      unordered_map<char, int> inDegree;
      for (int i=0; i+1<words.size(); ++i) {
          string w1 = words[i];
          string w2 = words[i+1];
          int a=0,b=0;
          while (a<w1.size() && b<w2.size() && w1[a]==w2[b]) {a++; b++;}
          if (a<w1.size() && b<w2.size() && !edges[w1[a]][w2[b]-'a']) {
              edges[w1[a]][w2[b]-'a'] = 1;
              if (!inDegree.count(w1[a])) inDegree[w1[a]]=0; inDegree[w2[b]]++;
         }
      }
      queue<char> tpSort; string order = "";
      for (auto count: inDegree) if (!count.second) {tpSort.push(count.first);}
      while (!tpSort.empty()) {
          char curr = tpSort.front(); tpSort.pop(); order += curr; 
          for (int i=0; i<26; i++) {
              char next = 'a' + i;
              if (!edges[curr][i]) continue;
              if (--inDegree[next] == 0) tpSort.push(next);
          }
      } return order.size()==inDegree.size() ? order : "";
  }
  ```

### ***[Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)***:
- ***Problem Desc***: given flights from each airports and their prices, find min cost to reach dst from src within k stops
- ***Not Sol - minQ on cost - doesn't work as it find min cost first and skips possibly better paths, skipping cost exceed check makes it BFS time (TLE) [O(A.F<sup>2</sup>) time | O(A) space]***:
  ```cpp
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<vector<int>>> adjList(n);
      for (auto f:flights) adjList[f[0]].push_back({f[2],f[1]});
      vector<int> minCost(n, INT_MAX); minCost[src] = 0;
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minQ; 
      minQ.push({0, 0, src});

      while (!minQ.empty()) {
          int currCost = minQ.top()[0], currStop = minQ.top()[1], currPort = minQ.top()[2];
          minQ.pop(); if (currStop > k) continue; 
          for (auto neighbor: adjList[currPort]) {
              int nextCost = currCost + neighbor[0], nextPort = neighbor[1];
              if (nextCost < minCost[nextPort]) {
              // priority Q won't work: if an intermediary node gets a lower val 
              // from another path then the actual path won't happen
              //     5        5
              // 0------->1------>2
              // |      / |      /
              // |2   /2  |1   /1
              // |  /     |  /
              // 3        4
                  minCost[nextPort] = min(minCost[nextPort], nextCost);
                  if (nextPort!=dst) minQ.push({nextCost, currStop+1, nextPort});
              }
          } 
      } 
      return minCost[dst]==INT_MAX ? -1 : minCost[dst];
  }
  ```
- ***Not Sol - bfs - gives TLE [O(A.F<sup>2</sup>) time | O(A) space]***:
  ```cpp
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<vector<int>>> adjList(n);
      for (auto f:flights) adjList[f[0]].push_back({f[2],f[1]});
      vector<int> minCost(n, INT_MAX); minCost[src] = 0;
      queue<vector<int>> minQ; 
      minQ.push({0, 0, src});

      while (!minQ.empty()) {
          int currCost = minQ.front()[0], currStop = minQ.front()[1], currPort = minQ.front()[2];
          minQ.pop(); if (currStop > k) continue; 
          for (auto neighbor: adjList[currPort]) {
              int nextCost = currCost + neighbor[0], nextPort = neighbor[1];
              minCost[nextPort] = min(minCost[nextPort], nextCost);
              if (nextPort!=dst) minQ.push({nextCost, currStop+1, nextPort});
          } 
      } 
      return minCost[dst]==INT_MAX ? -1 : minCost[dst];
  }
  ```
- ***Bellman ford - take each flight if the src already visited; doing k such iters evals all possible paths, leaving smallest cost [O(A.F) time | O(A) space]***:
  ```cpp
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<int> minCost(n, INT_MAX); minCost[src] = 0;
      for (int i=0; i<=k; i++) {
          vector<int> tempMinCost(begin(minCost), end(minCost)); 
          //need tempMinCost as have to use vals from minCost and can't alter them mid iter
          for(auto f:flights) {
              if (minCost[f[0]]==INT_MAX) continue;
              tempMinCost[f[1]] = min(tempMinCost[f[1]], minCost[f[0]] + f[2]);
          } minCost = tempMinCost;
      }
      return minCost[dst]==INT_MAX ? -1 : minCost[dst];
  }
  ```
- ***MinQ but priority is the number of stops - works as it evaluates smallest path first and can still use the skip next on its prev cost exceed [O(A<sup>2</sup>.logA) time | O(A<sup>2</sup>) space]***:
  ```cpp
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<vector<vector<int>>> adjList(n);
      for (auto f:flights) adjList[f[0]].push_back({f[2],f[1]});
      vector<int> minCost(n, INT_MAX); minCost[src] = 0;
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minQ; 
      minQ.push({0, 0, src});

      while (!minQ.empty()) {
          int currStop = minQ.top()[0], currCost = minQ.top()[1], currPort = minQ.top()[2];
          minQ.pop(); if (currStop > k) continue; 
          for (auto neighbor: adjList[currPort]) {
              int nextCost = currCost + neighbor[0], nextPort = neighbor[1];
              if (nextCost < minCost[nextPort]) {
                  minCost[nextPort] = min(minCost[nextPort], nextCost);
                  if (nextPort!=dst) minQ.push({currStop+1, nextCost, nextPort});
              }
          } 
      } 
      return minCost[dst]==INT_MAX ? -1 : minCost[dst];
  }
  ```
- ***simple bfs, traverse further from an edge if its minCost > currCost [O(K.A<sup>2</sup>) time | O(A<sup>2</sup>) space]***: this works and dfs didn't -> dfs missed when a smaller k value but higher minCost seen
  ```cpp
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      vector<int> minCost(n, INT_MAX); minCost[src] = 0;
      vector<vector<pair<int,int>>> adjList(n); 
      for (auto &f: flights) adjList[f[0]].push_back({f[1], f[2]});
      
      queue<pair<int,int>> q; q.push({src, 0}); int lvl = 0;
      while (lvl <= k && !q.empty()) {
          for (int i=q.size(); i>0; --i) {
              auto [curr, currCost] = q.front(); q.pop();
              for (auto &[n, cost]: adjList[curr]) {
                  if (minCost[n] > currCost + cost) {
                      minCost[n] = currCost + cost;
                      q.push({n, currCost + cost});
                  }
              }
          } lvl++;
      } return minCost[dst] == INT_MAX ? -1 : minCost[dst];
  }
  ```
