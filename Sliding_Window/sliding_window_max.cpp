// ***Problem Desc***: a window of size k slides over an array of size n. for each window give its max element
// ***Brute [O(k.(n-k)) time | O(1) space]***: for each window check max linearly

/*
***once a max elem seen, then the ones smaller before it are no longer of use[O(n) time | O(k) space]***:
  - maintain a deque, a monotonically decreasing deque
    - we push to its back and get ans from the front
  - firstly, we push the curr elem (start i, j from 0)
    - first pop while the back elem is < the curr elem
  - then we push in the elem
  - then if front elem no longer in the window then we remove it
    - no need for while since only one such elem can be there in an iter
*/
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q; // no need to store both val and i, get val from nums
    vector<int> ans;
    for (int i = 0, j = 0; i<nums.size(); i++) {
        while (q.size() && nums[q.back()] < nums[i]) q.pop_back();
        q.push_back(i);
        if (q.size() && q.front() < j) q.pop_front();
        if (i >= k-1) {
            ans.push_back(nums[q.front()]); j++;
        }
    }
    return ans;
}
