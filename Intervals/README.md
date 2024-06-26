# Problem Set

### [Insert Interval](https://leetcode.com/problems/insert-interval/):
- ***Problem Desc***: given list of sorted non-overlapping intervals and a new interval, insert it and remove overlap to restore order
- ***Add the ones that end before newInt; then keep iterating till currInts intersect with newInt & update it, finally add it; add rest too [O(n) time | O(1) space]***:
  ```cpp
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> ans;
      sort(begin(intervals), end(intervals)); int i=0, n=intervals.size(), a=newInterval[0],b=newInterval[1]; 
      while (i<n && intervals[i][1] < a) ans.push_back(intervals[i++]);

      while (i<n && b >= intervals[i][0]) {a = min(a, intervals[i][0]); b = max(b, intervals[i][1]); i++;}
      ans.push_back({a,b});

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
- ***Problem Desc***: given meeting schedules, find min number of rooms required to accomodate all
- ***go over each meeting, check if earliest ending meet in the minQ ends before curr meet, pop that, push the curr; overlaps won't get pushed out till end [O(n.logn) time | O(n) space]***:
  ```cpp
  int minMeetingRooms(vector<vector<int>>& intervals) {
      sort(begin(intervals), end(intervals));
      priority_queue<int, vector<int>, greater<int>> minQ; 
      int n = intervals.size(), i = 0, ans = 0; 
      while (i < n) {
          if (minQ.size() && minQ.top() < intervals[i][0]) minQ.pop();
          minQ.push_back(intervals[i][1]);
      } return minQ.size();
  }
  ```

### [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/):
- ***Problem Desc***: given intervals, not sorted and overlapping, for list of given numbers tell what's the shortest len interval they lie in
- ***minQ of inters, compared on len; iter on sorted Q-index pairs, push inters begin<Q and pop>Q, top is the ans len [O(n.logn + qlogq) time | O(n+q) space]***:
  ```cpp
  vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
      vector<int> ans(queries.size(), -1); vector<pair<int,int>> sortedQs;
      for (int i=0; i<queries.size(); ++i) sortedQs.push_back({queries[i], i});
      sort(begin(sortedQs), end(sortedQs));
      sort(intervals.begin(), intervals.end());
      auto comp = [](pair<int,int>&a, pair<int,int>&b) {return a.first > b.first;};
      priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> minQ(comp);
      int i = 0;
      for (auto q: sortedQs) {
          while (i < intervals.size() && intervals[i][0] <= q.first) 
              minQ.push({intervals[i][1] - intervals[i][0] + 1, intervals[i++][1]});
          while (minQ.size() && minQ.top().second < q.first) minQ.pop();
          if (minQ.size()) ans[q.second] = minQ.top().first;
      }
      return ans;
  }
  ```
