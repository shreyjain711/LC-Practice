// ***Problem Desc***: add a word and search for it in O(n) time
// ***Using Trie data structure [O(n) time | O(n) space]***:
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
