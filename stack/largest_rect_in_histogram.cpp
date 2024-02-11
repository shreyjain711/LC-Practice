/*
  ***Problem Desc***: given bar heights in a histogram, what would be the largest rectangle that can be fit in the bars 
    - ***store the height and from which index that height is possible [O(n) time | O(n) space]***:
      - stack stores pairs -> height, index -> the pair indicates a rectangle of height h can be formed from index i
      - pop from stack when the top has a higher height than curr height since that rectangle can no longer be achieved
      - push in the curr height and the index would be that of the last rectangle evicted from the stack or that of the elem itself
      - trick: to avoid special while loop at end, add a 0 element to heights
*/
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0);
    int ans = 0, n = heights.size();
    stack<pair<int,int>> indexStack;
    for (int i = 0; i<n; ++i) {
        int start = i;
        ans = max(ans, heights[i]);
        while (!indexStack.empty() && indexStack.top().first > heights[i]) {
            ans = max(ans, indexStack.top().first*(i-indexStack.top().second));
            start = indexStack.top().second;
            indexStack.pop();
        }
        indexStack.push({heights[i], start});
    }
    return ans;
}

/*
    ***store index of left and right smaller for each bar [O(n) time | O(n) space]***:
      - then for each bar calc the rectangle of its height since it can be formed from the point its left smaller till its right smaller was seen
*/
