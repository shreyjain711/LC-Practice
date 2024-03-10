# Problem Set

### ***[Single Number](https://leetcode.com/problems/single-number/)***: 
- ***Problem Desc***: Given an arr with all elems repeating except 1, find that.
- ***Brute [O(n<sup>2</sup>) time | O(1) space]***: for each elem find its duplicate, for one we can't is the ans
- ***Better [O(n) time | O(n) space]***: use hashmap to track count of each elem
- ***XOR all vals, XOR of a val twice = 0 so only the non-duplicate elem remains [O(n) time | O(1) space***:
  ```cpp
  int singleNumber(vector<int>& nums) {
      int i=0; for(int n:nums) i^=n; return i;
  }
  ```

### ***[Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)***: 
- ***Problem Desc***: count num of 1s in binary rep of a number
- ***If lowest bit 1 (i.e &1 = 1) then add to count, then shift bits right i.e. div by 2 [O(logn) time | O(1) space***:
  ```cpp
  int hammingWeight(uint32_t n) {
      int a=0; while(n>0) {a+=n&1; n>>=1;} return a;
  }
  ```

### ***[Counting Bits](https://leetcode.com/problems/counting-bits/)***: 
- ***Problem Desc***: given n, return arr with no. of bits in ints from range 0 to n
- ***Sol[O() time | O() space***:
  ```cpp
  ```
- ***Sol[O() time | O() space***:
  ```cpp
  ```

### ***[Reverse Bits](https://leetcode.com/problems/reverse-bits/)***: 
- ***Problem Desc***: reverse bits of an unsigned int binary rep
- ***Sol[O() time | O() space***:
  ```cpp
  ```

### ***[Missing Number](https://leetcode.com/problems/missing-number/)***: 
- ***Problem Desc***: n length arr with all but one elem in range 0,n. find missing num
- ***Sol[O() time | O() space***:
  ```cpp
  ```

### ***[Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/)***: 
- ***Problem Desc***: add two ints without + or - ops.
- ***Sol[O() time | O() space***:
  ```cpp
  ```
- ***Sol[O() time | O() space***:
  ```cpp
  ```

### ***[Reverse Integer](https://leetcode.com/problems/reverse-integer/)***:
- ***Problem Desc***: reverse int. return 0 if on reversing num out of 32 bit signed int range. Can’t use 64 bit num
- ***Sol[O() time | O() space***:
  ```cpp
  ```
