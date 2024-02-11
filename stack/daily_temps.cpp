// ***Problem Desc***: given temp for each day, for each day tell how many days before a day with higher temp seen
// ***Stack, 0..n iter [O(n) time | O(n) space]***:
//    - can also keep only the indexes in stack, see the temp from the actual array
vector<int> dailyTemperatures(vector<int>& temps) {
    vector<int> ans(temps.size(), 0);
    stack<pair<int, int>> s;
    for (int i = 0; i < temps.size(); ++i) {
        while (!s.empty() && s.top().first < temps[i]) {
            ans[s.top().second] = i - s.top().second;
            s.pop();
        } s.push({temps[i], i});
    } return ans;
}

// ***Stack, n-1..0 iter [O(n) time | O(n) space]***: pop if curr elem is >= top
