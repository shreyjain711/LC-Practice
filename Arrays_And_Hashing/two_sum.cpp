// Problem Desc: which two indexes add to target; only one solution exists
// Brute [O(n^2) time | O(1) space]
vector<int> BRUTE_twoSum(vector<int>& nums, int target) {
    for(int i = 0; i<nums.size(); ++i) {
        for(int j = i+1; j<nums.size(); ++j) {
            if (nums[i] + nums[j] == target) return {i, j};
        }
    }
    return {};
}

// hashmap [O(n) time | O(n) space]: keep a hashmap, check if 
// complement of current elem exists, keep adding elem till it doesn't
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    for (int i = 0; i<nums.size(); ++i) {
        if (m.find(target-nums[i]) != m.end()) 
            return {i, m[target-nums[i]]};
        
        m[nums[i]] = i;
    }
    return {};
}
