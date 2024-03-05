// ***Problem Desc***: given intervals, not sorted and overlapping, for list of given numbers tell what's the shortest len interval they lie in
// ***minQ of inters, compared on len; iter on sorted Qs, push inters that began before Q and pop that ended before Q, top is the ans len [O(n.logn + qlogq) time | O(n+q) space]***:
vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    auto comparator = [](vector<int> &a, vector<int> &b) {
        return (a[1]-a[0]) > (b[1]-b[0]);
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comparator)> minq(comparator);

    vector<int> ans, sortedQs(queries.begin(), queries.end()); 
    sort(sortedQs.begin(), sortedQs.end());
    unordered_map<int, int> m; for(int q:queries) m[q] = -1;
    queue<vector<int>> st; sort(intervals.begin(), intervals.end());

    int i = 0, n=intervals.size();
    for (auto q: sortedQs) {
        while (i<n && intervals[i][0] <= q) minq.push(intervals[i++]);
        while (!minq.empty() && minq.top()[1] < q) minq.pop();
        if(!minq.empty()) m[q] = minq.top()[1]-minq.top()[0]+1;
    } for (auto q:queries) ans.push_back(m[q]);
    return ans;
}
