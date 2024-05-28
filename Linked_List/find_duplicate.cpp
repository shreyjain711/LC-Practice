// ***Problem Desc***: arr of n+1 elms and only 1 num repeats. **BUT, it can repeat more than twice**. Time linear, space constant

// ***Brute[O(n) time | O(n) space]***: hashmap to save count

/*
  ***slow, fast[O() time | O() space]***: Arr is LL, each val defines what index it points to. LL cycle problem
    - initiate s, f taking the first step from 0 i.e. s = arr[0], f = arr[arr[0]]
    - after first match, take one jump for s from 0 and for f from where it is.. next match will be at duplicate
*/
int findDuplicate(vector<int>& nums) {
    int i = nums[0], j = nums[nums[0]];
    while (i != j) {
        i = nums[i];
        j = nums[nums[j]];
    } i = 0;
    while (i != j) {
        i = nums[i];
        j = nums[j];
    }
    return i;
}
