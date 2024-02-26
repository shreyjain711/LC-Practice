// ***Problem Desc***: given num of courses and list of prerequisties between the courses, determine if doing all possible

// ***Topological sort, when removing a course from Q reduce numCourses to track num left, also check for cycle, return 1 if no courses left [O(n.p) time | O(n.p) space]***:
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> preReqAL(numCourses); vector<int> inDegree(numCourses);
    for (auto preReq: prerequisites) {
        preReqAL[preReq[0]].push_back(preReq[1]); inDegree[preReq[1]]++;
    }
    queue<int> doable;
    for (int i=0; i<numCourses; ++i) if (!inDegree[i]) doable.push(i);
    while (!doable.empty()) {
        int sz = doable.size();
        for (int i=0; i<sz; ++i) {
            int crs = doable.front(); doable.pop(); numCourses--;
            for (int canDo: preReqAL[crs]) {
                inDegree[canDo]--;
                if (!inDegree[canDo]) doable.push(canDo);
                else if (inDegree[canDo] < 0) return 0; // check cycle
            }
        }
    }
    return !numCourses;
}

/*
***dfs with visit path [O(n*p) time | O(n*p) space]***:
  - make an adjacency list for each course which shows preReqs for each course
  - for each course start a dfs with an empty dfs path
      - if preReqs for the current course are 0 then course can be done → return true
      - if current course already seen in dfs path → cycle exists → return false
      - post checks, add current course to path now
      - dfs over each of the preReqs of the current course → if any false → return false
      - post these dfs calls, clear preReqs for current course since its preReqs all doable
      - remove it from path
      - return true
*/
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> preReqs;
    for (auto link: prerequisites)
        preReqs[link[0]].push_back(link[1]);
    
    unordered_set<int> tempPath;
    for (int i = 0; i<numCourses; i++)
        if (!dfs(i, preReqs, tempPath)) 
            return false;
    
    return true;
}

bool dfs(int course, unordered_map<int, vector<int>> &preReqs, unordered_set<int> &path) {
    if (preReqs[course].empty()) return true;
    if (path.find(course) != path.end()) return false;

    path.insert(course);
    for (auto c: preReqs[course]) {
        if (!dfs(c, preReqs, path)) 
            return false;
    }
    preReqs[course].clear();
    path.erase(course);
    return true;
}
