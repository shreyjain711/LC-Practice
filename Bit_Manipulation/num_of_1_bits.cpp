// ***Problem Desc***: count num of 1s in binary rep of a number

// ***If lowest bit 1 (i.e &1 = 1) then add to count, then shift bits right i.e. div by 2 [O(logn) time | O(1) space***:
int hammingWeight(uint32_t n) {
    int a=0; while(n>0) {a+=n&1; n>>=1;} return a;
}
