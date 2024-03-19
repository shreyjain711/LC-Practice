# Problem Set

### ***[Rotate Image](https://leetcode.com/problems/rotate-image/)***:
- ***Problem Desc***: given a square matrix, rotate it 90deg clockwise
- ***Take 4 corners, rotate, next cell adjoinging the corners is done next till next corner reached and then corner pointers decremented[O(n<sup>2</sup>) time | O(1) space]***:
- ***reverse the rows and then transpose [O(n<sup>2</sup>) time | O(1) space]***:
  ```cpp
  void rotate(vector<vector<int>>& matrix) {
      int n=matrix.size(); reverse(begin(matrix), end(matrix));
      for (int i=0; i<n; ++i)
          for (int j=i+1; j<n; j++)
              swap(matrix[i][j], matrix[j][i]);
  }
  ```

### ***[Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)***:
- ***Problem Desc***: print the clockwise spiral order of matrix
- ***have left, right, top, bottom pointers, go L->R (at T), T done so ++, T->B (at R), R--, R->L (at B), B--, B->T (at L), L++; keep going till L<=R & T<=B [O(m.n) time | O(1) space]***:
  ```cpp
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ans; int m=matrix.size(), n=matrix[0].size();
      for (int l = 0, r = n-1, t = 0, b = m-1; l<=r && t<=b; ) {
          for (int i=l; i<=r; ++i) ans.push_back(matrix[t][i]); t++;
          for (int i=t; i<=b; ++i) ans.push_back(matrix[i][r]); r--;
          if (t<=b) for (int i=r; i>=l; --i) ans.push_back(matrix[b][i]); b--;
          if (l<=r) for (int i=b; i>=t; --i) ans.push_back(matrix[i][l]); l++;
      } return ans;
  }
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
- ***Problem Desc***: given a number whose digits are in form of a vector with n-1th digit being the units; add 1 to it and return the result 
- ***Add a spare 0 in front, keep adding 1 from the last digit; at end remove first elem if it is 0 [O(n) time | O(1) space]***:
  ```cpp
  vector<int> plusOne(vector<int>& digits) {
      int n=digits.size(); digits.insert(digits.begin(), 0); digits[n]+=1;
      while (n) {digits[n-1]+=digits[n]/10; digits[n--]%=10;}
      if (!digits[0]) digits.erase(begin(digits));
      return digits;
  }
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
- ***Problem Desc***: given two large nums in string form, multiply them
- ***Multiply digitwise, i from n1-1..0, j n2-1..0, in the ans string, we make it n1+n2 of 0s init and then ans[i+j+1] gets mul result unit, carry in ans[i+j] [O(n1.n2) time | O(n1+n2) space]***:
  ```cpp
  string multiply(string num1, string num2) {
      int n1=num1.size(), n2=num2.size(); string ans(n1+n2, '0'); 
      for (int i=n2-1; ~i; --i) {
          for (int j=n1-1; ~j; --j) {
              int sum = (num2[i]-'0') * (num1[j]-'0') + (ans[i+j+1] - '0');
              ans[i+j+1] = sum%10 + '0'; ans[i+j] += sum/10;
          }
      } int i=0; while (i<n1+n2 && ans[i++] == '0'); i--; return ans.substr(i);
  }
  ```

### ***[Detect Squares](https://leetcode.com/problems/detect-squares/)***:
- ***Problem Desc***: given points on a grid, count num of squares possible if a point is given as a vertice
- ***Points x -> multiset(y); for given point, for each y pt on the same x, use it as vectical edge, form squares on its right and left [O(n<sup>2</sup>) time | O(n) space]***:
  ```cpp
  unordered_map<int, multiset<int>> xs; 
  DetectSquares() {}
  void add(vector<int> point) {xs[point[0]].insert(point[1]);}
  int count(vector<int> point) {
      int sqs = 0;
      for (auto y: xs[point[0]]) {
          int sideLen = abs(y-point[1]); if (!sideLen) continue;
          int x1 = point[0] + sideLen, x2 = point[0] - sideLen;
          sqs += (xs[x1].count(point[1]) * xs[x1].count(y));
          sqs += (xs[x2].count(point[1]) * xs[x2].count(y));
      }
      return sqs;
  }
  ```
- ***Points X -> {Y -> count}; for given point, for each y pt on the same x, use it as vectical edge, form squares on its right and left [O(n) time | O(n) space]***:
  ```cpp
  unordered_map<int, unordered_map<int,int>> counter; 
  DetectSquares() {}
  void add(vector<int> point) {counter[point[0]][point[1]]++;}
  int count(vector<int> point) {
      int sqs = 0;
      for (auto y: counter[point[0]]) {
          int sideLen = abs(y.first-point[1]); if (!sideLen) continue;
          int x1 = point[0] + sideLen, x2 = point[0] - sideLen;
          sqs += (counter[x1][point[1]] * counter[x1][y.first] * y.second);
          sqs += (counter[x2][point[1]] * counter[x2][y.first] * y.second);
      }
      return sqs;
  }
  ```
