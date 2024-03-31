// ***Problem Desc***: return the kth largest elem of the array

// ***Sort, pick len-k elem [O(n.logn) time | O()n space]***:
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()-k];
}

// ***min heap of size k, after pushing in all elems while maintaining size, top is kth largest [O(n.logk) time | O(k) space]***:
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int n: nums) {
        minHeap.push(n); 
        if (minHeap.size()>k) minHeap.pop();
    }
    return minHeap.top();
}

// ***make max heap from arr, pop k-1 times, top is the kth largest [O(n+k.logn) time | O(n) space]***:
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> maxQ(nums.begin(), nums.end());
    while(k>1) {maxQ.pop(); k--;}
    return maxQ.top();
}

/*
  ***Quick Select [O(nlogn) avg time, O(n<sup>2</sup>) worst time | O(1) space]***:
  - (Rejected on LC due to TLE on its worst case)
  - accepted is if we do descending quick select if k is small else ascending.. to reach sooner
*/
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
