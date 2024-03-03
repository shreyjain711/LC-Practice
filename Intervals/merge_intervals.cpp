// ***Problem Desc***: given unsorted list of intervals, return sorted, non-overlapping list of intervals

// ***sort, iterate and insert or resolve overlap between last inserted and current inter [O(n) time | O(1) space]***:
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
