// ***Problem Desc***: given network of weighted directed edges, given node to start from, find if all nodes can be connected or not

// ***BFS from source, keep track of minTime for each node, it's inserted into the bfsQ only if a new mintime for neighbor node set [O(E+V.E) time | O(V+E) space]***:
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<vector<int>>> adjList(n);
    for (auto t:times) adjList[t[0]-1].push_back({t[1]-1, t[2]}); 

    vector<int> minTime(n, INT_MAX); minTime[k-1] = 0;
    queue<vector<int>> bfsQ; bfsQ.push({k-1, 0});

    while (!bfsQ.empty()) {
        int currNode = bfsQ.front()[0], currTime = bfsQ.front()[1]; bfsQ.pop();
        if (currTime > minTime[currNode]) continue;
        for (auto neighbor: adjList[currNode]) {
            int newMinTime = currTime + neighbor[1];
            if (newMinTime < minTime[neighbor[0]]) {
                minTime[neighbor[0]] = newMinTime;
                bfsQ.push({neighbor[0], minTime[neighbor[0]]});
            }
        }
    } int m = *max_element(begin(minTime),end(minTime));
    return  m == INT_MAX ? -1 : m;
}

/*
- ***Djikstra -> minQ for bfs -> actual signal propogation order gets mimiced as minQ sorted by time -> avoid bfs from unoptimal time nodes [O(E+V.logV) time | O(V<sup>2</sup>) space]***:
  - to make use of skipping queue entries in favor of better entries
  - TC would be E+Vlog(V<sup>2</sup>) (in case of a fully connected graph len will be V<sup>2</sup> but total V calls would be made at max) which then converts to E+V.logV
*/
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adjList(n);
    for (auto t:times) adjList[t[0]-1].push_back({t[2], t[1]-1}); 

    vector<int> minTime(n, INT_MAX); minTime[k-1] = 0;
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> bfsPQ;
    bfsPQ.push({0, k-1});

    while (!bfsPQ.empty()) {
        int currTime = bfsPQ.top().first, currNode = bfsPQ.top().second; bfsPQ.pop();
        if (currTime > minTime[currNode]) continue;
        for (auto neighbor: adjList[currNode]) {
            int newMinTime = currTime + neighbor.first;
            if (newMinTime < minTime[neighbor.second]) {
                minTime[neighbor.second] = newMinTime;
                bfsPQ.push({minTime[neighbor.second], neighbor.second});
            }
        }
    } int m = 0; for(int t:minTime) if(m<t) m=t;
    return  m == INT_MAX ? -1 : m;
}
