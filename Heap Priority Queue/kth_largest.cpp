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

// ***Quick Select [O(n) avg time, O(n<sup>2</sup>) worst time | O(1) space]***: (Rejected on LC due to TLE on its worst case)
int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, nums.size()-k, 0, nums.size()-1);
}
int quickSelect(vector<int>&nums, int ind, int l, int r) {
    int pivot = nums[r], leftHalfEnd = l;
    for(int i = l; i<r; i++) 
        if (nums[i] <= pivot) 
            swap(nums[i], nums[leftHalfEnd++]);
     swap(nums[leftHalfEnd], nums[r]);

    if (leftHalfEnd < ind) 
        return quickSelect(nums, ind, leftHalfEnd+1, r);
    else if (leftHalfEnd > ind)
        return quickSelect(nums, ind, l, leftHalfEnd-1);
    return nums[ind];
}
