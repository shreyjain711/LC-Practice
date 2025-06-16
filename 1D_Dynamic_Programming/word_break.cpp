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

// ***Start from last, go across each word, if exists, set ith bit to i+wordLen bit [O(n*NumWords) time|O(n) space]***:
bool wordBreak(string s, vector<string>& wordDict) {
  int n = s.size(); 
  vector<bool> possible(n+1); possible[n] = 1;
  for (int i=n-1; i>=0; --i) 
      for (auto w: wordDict) 
          if (s.substr(i, w.size())==w) 
              possible[i] = possible[i+w.size()];
  return possible[0];
}
