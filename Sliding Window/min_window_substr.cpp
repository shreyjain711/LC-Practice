// ***Problem Desc***: find substring in s that has all chars of str t
// ***Brute [O(n<sup>3</sup>) time | O(1) space]***: try every substring for every char count match

/*
***track nums of charCounts that curr window has and shrink or grow as per haves vs needs[O(n) time | O(1) space]***:
  - hashmap to track letters in t (not vector as that doesn't tell if a letter existed or not
  - size of map = needed; init haves = 0
  - track minLen and start point (don't save string it will exceed memory if too long)
  - start i, j from 0
    - if haves == needed then shrink
      - if curr j ptr's char in map, upadte counter and if counter turned negative then one need unmet so haves--
    - else
      - if i's char in map and on incrementing counter its value hits 0 then a need met and haves++
    - check again if haves==needed and minLen > currLen
      - set minLen and start vals
*/
string minWindow(string s, string t) {
    unordered_map<char, int> ctr;
    for (auto i: t) ctr[i]--;
    int haves = 0, needed = ctr.size(), minLen = s.length()+1, start = -1;
    for (int i = 0, j = 0; i<s.size() || haves == needed; ) {
        if (haves == needed) { // shrink
            if (ctr.find(s[j]) != ctr.end()) {
                ctr[s[j]]--; if (ctr[s[j]] < 0) haves--;
            } j++;
        } else {
            if (ctr.find(s[i]) != ctr.end()) {
                ctr[s[i]]++; if (ctr[s[i]] == 0) haves++;
            } i++;
        }
        if (haves == needed && minLen > i-j) {minLen = i-j; start = j;}
    }
    return (start!=-1) ? s.substr(start, minLen) : "";
}
