// ***Problem Desc***: Given an arr with all elems repeating except 1, find that.

// ***Brute [O(n<sup>2</sup>) time | O(1) space]***: for each elem find its duplicate, for one we can't is the ans

// ***Better [O(n) time | O(n) space]***: use hashmap to track count of each elem

// ***XOR all vals, XOR of a val twice = 0 so only the non-duplicate elem remains [O(n) time | O(1) space***:
int singleNumber(vector<int>& nums) {
    int i=0; for(int n:nums) i^=n; return i;
}
