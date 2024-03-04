// ***Problem Desc***: given a list with unsorted intervals that could be overlapping, find min count of intervals to be removed to get it non overlapping

// **Greedy, sort then if an interval ends after the next begins then count++ and if it ends before the next ends then we remove the next (replace with curr) [O(n.logn) time | O(1) space]***:
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
