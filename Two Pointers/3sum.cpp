/*
  ***Problem Desc***: array, unsorted, find unique combinations of 3 elem adding to 0
  ***Brute [O(n<sup>3</sup>) time | O(1) space]***: pick each one and try; 3rd degree nesting loops -> this will still give repeat triplets
  ***Sort, pick first and rest is two sum ii [O(n<sup>2</sup>) time | O(1) space]***:
      - sort to ensure no repeats, for first elem, go over each
      - stop going once hit a positive num since two nums greater than that can't make sum 0
      - do not pick a first elem if its previous is equal as for this first value, all pairs will already be accounted for
      - for the next two elem, in the rest of the array, use two pointer approach as in two sum ii
      - when match found, move left pointer enough so that it's not the same as the value where the match happened
          - need not move right as well as that'll automatically adjust to ensure no repeat value
*/
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans; int n = nums.size();
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i<n; ++i) {
        if (nums[i] > 0) break;
        if (i>0 && nums[i] == nums[i-1]) continue;
        int target = -nums[i], l = i+1, r = n-1;
        while (l<r) {
            int tempSum = nums[l]+nums[r];
            if (tempSum < target) l++;
            else if (tempSum > target) r--;
            else {
                ans.push_back({-target, nums[l++], nums[r--]});
                while(nums[l] == nums[l-1] && l<r) l++;
            }
        }
    }
    return ans;
}
