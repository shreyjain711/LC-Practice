// ***Problem Desc***: given flights from each airports and their prices, find min cost to reach dst from src within k stops

// ***Not Sol - minQ on cost - doesn't work as it find min cost first and skips possibly better paths, skipping cost exceed check makes it BFS time (TLE) [O(A.F<sup>2</sup>) time | O(A) space]***:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<vector<int>>> adjList(n);
    for (auto f:flights) adjList[f[0]].push_back({f[2],f[1]});
    vector<int> minCost(n, INT_MAX); minCost[src] = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minQ; 
    minQ.push({0, 0, src});

    while (!minQ.empty()) {
        int currCost = minQ.top()[0], currStop = minQ.top()[1], currPort = minQ.top()[2];
        minQ.pop(); if (currStop > k) continue; 
        for (auto neighbor: adjList[currPort]) {
            int nextCost = currCost + neighbor[0], nextPort = neighbor[1];
            if (nextCost < minCost[nextPort]) {
            // priority Q won't work: if an intermediary node gets a lower val 
            // from another path then the actual path won't happen
            //     5        5
            // 0------->1------>2
            // |      / |      /
            // |2   /2  |1   /1
            // |  /     |  /
            // 3        4
                minCost[nextPort] = min(minCost[nextPort], nextCost);
                if (nextPort!=dst) minQ.push({nextCost, currStop+1, nextPort});
            }
        } 
    } 
    return minCost[dst]==INT_MAX ? -1 : minCost[dst];
}

// ***Not Sol - bfs - gives TLE [O(A.F<sup>2</sup>) time | O(A) space]***:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<vector<int>>> adjList(n);
    for (auto f:flights) adjList[f[0]].push_back({f[2],f[1]});
    vector<int> minCost(n, INT_MAX); minCost[src] = 0;
    queue<vector<int>> minQ; 
    minQ.push({0, 0, src});

    while (!minQ.empty()) {
        int currCost = minQ.front()[0], currStop = minQ.front()[1], currPort = minQ.front()[2];
        minQ.pop(); if (currStop > k) continue; 
        for (auto neighbor: adjList[currPort]) {
            int nextCost = currCost + neighbor[0], nextPort = neighbor[1];
            minCost[nextPort] = min(minCost[nextPort], nextCost);
            if (nextPort!=dst) minQ.push({nextCost, currStop+1, nextPort});
        } 
    } 
    return minCost[dst]==INT_MAX ? -1 : minCost[dst];
}

// ***Bellman ford - take each flight if the src already visited; doing k such iters evals all possible paths, leaving smallest cost [O(A.F) time | O(A) space]***:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> minCost(n, INT_MAX); minCost[src] = 0;
    for (int i=0; i<=k; i++) {
        vector<int> tempMinCost(begin(minCost), end(minCost)); 
        //need tempMinCost as have to use vals from minCost and can't alter them mid iter
        for(auto f:flights) {
            if (minCost[f[0]]==INT_MAX) continue;
            tempMinCost[f[1]] = min(tempMinCost[f[1]], minCost[f[0]] + f[2]);
        } minCost = tempMinCost;
    }
    return minCost[dst]==INT_MAX ? -1 : minCost[dst];
}

// ***MinQ but priority is the number of stops - works as it evaluates smallest path first and can still use the skip next on its prev cost exceed [O(A.A.logF) time | O() space]***:
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<vector<int>>> adjList(n);
    for (auto f:flights) adjList[f[0]].push_back({f[2],f[1]});
    vector<int> minCost(n, INT_MAX); minCost[src] = 0;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minQ; 
    minQ.push({0, 0, src});

    while (!minQ.empty()) {
        int currStop = minQ.top()[0], currCost = minQ.top()[1], currPort = minQ.top()[2];
        minQ.pop(); if (currStop > k) continue; 
        for (auto neighbor: adjList[currPort]) {
            int nextCost = currCost + neighbor[0], nextPort = neighbor[1];
            if (nextCost < minCost[nextPort]) {
                minCost[nextPort] = min(minCost[nextPort], nextCost);
                if (nextPort!=dst) minQ.push({currStop+1, nextCost, nextPort});
            }
        } 
    } 
    return minCost[dst]==INT_MAX ? -1 : minCost[dst];
}
