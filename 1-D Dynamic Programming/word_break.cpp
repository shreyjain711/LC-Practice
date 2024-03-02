// ***Problem Desc***: break string to words from the given dict

// ***1D boor arr to rep if breaking word till ith pos possible; at each pos, go upto dictWordLen back, if in dict remaining can be broken = 1 [O(len.dictWordLen) time | O(len) space]***:
bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = s.size(); vector<bool> canBreak(n+1, 0); canBreak[0] = 1;
    for (int i=1; i<=n; ++i) {
        int j = i-1;
        while (j>=0 && i-j<=20 && !canBreak[i]) {
            if (dict.find(s.substr(j, i-j)) != dict.end()) {
                canBreak[i] = canBreak[j];
            } j--;
        }
    }
    return canBreak[n];
}
