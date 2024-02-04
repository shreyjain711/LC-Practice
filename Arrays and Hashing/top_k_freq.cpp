vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    vector<pair<int, int>> v;

    for (auto n: nums) count[n]++;

    for (auto i: count) v.push_back({i.second, i.first});
    priority_queue<pair<int, int>> q;

    // for (auto i: count) v.push_back({i.first, i.second});
    // auto comparator = [](pair<int, int> &a, pair<int, int> &b) {return a.second < b.second;};
    // priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> q(comparator);
    // priority_queue<pair<int, int>> q;

    // can also use (ordered) set, pair pushed will be {-i.second, i.first)

    for (auto p: v) q.push(p);

    vector<int> ans;
    for (int i = 0; i<k; ++i) {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}
