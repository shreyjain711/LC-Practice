// ***Problem Desc***: make unique combinations with using elems only once, there can be duplicate elems in the array tho

// ***Backtracking, sort the arr and then skip looping on the elems if they're not the first elem and have a same value prior to them [O(2<sup>n</sup>) time | O(n) space]***:
void backtrack(int index, int &remaining, vector<int>& curr, 
                vector<int>& nums, vector<vector<int>>& ans) {
    if (remaining <= 0) {if (!remaining) ans.push_back(curr); return;}
    for (int i = index; i<nums.size(); ++i) {
        if (i>index && nums[i] == nums[i-1]) continue;
        curr.push_back(nums[i]); remaining -= nums[i];
        backtrack(i+1, remaining, curr, nums, ans);
        curr.pop_back(); remaining += nums[i];
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans; vector<int> curr;
    backtrack(0, target, curr, candidates, ans);
    return ans;
}
