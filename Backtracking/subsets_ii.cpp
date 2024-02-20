// ***Problem Desc***: make unique subsets of array with duplicate elements

// ***Backtrack after sorting and skip looping on elems that have a same value prior to them [O(n.2<sup>n</sup>) time | O(n) space]***:
void backtrack(int ind, vector<int>& curr, vector<int>& nums, vector<vector<int>> &ans) {
    ans.push_back(curr);
    for (int i = ind; i<nums.size(); ++i) {
        if (i>ind && nums[i] == nums[i-1]) continue;
        curr.push_back(nums[i]);
        backtrack(i+1, curr, nums, ans);
        curr.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans; vector<int> curr;
    backtrack(0, curr, nums, ans);
    return ans;
}
