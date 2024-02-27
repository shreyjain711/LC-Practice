// ***Problem Desc***: given courses and pre-reqs, determine what order can all be done in if possible

// ***Topological sort, keep adding to vector the courses [O(n.p) time | O(n) space]***:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans, inDegree(numCourses);
    vector<vector<int>> preReqAL(numCourses);
    queue<int> doable;
    for (auto pre: prerequisites) {inDegree[pre[0]]++; preReqAL[pre[1]].push_back(pre[0]);}
    for (int i=0; i<numCourses; ++i) if (!inDegree[i]) doable.push(i);

    while (!doable.empty()) {
        int sz = doable.size(); 
        for (int i=0; i<sz; i++) {
            int curr = doable.front(); doable.pop();
            ans.push_back(curr);
            for (auto nextCr: preReqAL[curr]) {
                inDegree[nextCr]--;
                if (!inDegree[nextCr]) doable.push(nextCr);
                if (inDegree[nextCr] < 0) return {};
            }
        }
    }
    if (numCourses != ans.size()) return {};
    return ans;
}
