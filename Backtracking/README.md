# Problem Set

### ***[Subsets](https://leetcode.com/problems/subsets/)***:
- ***Problem Desc***: make all possible subsets of given array
- ***Recursively, push curr arr into ans, add curr elem into curr arr and the call again for next index, on return pop the curr elem [O(n.2<sup>n</sup>) time | O(n) space]***:
  ```cpp
  void backtrack(int i, vector<int> &curr, vector<int> &nums, vector<vector<int>>& ans) {
      ans.push_back(curr);
      for(int j=i; j<nums.size();++j){
          curr.push_back(nums[j]);
          backtrack(j+1, curr, nums, ans);
          curr.pop_back();
      }
  }

  vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans; vector<int> curr;
      backtrack(0, curr, nums, ans);
      return ans;
  }
  ```

### ***[Combination Sum](https://leetcode.com/problems/combination-sum/)***:
- ***Problem Desc***: given an arr of distince +ve nums, find all possible combinations of its elems (with replacement) that sum up to a given number
- ***backtracking, keep track of elems added and remaining sum after adding these elems [O(2<sup>target</sup>) time | O(target) space]***:
  ```cpp
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> ans; vector<int> curr;
      backtrack(0, target, curr, candidates, ans);
      return ans;
  }

  void backtrack(int i, int remaining, vector<int> &curr, 
                  vector<int>& nums, vector<vector<int>> &ans) {
      if (remaining<=0) {
          if (!remaining) ans.push_back(curr);
          return;
      }
      
      for(int j = i; j<nums.size(); ++j) {
          curr.push_back(nums[j]); remaining -= nums[j];
          backtrack(j, remaining, curr, nums, ans);
          curr.pop_back(); remaining += nums[j];
      }
  }
  ```

### ***[Permutations](https://leetcode.com/problems/permutations/)***:
- ***Problem Desc***: given an array, generate all permutations of its elements
- ***backtracking, swap i, j pairs for generating permutations [O(n.n!) time | O(n!) space]***:
  - j goes from i...end: not from i+1 since no swapped version is also a permutation
  - recursive call gets from i+1 and not from j+1 since for j>i+1, the swaps with i+1th elem get ruled out
  ```cpp
  void backtrack(int i, vector<int>& nums, vector<vector<int>>& ans) {
      if (i==nums.size()) {ans.push_back(nums);}
      for(int j = i; j<nums.size(); ++j) {
          swap(nums[i], nums[j]);
          backtrack(i+1, nums, ans);
          swap(nums[i], nums[j]);
      }
  }
  vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans; 
      backtrack(0, nums, ans);
      return ans;
  }
  ```

### ***[Subsets II](https://leetcode.com/problems/subsets-ii/)***:
- ***Problem Desc***: make unique subsets of array with duplicate elements
- ***Backtrack after sorting and skip looping on elems if they're not the first elem and have a same value prior to them [O(n.2<sup>n</sup>) time | O(n) space]***:
  ```cpp
  void backtrack(int ind, vector<int>& curr, vector<int>& nums, vector<vector<int>> &ans) {
      ans.push_back(curr);
      for (int i = ind; i<nums.size(); ++i) {
          if (i>ind && nums[i] == nums[i-1]) continue; //skipping if prev elem same
          curr.push_back(nums[i]);
          backtrack(i+1, curr, nums, ans);
          curr.pop_back();
      }
  }
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end()); //sorting
      vector<vector<int>> ans; vector<int> curr;
      backtrack(0, curr, nums, ans);
      return ans;
  }
  ```

### ***[Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)***:
- ***Problem Desc***: make unique combinations with using elems only once, there can be duplicate elems in the array tho
- ***Backtracking, sort the arr and then skip looping on the elems if they're not the first elem and have a same value prior to them [O(2<sup>n</sup>) time | O(n) space]***:
  ```cpp
  void backtrack(int index, int &remaining, vector<int>& curr, 
                  vector<int>& nums, vector<vector<int>>& ans) {
      if (remaining <= 0) {if (!remaining) ans.push_back(curr); return;}
      for (int i = index; i<nums.size(); ++i) {
          if (i>index && nums[i] == nums[i-1]) continue;
          curr.push_back(nums[i]); remaining -= nums[i];
          backtrack(i+1, remaining, curr, nums, ans);
          curr.pop_back(); remaining += nums[i];
      }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int>> ans; vector<int> curr;
      backtrack(0, target, curr, candidates, ans);
      return ans;
  }
  ```

### ***[Word Search](https://leetcode.com/problems/word-search/)***:
- ***Problem Desc***: given a word and a crossword board, find if it exists anywhere
- ***backtracking: traverse over grid, dfs from each cell, if letter of string matches then continue dfs, keep track of visited  [O(m.n.3<sup>len</sup>) time | O(len) space]***:
  - optimization: reverse word if its last letter occurs less frequently than the first -> few dfs calls this way
  ```cpp
  int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
  bool backtrack(int i, int j, int &m, int &n, int si, string &word,
                  vector<vector<bool>> &visited, vector<vector<char>>&  board) {
      if (si == word.size()) return 1;
      if (i<0 || i>=m || j<0 || j>=n || visited[i][j] || board[i][j] != word[si]) return 0;
      for (int a=0; a<4; ++a) {
          visited[i][j] = 1;
          if (backtrack(i+dx[a], j+dy[a], m, n, si+1, word, visited, board)) return 1;
          visited[i][j] = 0;
      }
      return 0;
  }
  bool exist(vector<vector<char>>& board, string word) {
      int m = board.size(), n = board[0].size();

      // optimization: reverse word if its last letter 
      // occurs less frequently than first letter
      int len = word.size(), firstChar = 0, lastChar = 0;
      for(int i=0; i<m; i++) {
          for(int j=0; j<n; j++) {
              if(board[i][j] == word[0]) firstChar++;
              else if(board[i][j] == word[len-1]) lastChar++;
          }
      }
      if(firstChar > lastChar) reverse(word.begin(), word.end());

      vector<vector<bool>> visited(m, vector<bool>(n));
      for (int i=0; i<m; ++i) 
          for (int j=0; j<n; ++j) 
              if (backtrack(i, j, m, n, 0, word, visited, board)) 
                  return 1;
      return 0;
  }
  ```

### ***[Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)***:
- ***Problem Desc***: possible ways to part given string such that each partition is a palindrome
- ***Backtracking, start from 0th index, keep inc subStr and if it is a palindrome then recur call on remainder string [O(n.2^n) time | O(n) space]***:
  ```cpp
  bool isPalindrome(string str) {
      int i = 0, j = str.size()-1;
      while (i<j) if (str[i++] != str[j--]) return 0;
      return 1;
  }
  void backtrack(int ind, string &s, vector<string>&vecStr, vector<vector<string>>&ans) {
      if (ind==s.size()) {ans.push_back(vecStr); return;}
      for(int i = ind; i<s.size(); ++i) {
          string sub = s.substr(ind, i-ind+1);
          if (isPalindrome(sub)) {
              vecStr.push_back(sub);
              backtrack(i+1, s, vecStr, ans);
              vecStr.pop_back();
          }
      }
  }
  vector<vector<string>> partition(string s) {
      vector<vector<string>> ans;
      vector<string> vecStr;
      backtrack(0, s, vecStr, ans);
      return ans;
  }
  ```

### ***[Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)***:
- ***Problem Desc***: given a string with digit chars, produce possible strings using the num pad on old phones
- ***Backtracking, go through digits, for each digit, recur call with each of its possible value; when recur call at end, store str formed [O(n.4<sup>n</sup>) time | O(n) space]***:
  ```cpp
  unordered_map<char, string> numMap;
  void backtrack(string &code, int di, string &digits, vector<string>& ans) {
      if (di == digits.size()) {ans.push_back(code); return;}
      char num = digits[di];
      for(auto c: numMap[num]) {code += c; backtrack(code, di+1, digits, ans); code.pop_back();}
  }
  vector<string> letterCombinations(string digits) {
      vector<string> ans; if (!digits.size()) return ans; string code="";
      numMap['2'] = "abc"; numMap['3'] = "def"; numMap['4'] = "ghi"; numMap['5'] = "jkl";
      numMap['6'] = "mno"; numMap['7'] = "pqrs"; numMap['8'] = "tuv"; numMap['9'] = "wxyz";
      backtrack(code, 0, digits, ans);
      return ans;
  }
  ```

### ***[N Queens](https://leetcode.com/problems/n-queens/)***:
- ***Problem Desc***: given n, place n queens on an nxn grid such that none can kill each other
- ***backtracking: maintain board, go over each row and in each row each col, add in a queen if board still valid, continue; (check only prev i,same j & diagonals up-left and up-right [O(n!) time | O(n<sup>2</sup>) space]***:
  ```cpp
  vector<vector<string>> solveNQueens(int n) {
      if (n==2||n==3) return {};
      vector<vector<string>> boards; vector<string> board(n, string(n,'.'));
      backtrack(0, n, board, boards); return boards;
  }
  void backtrack(int i, int &n, vector<string> &board, vector<vector<string>> &boards) {
      if (i==n) {boards.push_back(board); return;}
      for (int j=0; j<n; j++) {
          board[i][j] = 'Q';
          if (isValid(i, j, board)) backtrack(i+1, n, board, boards);
          board[i][j] = '.';
      }
  }
  bool isValid(int &i, int &j, vector<string>&board) {
      int n = board.size();
      for (int d=1; d<=i; d++) {
          if (board[i-d][j]=='Q') return 0;
          if (j-d>=0 && board[i-d][j-d] == 'Q') return 0;
          if (j+d<n && board[i-d][j+d] == 'Q') return 0;
      } return 1;
  }
  ```
