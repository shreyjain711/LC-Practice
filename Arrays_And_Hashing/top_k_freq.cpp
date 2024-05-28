// ***Problem Desc***: from an arr of elems, make list of top k freq

// ***brute [O(n.c<sup>2</sup>) time | O(c) space]***: count of each, iterate to find the most occuring

// ***max heap of counts [O(n.c.logc) time | O(c) space]***: take max heap based on counts
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    vector<pair<int, int>> v;

    for (auto n: nums) count[n]++;

    for (auto i: count) v.push_back({i.second, i.first});
    priority_queue<pair<int, int>> q;
    for (auto p: v) q.push(p);

    vector<int> ans;
    for (int i = 0; i<k; ++i) {
        ans.push_back(q.top().second);
        q.pop();
    }
    return ans;
}
