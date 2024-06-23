// ***Problem Desc***: given a string s and regex pattern p, check if s is a match

// ***Brute [O(2<sup>n+m</sup>) time | O(n) space]***: backtracking with checking if each char of the string is to be taken as part of current pattern variable

/*
***cache the results of backtracking  [O(n.m) time | O(n.m) space]***
  - if p end, s also end
  - check in cache
  - if not last char in p and next star then check skip 2 in p and if still not 1 and i<s then 1 forward in s + 1,2 forward in both
  - else check for curr char match and continue
*/
bool isMatch(string s, string p) {
    int n=s.size(), m=p.size(); vector<vector<int>> cache(n+1, vector<int>(m+1,-1));
    return helper(0, 0, s, p, cache);
}
bool helper(int i, int j, string &s, string &p, vector<vector<int>> &cache) {
    if (j==p.size()) return i==s.size();
    if (cache[i][j]!=-1) return cache[i][j];
    cache[i][j] = 0;
    if (j+1<p.size() && p[j+1]=='*') {
        cache[i][j] = helper(i, j+2, s, p, cache);
        if (!cache[i][j]) 
            cache[i][j] = i<s.size() && (s[i]==p[j] || p[j]=='.') 
                        && (helper(i+1, j, s, p, cache) || helper(i+1, j+2, s, p, cache));
    } else {
        cache[i][j] = i<s.size() && (s[i]==p[j] || p[j]=='.') 
                        && helper(i+1, j+1, s, p, cache);
    } return cache[i][j];
}
