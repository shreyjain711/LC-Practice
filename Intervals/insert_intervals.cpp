// ***Problem Desc***: given list of sorted non-overlapping intervals and a new interval, insert it and remove overlap to restore order

// ***Add the ones that end before newInt; then keep iterating till currInts intersect with newInt & update it, finally add it; add rest too [O(n) time | O(1) space]***:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    sort(begin(intervals), end(intervals)); int i=0, n=intervals.size(), a=newInterval[0],b=newInterval[1]; 
    while (i<n && intervals[i][1] < a) ans.push_back(intervals[i++]);
    
    while (i<n && b >= intervals[i][0]) {a = min(a, intervals[i][0]); b = max(b, intervals[i][1]); i++;}
    ans.push_back({a,b});
    
    while (i<n) ans.push_back(intervals[i++]);
    return ans;
}
