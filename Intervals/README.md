# Problem Set

### [Insert Interval](https://leetcode.com/problems/insert-interval/):
- ***Problem Desc***: given list of sorted non-overlapping intervals and a new interval, insert it and remove overlap to restore order
- ***Push inters till end<new's begin; then combine the inters into new till new's end<=begin; then push in remaining inters [O(n) time| O(1) space]***:
  ```cpp
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> ans; int i=0, n=intervals.size();
      while (i<n && intervals[i][1] < newInterval[0]) ans.push_back(intervals[i++]);
      
      while (i<n && newInterval[1] >= intervals[i][0]) {
          newInterval[0] = min(newInterval[0], intervals[i][0]);
          newInterval[1] = max(newInterval[1], intervals[i][1]);
          i++;
      }
      ans.push_back(newInterval);
      
      while (i<n) ans.push_back(intervals[i++]);
      
      return ans;
  }
  ```

### [Merge Intervals](https://leetcode.com/problems/merge-intervals/):
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### [Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/):
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/):
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### [Meeting Rooms II](https://github.com/neetcode-gh/leetcode/blob/main/cpp/0253-meeting-rooms-ii.cpp):
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/):
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
