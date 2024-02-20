// ***Problem Desc***: given crossword board and a list of words, tell what all words exist in board
// ***make trie with word list, iterate over board, dfs when the letter in trie and dfs till following letters in trie [O(m.n + numStr.strLen) time | O(numStr.StrLen) space]***:

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
    for (int i = 0; i<m; ++i)
        for (int j = 0; j<n; ++j) 
            search(i, j, m, n, board, visited, head, ans);
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
