// ***Problem Desc***: given a stream of nums (m nums), after every addition return the kth largest, init with n nums

// ***Sol [O((n+m).logk) time | O(k) space]***:
priority_queue<int, vector<int>, greater<int>> minq; int k;
KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for (int n: nums) add(n);
}
int add(int val) {
    minq.push(val);
    if (minq.size() > k) minq.pop();
    return minq.top();
}
