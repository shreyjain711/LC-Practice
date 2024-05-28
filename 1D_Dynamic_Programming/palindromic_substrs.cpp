***Problem Desc***: count num of palindromic substrs in a given str
- ***Brute, check each [O(n<sup>3</sup>) time | O(1) space]***
- ***make a 2d dp, it tell if substr from i to j is a palindrome, go by the right diagonal, incre len each iter [O(n<sup>2</sup>) time | O(n<sup>2</sup>) space]***:
  ```cpp
  int countSubstrings(string s) {
      int n = s.size(), numPalins=n; 
      bool isPalin[n][n]; memset(isPalin, 0x1, sizeof isPalin);
      
      for (int l=1; l<n; ++l) {
          for (int i=0, j=i+l; i<n-l; ++i, ++j) {
              isPalin[i][j] = 0;
              if (isPalin[i+1][j-1] && s[i]==s[j]) {
                  isPalin[i][j] = 1; numPalins++;
              }
          }
      }
      
      return numPalins;
  }
  ```
- ***Expand, for both odd and even len, from each pos in str [O(n<sup>2</sup>) time | O(1) space]***:
  ```cpp
  void countPalins(int &numPalins, string s, int start, int end) {
      while (start>=0 && end<s.size() && s[start] == s[end]) {numPalins++; start--; end++;}
  }
  int countSubstrings(string s) {
      int n = s.size(), numPalins=0; 
      for (int i=0; i<n; ++i) {
          countPalins(numPalins, s, i, i);
          countPalins(numPalins, s, i, i+1);
      }
      return numPalins;
  }
