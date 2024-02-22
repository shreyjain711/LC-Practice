# Problem Set

### ***[Kth Largest Element In a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[K Closest Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
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
