// ***Problem Desc***: given intervals, not sorted and overlapping, for list of given numbers tell what's the shortest len interval they lie in
// ***minQ of inters, compared on len; iter on sorted Qs, push inters that began before Q and pop that ended before Q, top is the ans len [O(n.logn + qlogq) time | O(n+q) space]***:
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
