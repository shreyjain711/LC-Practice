// ***Problem Desc:*** implement trie data structure
// ***TrieNode has a bool to indicate word ended there and 26 len arr/vector of pointers [O(n) time for search, insert and prefix | O(n) space]***:
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
