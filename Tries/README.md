# Problem Set

### ***[Implement Trie Prefix Tree](https://leetcode.com/problems/implement-trie-prefix-tree/)***:
- ***Problem Desc***: implement trie data structure
- ***TrieNode has a bool to indicate word ended there and 26 len arr/vector of pointers [O(n) time for search, insert and prefix | O(n) space]***:
  ```cpp
  struct TrieNode {
      bool hasEndHere; TrieNode* edges[26]; // 
      TrieNode (): hasEndHere(0) {
          for(int i = 0; i<26; ++i) edges[i] = NULL;
          // without initialization taken in random pointer vals, then can't null check
      }
      // can use vector<TrieNode*> for edges, only need to resize to 26 in constructor
  };
    
  class Trie {
  public:
      TrieNode * head;
      Trie() {
          head = new TrieNode();
      }
  
      void insert(string word) {
          TrieNode *curr = head;
          for (char c: word) {
              int i = c-'a';
              if (!curr->edges[i]) curr->edges[i] = new TrieNode();
              curr = curr->edges[i];
          } 
          curr->hasEndHere = 1;
      }
      
      bool search(string word) {
          TrieNode *curr = head;
          for (char c: word) {
              int i = c-'a';
              if (!curr->edges[i]) return 0;
              curr = curr->edges[i];
          } return curr->hasEndHere;
      }
      
      bool startsWith(string prefix) {
          TrieNode *curr = head;
          for (char c: prefix) {
              int i = c-'a';
              if (!curr->edges[i]) return 0;
              curr = curr->edges[i];
          } 
          for (auto e: curr->edges) if (e) return 1;
          return curr->hasEndHere;
      }
  };
  ```

### ***[Design Add And Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)***:
- ***Problem Desc***: add a word and search for it in O(n) time
- ***Using Trie data structure [O(n) time | O(n) space]***:
  ```cpp
  struct TrieNode {
      bool endHere; TrieNode* edges[26];
      TrieNode() :endHere(0) {for(int i=0; i<26;)edges[i++]=NULL;}
  };

  TrieNode* head;
  WordDictionary() {
      head = new TrieNode();
  }
  
  void addWord(string word) {
      TrieNode* curr = head;
      for(char c: word) {
          int i = c-'a';
          if (!curr->edges[i]) curr->edges[i] = new TrieNode();
          curr = curr->edges[i];
      } curr->endHere = 1;
  }
  
  bool search(string word) {
      return searchHelper(head, word, 0);
  }

  bool searchHelper(TrieNode* curr, string word, int i) {
      if (!curr) return 0;
      if (i == word.size()) return curr->endHere;
      bool ans = 0;
      if (word[i] == '.') 
          for(int k=0; k<26 && !ans;) ans |= searchHelper(curr->edges[k++], word, i+1);
      else 
          ans |= searchHelper(curr->edges[word[i]-'a'], word, i+1);
      return ans;
  }
  ```

### [Word Search II](https://leetcode.com/problems/word-search-ii/):
- ***Problem Desc***: given crossword board and a list of words, tell what all words exist in board
- ***make trie with word list, iterate over board, dfs when the letter in trie and dfs till following letters in trie [O(m.n + numStr.strLen) time | O(numStr.StrLen) space]***:
  ```cpp
  struct TrieNode {
      string endingHere; TrieNode *edges[26];
      TrieNode() : endingHere() {for(int i=0; i<26;) edges[i++]=NULL;}
  };
  TrieNode* head;
  
  void insert(string word) {
      TrieNode* curr = head;
      for(auto c: word) {
          int i = c-'a'; 
          if (!curr->edges[i]) curr->edges[i] = new TrieNode();
          curr = curr->edges[i];
      } curr->endingHere = word;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      head = new TrieNode(); for(auto w:words) insert(w);
      vector<string> ans; 
      int m = board.size(), n = board[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n));
      for (int i = 0; i<m; ++i) {
          for (int j = 0; j<n; ++j) {
              search(i, j, m, n, board, visited, head, ans);
          }
      }
      return ans;
  }

  void search(int i, int j, int m, int n, vector<vector<char>> &board, 
              vector<vector<bool>> &visited, TrieNode *curr, vector<string>& ans) {
      if (i<0 || i>=m || j<0 || j>=n || visited[i][j]) return;
      int ind = board[i][j]-'a';
      if (!curr->edges[ind]) return;
      visited[i][j] = 1;
      curr = curr->edges[ind];
      if (curr->endingHere.size()) {ans.push_back(curr->endingHere); curr->endingHere="";}
      int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};
      for (int k = 0; k<4; ++k) 
          search(i+dx[k], j+dy[k], m, n, board, visited, curr, ans);
      visited[i][j] = 0;
  }
  ```
  
