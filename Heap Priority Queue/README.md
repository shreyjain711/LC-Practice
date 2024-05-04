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
- ***Problem Desc***: return the kth largest elem of the array
- ***Sort, pick len-k elem [O(n.logn) time | O()n space]***:
  ```cpp
  int findKthLargest(vector<int>& nums, int k) {
      sort(nums.begin(), nums.end());
      return nums[nums.size()-k];
  }
  ```
- ***min heap of size k, after pushing in all elems while maintaining size, top is kth largest [O(n.logk) time | O(k) space]***:
  ```cpp
  int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, greater<int>> minHeap;
      for (int n: nums) {
          minHeap.push(n); 
          if (minHeap.size()>k) minHeap.pop();
      }
      return minHeap.top();
  }
  ```
- ***make max heap from arr, pop k-1 times, top is the kth largest [O(n+k.logn) time | O(n) space]***:
  ```cpp
  int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxQ(nums.begin(), nums.end());
        while(k>1) {maxQ.pop(); k--;}
        return maxQ.top();
    }
  ```
- ***Quick Select [O(nlogn) avg time, O(n<sup>2</sup>) worst time | O(1) space]***:
  - (Rejected on LC due to TLE on its worst case)
  - accepted is if we do descending quick select if k is small else ascending.. to reach sooner
  ```cpp
  int findKthLargest(vector<int>& nums, int k) {
      return quickSelectLookBothWays(nums, k);
  }
  int quickSelectLookBothWays(vector<int>& nums, int k) {
      if (k<nums.size()/2) {
          nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
          return nums[k-1];
      } else {
          nth_element(nums.begin(), nums.begin()+nums.size()-k, nums.end());
          return nums[nums.size()-k];
      }
  }
  int quickSelectPlain(int start, int end, vector<int>& nums, int target) {
      int pivotPointer=start;
      for (int i=start; i<end; i++) {
          if (nums[i] < nums[end]) {swap(nums[i], nums[pivotPointer]); pivotPointer++;}
      } swap(nums[pivotPointer], nums[end]);
      if (pivotPointer == target) return nums[pivotPointer];
      else if (pivotPointer < target) return quickSelectPlain(pivotPointer+1, end, nums, target);
      else return quickSelectPlain(start, pivotPointer-1, nums, target);
  }
  ```

### ***[Task Scheduler](https://leetcode.com/problems/task-scheduler/)***:
- ***Problem Desc***: given tasks (identified by uppercase chars), they have to be exec. Can be exec but between each same task, gap of n needed. How much time need to run total
- ***max heap and priority queue [O(n*tasks) time | O(1) space]***:
  - we need to prioritise the task with max count since that will define the empty intervals
    - make maxQ with only counts of each task (task id doesn't matter)
    - it'll tell which task to run at any time
  - then we need a Q to know when a task is again eligible
    - relying only on pq would lead to diff tasks running fist and then the max occus task adds up the idle time
    - when task run, if it needs to be run again then store its count and the curr ts in Q
    - at each ts check if q has an item in front that can be run again, take it out of Q and re-enter into maxQ
  - now run till task left in maxQ (to be run) or Q (waiting) states
  ```cpp
  int leastInterval(vector<char>& tasks, int n) {
      vector<int> counts(26);
      priority_queue<int> mxq; queue<vector<int>> q;
      for (char t: tasks) counts[t-'A']++;
      for (auto c: counts) if (c) mxq.push(c);

      int ts = 0;
      while (!q.empty() || !mxq.empty()) {
          ts++;
          if (!mxq.empty()) {
              if (mxq.top() > 1) 
                  q.push({mxq.top()-1, ts+n});
              mxq.pop();
          }
          if (!q.empty() && q.front()[1] == ts) {
              mxq.push(q.front()[0]);
              q.pop();
          }
      }
      return ts;
  }
  ```
- ***greedy, maths [O(n) time | O(1) space]:
  - maxOccur task will define the n+1 spaced intervals needed (provided n is big enough)
  - so (maxOccur-1)*(n+1) spaces will definitely exist
  - now count for each elem that occurs == maxOccur, the last extra window will get added
    - won't be of length n+1 so we increment ans by 1 for each such elem
  - if n not big enough then tasks size is going to matter
  ```cpp
  int leastInterval(vector<char>& tasks, int n) {
      vector<int> counts(26); int ans = 0, maxOccur = 0;
      for (char t: tasks) maxOccur = max(maxOccur, ++counts[t-'A']);
      
      ans = (maxOccur - 1) * (n + 1);
      for (int c: counts) if (c == maxOccur) ans++;
      
      return max(ans, (int)tasks.size());
  }
  ```

### ***[Design Twitter](https://leetcode.com/problems/design-twitter/)***:
- ***Problem Desc***: design functions for follow, unfollow and generate news feed
- ***Sol [O(logn) time for follow, unfollow, O(n.p.logFeedSize) time for news feed generation | O(feedSize) space]***:
  ```cpp
  int tweetNum;
  unordered_map<int, unordered_set<int>> followList;
  unordered_map<int, vector<vector<int>>> postList;
  Twitter() {
      tweetNum = 0;
  }
  
  void postTweet(int userId, int tweetId) {
      if (followList.find(userId) == followList.end())
          followList[userId].insert(userId);
      postList[userId].push_back({tweetNum++, tweetId});
  }
  
  vector<int> getNewsFeed(int userId) {
      vector<int> newsFeed;
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
      for (auto followed: followList[userId]) {
          for (auto postDetails : postList[followed]) {
              pq.push(postDetails);
              if (pq.size() > 10) pq.pop();
          }
      }
      while (!pq.empty()) {newsFeed.push_back(pq.top()[1]); pq.pop();}
      reverse(newsFeed.begin(), newsFeed.end());
      return newsFeed;
  }
  
  void follow(int followerId, int followeeId) {
      if (followList.find(followerId) == followList.end())
          followList[followerId].insert(followerId);
      followList[followerId].insert(followeeId);
  }
  
  void unfollow(int followerId, int followeeId) {
      followList[followerId].erase(followeeId);
  }
  ```

### ***[Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)***:
- ***Problem Desc***: from an incoming stream of data, find the medium at any given time
- ***Min and Max Qs, max keeps lower half, min keeps greater; insert as per empty/max.top & balance; median as per sizes [O(logn) time insert, O(1) median | O(n) space]***:
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
