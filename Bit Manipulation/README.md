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
- ***Forward solve, add 0 then add a val[0]+1 then repeat on this set of 2 vals, then on 4, keep on till hitting n size [O(n) time | O(1) space***:
  ```cpp
  vector<int> countBits(int n) {
      vector<int> ans(1);
      while (ans.size()<=n) {
          int t=ans.size(); 
          for (int i=0; i<t && ans.size()<=n; ++i) {
              ans.push_back(ans[i]+1);
          }
      } return ans;
  }
  ```
- ***Lookback, val[n] = val[n/2] + n%2 [O(n) time | O(1) space***:
  ```cpp
  vector<int> countBits(int n) {
      vector<int> ans(n+1);
      for (int i=1; i<=n; ++i) {
          ans[i] = ans[i/2] + i%2;
      } return ans;
  }
  ```

### ***[Reverse Bits](https://leetcode.com/problems/reverse-bits/)***: 
- ***Problem Desc***: reverse bits of an unsigned int binary rep
- ***32 times, shift ans left(multiply 2), set ans' unit as per curr unit of n, shift n right 1(div by 2) [O(logn) time | O(1) space***:
  ```cpp
  uint32_t reverseBits(uint32_t n) {
      uint32_t a=0, c=32; 
      while(c--) {a<<=1; a|=n&1; n>>=1;} return a;
  }
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
- ***check if current rev val isn't >INT_MAX/10 or <INT_MIN/10 then regular reverse flow [O(logn) time | O(1) space***:
  ```cpp
  int reverse(int x) {
      int rev = 0;
      while (x) {
          if (rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
          rev = rev*10 + x%10; x /= 10;
      } return rev;
  }
  ```
