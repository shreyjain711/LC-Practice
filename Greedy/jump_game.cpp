// ***Problem Desc***: given arr where each elem = num steps that one can jump further from that index; can we reach index n-1 if starting from 0

// ***keep track of range, at each elem new range i+arr[i]; if it reaches n-1 then can reach else not [O(n) time | O(1) space]***:
bool canJump(vector<int>& nums) {
    int range = nums[0];
    for (int i=0; i<=range;++i) {
        range = max(range, i+nums[i]);
        if (range+1 >= nums.size()) return 1;
    }
    return 0;
}
