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
