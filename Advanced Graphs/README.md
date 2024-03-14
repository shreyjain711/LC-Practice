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
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Network Delay Time](https://leetcode.com/problems/network-delay-time/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Swim In Rising Water](https://leetcode.com/problems/swim-in-rising-water/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
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
