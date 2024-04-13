// ***Problem Desc***: given meeting schedules, find min number of rooms required to accomodate all

// ***go over each meeting, check if earliest ending meet in the minQ ends before curr meet, pop that, push the curr; overlaps won't get pushed out till end [O(n.logn) time | O(n) space]***:
int minMeetingRooms(vector<vector<int>>& intervals) {
  sort(begin(intervals), end(intervals));
  priority_queue<int, vector<int>, greater<int>> minQ; 
  int n = intervals.size(), i = 0, ans = 0; 
  while (i < n) {
      if (minQ.size() && minQ.top() < intervals[i][0]) minQ.pop();
      minQ.push_back(intervals[i][1]);
  } return minQ.size();
}
