// ***Problem Desc***: given points on grid, connect all of them with minimum edge weights (an edge weight is manhattan dis between the two points)

// ***Prim's algo, start from 0th, for each node put all edges (unvisited) in a minQ, pop top till top visited, then top gets added, visit it and continue from there [O(n<sup>2</sup>.logn) time | O(<sup>2</sup>) space]***:
int minCostConnectPoints(vector<vector<int>>& points) {
    int i=0, cost = 0, n = points.size(); bitset<1000> visited; visited[0] = 1;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minQ;
    while (visited.count()<n){
        for (int j=0; j<n; ++j) 
            if (!visited[j])
                minQ.push({abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), j});
        while (visited[minQ.top().second]) minQ.pop();
        cost += minQ.top().first; 
        i = minQ.top().second; visited[i] = 1; 
        minQ.pop();
    }
    return cost;
}

// ***Unoptimised prim - calculating all instead of minHeap - better since n<sup>2</sup> edges exist [O(n<sup>2</sup>) time | O(n) space]***:
int minCostConnectPoints(vector<vector<int>>& points) {
    int cost = 0, n = points.size(); bitset<1000> visited; 
    vector<int> minCost(n, INT_MAX); minCost[0] = 0;
    while (visited.count() < n){
        int next, nextDis = INT_MAX;
        for (int i=0; i<n; ++i) 
            if (!visited[i] && minCost[i] < nextDis) 
                {next=i; nextDis=minCost[i];}
        visited[next] = 1; cost+=nextDis;
        for (int i=0; i<n; ++i)
            if (!visited[i])
                minCost[i] = min(minCost[i], 
                        abs(points[next][0]-points[i][0]) + abs(points[next][1]-points[i][1]));
    }
    return cost;
}
