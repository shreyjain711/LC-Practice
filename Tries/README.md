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

### [Design Add And Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/):
- ***Problem Desc***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
  
