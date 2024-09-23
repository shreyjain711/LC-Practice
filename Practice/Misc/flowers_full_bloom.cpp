// ### ***[Number of Flowers in Full Bloom](https://leetcode.com/problems/number-of-flowers-in-full-bloom/)***: 

// - ***Problem Desc***: given intervals for true and set of points, count number of true for each given point
// - ***Brute [O(n.p) time | O(1) space]***: for each point, check which intervals it falls in

// - ***store in map starts and ends(+1, as inclusive) of intervals, +1 at s, -1 and e+1, prefixSum for elem just less than point [O(nlogn+plogn) time | O(1) space]***: 
vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    map<int, int> onOffs; onOffs[-1] = 0; int countTillNow=0;
    for (auto f: flowers) {onOffs[f[0]]++; onOffs[f[1]+1]--;}
    for (auto p: onOffs) {
        countTillNow += p.second;
        onOffs[p.first] = countTillNow;
    }
    vector <int> ans(people.size());
    for(int i=0; i<people.size(); i++) {
        ans[i] = (*(--onOffs.upper_bound(people[i]))).second;
    } return ans;
}

// - ***store in map starts and ends(+1, as inclusive) of intervals, +1 at s, -1 and e+1, go over sorted points, keep doing prefix sum [O(nlogn+plogp) time | O(1) space]***: 
vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
    int countTillNow=0, np = people.size();
    vector <int> ans(np);
    map<int, int> onOffs; vector<pair<int,int>>sortedP(np); onOffs[-1] = 0; 
    for (auto f: flowers) {onOffs[f[0]]++; onOffs[f[1]+1]--;}
    auto ooIt = onOffs.begin();
    for(int i=0; i<np; i++) sortedP[i] = {people[i], i};
    sort(begin(sortedP), end(sortedP));
    for (auto sp: sortedP) {
        while (ooIt!=onOffs.end() && (*ooIt).first<=sp.first) {
            countTillNow += (*ooIt).second; ooIt++;
        } ans[sp.second] = countTillNow;
    }
    return ans;
}
