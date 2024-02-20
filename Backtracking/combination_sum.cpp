// ***Problem Desc***: given an arr of distince +ve nums, find all possible combinations of its elems (with replacement) that sum up to a given number

// ***Brute [O(2<sup>n</sup> time | O(1) space]***: try every elem once and then restart, no backtracking

// ***backtracking [O(n<sup>2</sup>) time | O(n) space]***:
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans; vector<int> curr;
    backtrack(0, target, curr, candidates, ans);
    return ans;
}

void backtrack(int i, int remaining, vector<int> &curr, 
                vector<int>& nums, vector<vector<int>> &ans) {
    if (remaining<=0) {
        if (!remaining) ans.push_back(curr);
        return;
    }
    
    for(int j = i; j<nums.size(); ++j) {
        curr.push_back(nums[j]); remaining -= nums[j];
        backtrack(j, remaining, curr, nums, ans);
        curr.pop_back(); remaining += nums[j];
    }
}
