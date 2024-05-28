// ***Problem Desc***: given s1 and s2. check if a permutation of s1 exists in s2 as a substring
// ***Brute [O(s1.s2) time | O(1) space]***: check each s1 length substring for a match
// ***Make a window of size s1 on s2, keep moving till match found [O(s1+s2) time | O(1) space]***:
bool compareCounts(vector<int> &c1, vector<int> &c2) {
    for (int i=0; i<26; ++i) if (c1[i] != c2[i]) return 0;
    return 1;
}

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return 0;
    vector<int> c1(26), c2(26);
    for (char c: s1) c1[c-'a']++;
    for (int i = 0; i<s1.size(); ++i) c2[s2[i]-'a']++;
    if (compareCounts(c1, c2)) return 1;

    for (int i = s1.size(); i<s2.size(); i++) {
        c2[s2[i]-'a']++; c2[s2[i-s1.size()]-'a']--;
        if (compareCounts(c1, c2)) return 1;
    }
    return 0;
}
