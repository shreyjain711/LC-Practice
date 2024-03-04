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
- ***Problem Desc***: given unsorted list of intervals, return sorted, non-overlapping list of intervals
- ***sort, iterate and insert or resolve overlap between last inserted and current inter [O(n.logn) time | O(1) space]***:
  ```cpp
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      vector<vector<int>> newInters; newInters.push_back(intervals[0]);
      int i=1, n=intervals.size();
      while (i<n) {
          if (newInters.back()[1] >= intervals[i][0]) {
              newInters.back()[0] = min(newInters.back()[0], intervals[i][0]);
              newInters.back()[1] = max(newInters.back()[1], intervals[i][1]);
          } else {
              newInters.push_back(intervals[i]);
          } i++;
      }
      return newInters;
  }
  ```

### [Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/):
- ***Problem Desc***: given a list with unsorted intervals that could be overlapping, find min count of intervals to be removed to get it non overlapping
- ***Greedy, sort then if an interval ends after the next begins then count++ and if it ends before the next ends then we remove the next (replace with curr) [O(n.logn) time | O(1) space]***:
  ```cpp
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end()); int ans=0;
      for (int i=0; i<intervals.size()-1; ++i) {
          if (intervals[i][1] > intervals[i+1][0]) {
              if (intervals[i][1] < intervals[i+1][1]) 
                  intervals[i+1] = intervals[i];
              ans++;
          }
      } return ans;
  }
  ```

### [Meeting Rooms](https://leetcode.com/problems/meeting-rooms/):
- ***Problem Desc***: given meeting schedules, check if person can attend all
- ***Sort, check for overlaps [O(n.logn) time | O(1) space]***:
  ```cpp
  bool canAttendMeetings(vector<vector<int>>& intervals) {
      sort(intervals.begin(), intervals.end());
      for(int i=0; i<intervals.size()-1; ++i)
          if (intervals[i][1] > intervals[i+1][0]) 
              return 0;
      return 1;
  }
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
