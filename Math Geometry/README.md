# Problem Set

### ***[Rotate Image](https://leetcode.com/problems/rotate-image/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Happy Number](https://leetcode.com/problems/happy-number/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Plus One](https://leetcode.com/problems/plus-one/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Pow(x, n)](https://leetcode.com/problems/powx-n/)***:
- ***Problem Desc***: raise numbers to a given power 
- ***Recur - set base cases (n==-1,0,1) and then calc pow(x,n/2), return sq of pow/2 and if n is odd then .n [O(logn) time | O(logn) space]***:
  ```cpp
  double myPow(double x, int n) {
      if (!n) return 1;
      if (n==1) return x;
      if (n==-1) return 1/x;
      double sqrt = myPow(x, n/2);
      return (n%2 ? (n>0? x : (1/x)) : 1) * sqrt * sqrt;
  }
  ```
- ***Iter - handle n -ve by x = 1/x; res = 1, while n, if n is odd then res*=x then x square and n/=2 [O(logn) time | O(1) space]***:
  ```cpp
  double myPow(double x, int n) {
      if (n<0) {x=1/x;}
      double res=1;
      while (n) {
          if (n%2) res*=x;
          x*=x; n/=2;
      } return res;
  }
  ```

### ***[Multiply Strings](https://leetcode.com/problems/multiply-strings/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```

### ***[Detect Squares](https://leetcode.com/problems/detect-squares/)***:
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
