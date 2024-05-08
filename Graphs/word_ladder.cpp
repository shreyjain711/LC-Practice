// ***Problem Desc***: given list of equal len words, find out shortest path from word A to B while changing only 1 char in each step

/*
***bfs with the starting word, make hashset of wordList, for each possible variation of the current word in set, add to Q remove from set [O(n.wordLen<sup>2</sup>) time | O(n) space]***:
  - can't do bfs and check all words in the set for the next level, that's n<sup>2</sup>.m complexity, since n > m, this is inefficient
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int ans = 1; unordered_set<string> wordSet(begin(wordList), end(wordList)); 
    if (!wordSet.count(endWord)) return 0;
    queue<string> bfs; bfs.push(beginWord);
    while (bfs.size()) {
        int n = bfs.size(); ans++;
        for (int i = 0; i<n; ++i) {
            string s = bfs.front(); bfs.pop(); 
            for (int j=0; j<s.size(); ++j) {
                char c = s[j];
                for (char rep = 'a'; rep<='z'; ++rep) {
                    if (rep!=c) {
                        s[j] = rep;
                        if (wordSet.count(s)) {
                            if (s==endWord) return ans;
                            bfs.push(s); wordSet.erase(s);
                        }
                    }
                } s[j] = c;
            }
        } 
    } return 0;
}
