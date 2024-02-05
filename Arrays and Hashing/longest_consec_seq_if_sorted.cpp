int longestConsecutive(vector<int>& nums) {
    int lcs = 0, temp = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for (int n : nums) {
        if (s.find(n-1)==s.end()) { // i.e. is start
            while (s.find(n++) != s.end()) temp++;
            lcs = max(lcs, temp);
            temp = 0;
        }
    }
    return lcs;
}
