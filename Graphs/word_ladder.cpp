// ***Problem Desc***: given list of equal len words, find out shortest path from word A to B while changing only 1 char in each step

/*
***bfs with the starting word, make hashset of wordList, for each possible variation of the current word in set, add to Q remove from set [O(n.wordLen<sup>2</sup>) time | O(n) space]***:
  - can't do bfs and check all words in the set for the next level, that's n<sup>2</sup>.m complexity, since n > m, this is inefficient
*/
bool isAdj(string a, string b) {
    int diff = 0; for(int i=0;i<a.size();++i) if (a[i]!=b[i]) diff++;
    return diff == 1;
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int ans = 1; queue<string> q; q.push(beginWord);
    unordered_set<string> wordSet(wordList.begin(), wordList.end());

    while (!q.empty()) {
        ans++; int sz = q.size();
        for (int i=0; i<sz; i++) {
            string currWord = q.front(), temp; q.pop();
            for(int l=0; l<currWord.size(); l++) {
                temp = currWord;
                for(char c='a'; c<='z'; c++) {
                    temp[l] = c;
                    if (wordSet.find(temp) == wordSet.end()) continue;
                    if (isAdj(currWord, temp)) {
                        if (temp == endWord) return ans;
                        q.push(temp);
                        wordSet.erase(temp);
    }}}}} return 0;
}
