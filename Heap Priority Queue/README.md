# Problem Set

### ***[Kth Largest Element In a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)***:
- ***Problem Desc***: given a stream of nums (m nums), after every addition return the kth largest, init with n nums
- ***Sol [O((n+m).logk) time | O(k) space]***:
  ```cpp
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
  ```

### ***[Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)***:
- ***Problem Desc***: given arr of stones with specific weight, play game till left with 1/0 stones -> collide the heaviest stones, if one greater then their diff survives else both don't
- ***Brute [O(n<sup>2</sup>) time | O(n) space]***: find the top two, insert if needed and repeat till 1/0 left
- ***Sol [O(n.logn) time | O(n) space]***:
  ```cpp
  int lastStoneWeight(vector<int>& stones) {
      priority_queue<int> maxQ(stones.begin(), stones.end());
      while (maxQ.size()>1) {
          int y = maxQ.top(); maxQ.pop();
          int x = maxQ.top(); maxQ.pop();
          if (y>x) maxQ.push(y-x);
      }
      return maxQ.size() ? maxQ.top() : 0;
  }
  ```

### ***[K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)***:
- ***Problem Desc***: given a vector of coordinates, tell the k closes points
- ***Calc euclidean distances, keep in arr as pair of distance and the index of point, sort the array and use the first k points [O(n.logn) time | O(n) space]***:
  ```cpp
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      vector<vector<int>> ans; vector<pair<int, int>> minD;
      for (int i=0; i<points.size(); ++i) 
          minD.push_back({(points[i][0]*points[i][0] + points[i][1]*points[i][1]), i});

      sort(minD.begin(), minD.end());
      
      for (int i=0; i<k; ++i)
          ans.push_back(points[minD[i].second]);
      return ans;
  }
  ```
- ***make min heap of pair of euc dis and index, pop for k times to get the k nearest [O(n.logn) time | O(n) space]***:
  ```cpp
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      vector<vector<int>> ans;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minD;
      for (int i=0; i<points.size(); ++i) 
          minD.push({(points[i][0]*points[i][0] + points[i][1]*points[i][1]), i});
      
      for (int i=0; i<k; ++i)
          {ans.push_back(points[minD.top().second]); minD.pop();}
      return ans;
  }
  ```
- ***keep a max heap of size k, it pops the current farthest element in favour of a smaller one so at end will have the k least farther or k nearest pts [O(n.logk) time | O(k) space]***:
  ```cpp
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
  ```

### ***[Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Task Scheduler](https://leetcode.com/problems/task-scheduler/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Design Twitter](https://leetcode.com/problems/design-twitter/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)***:
- ***Problem Desc***: from an incoming stream of data, find the medium at any given time
- ***Sol [O(logn) time insert, O(1) median | O(n) space]***:
  ```cpp
  priority_queue<int> maxFirstHalf;
  priority_queue<int, vector<int>, greater<int>> minSecondHalf;
  MedianFinder() {}
  
  void addNum(int num) {
      if (maxFirstHalf.empty() || maxFirstHalf.top() >= num) maxFirstHalf.push(num);
      else minSecondHalf.push(num);
      
      if (maxFirstHalf.size() > minSecondHalf.size()+1) {
          minSecondHalf.push(maxFirstHalf.top()); maxFirstHalf.pop();
      } else if (maxFirstHalf.size() < minSecondHalf.size()) {
          maxFirstHalf.push(minSecondHalf.top()); minSecondHalf.pop();
      }
  }
  
  double findMedian() {
      if (maxFirstHalf.size() > minSecondHalf.size()) return maxFirstHalf.top();
      return (maxFirstHalf.top() + minSecondHalf.top()) / (double)2;
  }
  ```
