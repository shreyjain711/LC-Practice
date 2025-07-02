// ***Problem Desc***: count min jumps needed for reaching the end

// ***in the range, iterate to find the next range, jumps++, then continue in the arr till new range and keep repeating [O(n) time | O(1) space]***:
int jump(vector<int>& nums) {
    if (nums.size()==1) return 0;
    int jumps=1, range=nums[0], pos=0; 
    while (range < nums.size()-1) {
        jumps++; int newRange = range;
        while (pos<=range) {
            newRange = max(newRange, pos+nums[pos++]);
        } range = newRange;
    } return jumps;
}

// ***iterate till second last elem, update range at each, if i==currRange then we at the end of lvl so make a jump, update currRange [O(n) time | O(1) space]***:
int jump(vector<int>& nums) {
  int jumps = 0, range = 0, currRange = 0; 
  for (int i=0; i<nums.size()-1; i++) {
      range = max(range, i+nums[i]);
      if (i==currRange) {
          jumps++; 
          currRange = range;
      }
  } return jumps;
}
