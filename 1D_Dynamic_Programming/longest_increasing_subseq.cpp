// ***Problem Desc***: given unsorted arr, find len of longest possible increasing subsequence

// ***Brute, recursive, each elem can exist or not exist [O(2<sup>n</sup>) time | O(n) space]***

// ***iterate and check the LIS len at the curr elem comparing it with the elems before it and their LIS lens [O(n<sup>2</sup>) time | O(n) space]***:
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), ans=1; vector<int> lisLen(n, 1);
    for (int i=0; i<n; ++i) {
        for (int j=0; j<i; ++j) 
            if (nums[i] > nums[j]) lisLen[i] = max(lisLen[i], lisLen[j]+1);
        ans = max(ans, lisLen[i]);
    }
    return ans;
}

/*
***form the LIS, keep going over the arr, if elem > lis end then insert, else replace the one that should be replaced by it [O(n.logn) time | O() space]***:
  - at any point when lower bound replacement happens, the lis seq isn't the actual ans rather it's just sure to expand only in valid cases
    - e.g. 1 3 5 7 .. if 2 comes, it replaces 3.
      - if 9 comes next then it adds to the seq and the actual ans will be 1,3,5,7,9 however we'll have 1,2,5,7,9
      - this ensures instead of 3 we have 2, i.e. the lowest possible value however the seq len is still the valid one
*/
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(); vector<int> lis; lis.push_back(nums[0]);
    for (int i=1; i<n; ++i) {
        if (nums[i] > lis.back()) lis.push_back(nums[i]);
        else lis[lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin()] = nums[i];
    }
    return lis.size();
}
