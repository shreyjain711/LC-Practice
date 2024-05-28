// ***Problem Desc***: in O(n) time, for an unsorted array, tell what would be the longest consec seq if it was sorted
// - **KEY POINT**: find if an elem is the start of a seq

// ***hashset to detect starts [O(n) time | O(n) space]***: make arr in set, check for each elem, if its prev doesn't exist then its a start, count from there
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
  
// ***sort, go across checking if prev elem is same then skip to next, if consecutive then incr currLen by 1, else reset currLen to 1 [O(n) time | O(1) space]***:
int longestConsecutive(vector<int>& nums) {
  if (nums.empty()) return 0;
  sort(begin(nums), end(nums));
  int lcs = 1, l = 1, n = nums.size();
  for(int i=1; i<n; ++i) {
      if (nums[i]==nums[i-1]) continue;
      if (nums[i]==nums[i-1]+1) {if (!l) l=2; else l++;}
      else l=1;
      lcs = max(lcs, l);
  } return lcs;
}
