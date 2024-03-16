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
- ***Problem Desc***: given matrix of size m,n -> for any cell 0, set its entire row and col 0
- ***Store flags in separate row col arrs and then apply the flag [O(m.n) time | O(m+n) space]***:
  ```cpp
  void setZeroes(vector<vector<int>>& matrix) {
      int m=matrix.size(), n=matrix[0].size(); bitset<200>rows, cols;
      for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (!matrix[i][j]) {rows[i]=1; cols[j]=1;}
      for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (rows[i] || cols[j]) matrix[i][j] = 0;
  }
  ```
- ***find if first row and col have a 0, i.e. they will be 0, then use them as flag; if a cell 0,i = 0 then all cells in the row made 0, at end make first row col 0s [O(m.n) time | O(1) space]***:
  ```cpp
  void setZeroes(vector<vector<int>>& matrix) {
      int m=matrix.size(), n=matrix[0].size(); bool isFirstRow0=0, isFirstCol0=0;
      for (int i=0; i<m; ++i) if (!matrix[i][0]) isFirstRow0=1;
      for (int i=0; i<n; ++i) if (!matrix[0][i]) isFirstCol0=1;

      for (int i=1; i<m; ++i) for(int j=1; j<n; ++j) if(!matrix[i][j]) matrix[0][j]=matrix[i][0]=0;
      for (int i=1; i<m; i++) for(int j=1;j<n;j++) if(!matrix[i][0]||!matrix[0][j]) matrix[i][j]=0;

      if (isFirstRow0) for (int i=0; i<m; ++i) matrix[i][0] = 0;
      if (isFirstCol0) for (int i=0; i<n; ++i) matrix[0][i] = 0;
  }
  ```

### ***[Happy Number](https://leetcode.com/problems/happy-number/)***:
- ***Problem Desc***: if num is happy then after n ops (op => take sum of sq of all digits) val reaches 1; if not then it will end up in a cycle
- ***Using set to store each op result [O(logn) time | O(logn) space]***:
  ```cpp
  int helper(int n) {int a=0; while(n) {int x=n%10; a+=x*x; n/=10;} return a;}
  bool isHappy(int n) {
      unordered_set<int> s;
      while (n!=1) {
          if (s.count(n)) return 0;
          s.insert(n); n = helper(n);
      }
      return n==1;
  }
  ```
- ***Using slow fast approach, slow = n, fast = op(n) then keep jumping till they not same, return if in end it is 1 [O(logn) time | O(1) space]***:
  ```cpp
  int helper(int n) {int a=0; while(n) {int x=n%10; a+=x*x; n/=10;} return a;}
  bool isHappy(int n) {
      int slow=n, fast=helper(n);
      while (slow != fast) {
          slow=helper(slow); fast=helper(helper(fast));
      } return slow == 1;
  }
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
