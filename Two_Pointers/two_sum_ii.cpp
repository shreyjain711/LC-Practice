vector<int> twoSum(vector<int>& nums, int target) {
    int i1 = 0, i2 = nums.size()-1;
    while (i1 < i2) {
        int s = nums[i1]+nums[i2];
        if (s < target) ++i1;
        else if (s > target) --i2;
        else return {i1+1, i2+1};
    }
    return {-1, -1};
}
