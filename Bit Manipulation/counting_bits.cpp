// ***Problem Desc***: given n, return arr with no. of bits in ints from range 0 to n

// ***Forward solve, add 0 then add a val[0]+1 then repeat on this set of 2 vals, then on 4, keep on till hitting n size [O(n) time | O(1) space***:
vector<int> countBits(int n) {
    vector<int> ans(1);
    while (ans.size()<=n) {
        int t=ans.size(); 
        for (int i=0; i<t && ans.size()<=n; ++i) {
            ans.push_back(ans[i]+1);
        }
    } return ans;
}

// ***Lookback, val[n] = val[n/2] + n%2 [O(n) time | O(1) space***:
vector<int> countBits(int n) {
    vector<int> ans(n+1);
    for (int i=1; i<=n; ++i) {
        ans[i] = ans[i/2] + i%2;
    } return ans;
}
