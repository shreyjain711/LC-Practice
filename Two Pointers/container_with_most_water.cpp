int maxArea(vector<int>& height) {
    int maxArr = 0, i = 0, j = height.size()-1;
    while (i<j) {
        maxArr = max(maxArr, min(height[i], height[j]) * (j-i));
        if (height[i] < height[j]) ++i;
        else --j;
    }
    return maxArr;
}
