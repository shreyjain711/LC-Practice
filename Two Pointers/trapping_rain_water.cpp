// ***Problem Desc***: each location in an array is a wall of the given height -> what's the water that will be trapped if it were to rain an infinite amount
// ***Brute [O(n) time | O(n) space]***: get max on left and max on right and their min is the height that can be retained ata pos
int trap(vector<int>& height) {
    int n = height.size(), minWall[n], ans = 0;
    memset(minWall, 0, sizeof(minWall));

    for (int i = 1; i<n-1; ++i) 
        minWall[i] = max(height[i-1], minWall[i-1]);
    
    for (int i = n-2; i>=0; --i)
        minWall[i] = min(minWall[i], max(height[i+1], minWall[i+1]));

    for (int i = 0; i<n; ++i) {
        cout << i << " " << minWall[i] << " " << max(0, minWall[i]-height[i]) << endl;
        ans += max(0, minWall[i]-height[i]);
    }
    
    return ans;
}

// ***[O() time | O() space]***: start from pointers on both ends, if left pointer's prev maxLeft is less than maxRight then max water retention would be as per maxLeft, no need to calc till curr position from the right side as well
int trap(vector<int>& h) {
    int n = h.size(), ans = 0;
    int l = 1, r = n-2, mL = h[0], mR = h[n-1];
    
    while (l<=r) {
        if (mL < mR) {
            ans += max(0, mL-h[l]);
            mL = max(mL, h[l]);
            l++;
        } else {
            ans += max(0, mR-h[r]);
            mR = max(mR, h[r]);
            r--;
        }
    }
    
    return ans;
}
