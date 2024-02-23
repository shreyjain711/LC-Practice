// ***Problem Desc***: given a vector of coordinates, tell the k closes points

// ***Calc euclidean distances, keep in arr as pair of distance and the index of point, sort the array and use the first k points [O(n.logn) time | O(n) space]***:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans; vector<pair<int, int>> minD;
    for (int i=0; i<points.size(); ++i) 
        minD.push_back({(points[i][0]*points[i][0] + points[i][1]*points[i][1]), i});

    sort(minD.begin(), minD.end());
    
    for (int i=0; i<k; ++i)
        ans.push_back(points[minD[i].second]);
    return ans;
}

// ***make min heap of pair of euc dis and index, pop for k times to get the k nearest [O(n.logn) time | O(n) space]***:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    vector<vector<int>> ans;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minD;
    for (int i=0; i<points.size(); ++i) 
        minD.push({(points[i][0]*points[i][0] + points[i][1]*points[i][1]), i});
    
    for (int i=0; i<k; ++i)
        {ans.push_back(points[minD.top().second]); minD.pop();}
    return ans;
}

// ***keep a max heap of size k, it pops the current farthest element in favour of a smaller one so at end will have the k least farther or k nearest pts [O(n.logk) time | O(k) space]***:
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
  vector<vector<int>> ans;priority_queue<vector<int>> maxQ;

  for (auto pt: points) {
      int x = pt[0], y = pt[1];
      maxQ.push({pt[0]*pt[0] + pt[1]*pt[1], pt[0], pt[1]});
      if (maxQ.size() > k) maxQ.pop();
  }
  
  while (maxQ.size()) {ans.push_back({maxQ.top()[1], maxQ.top()[2]}); maxQ.pop();}
  return ans;
}
