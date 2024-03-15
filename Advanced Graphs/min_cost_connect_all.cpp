***Problem Desc***: given points on grid, connect all of them with minimum edge weights (an edge weight is manhattan dis between the two points)
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
