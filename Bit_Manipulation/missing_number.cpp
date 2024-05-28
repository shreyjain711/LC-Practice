// ***Problem Desc***: n length arr with all but one elem in range 0,n. find missing num

// ***We use the XOR logic, XOR-ing a number twice = 0 [O(n) time | O(2) space***:
int missingNumber(vector<int>& nums) {
    int a=nums.size(); for(int i=0; i<nums.size(); ++i) {a^=i;a^=nums[i];} return a;
}
