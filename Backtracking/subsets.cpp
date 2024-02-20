// ***Problem Desc***: make all possible subsets of given array

// ***Brute [O(2n) time | O(1) space]***: each elem can either be present or not be present, so 2^n possible combinations/subsets

// ***Recursively, push curr arr into ans, add curr elem into curr arr and the call again for next index, on return pop the curr elem [O(n<sup>2</sup>) time | O(n2) space]***:
void backtrack(int i, vector<int> &curr, vector<int> &nums, vector<vector<int>>& ans) {
    ans.push_back(curr);
    for(int j=i; j<nums.size();++j){
        curr.push_back(nums[j]);
        backtrack(j+1, curr, nums, ans);
        curr.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans; vector<int> curr;
    backtrack(0, curr, nums, ans);
    return ans;
}
