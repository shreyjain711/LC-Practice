// Brute: O(nlogn) time, O(1) space
bool BRUTE_isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s==t;
}

// count and compare: O(n) time, O(1) space
bool FINAL_isAnagram(string s, string t) {
    int count[26]; memset(count, 0, sizeof(count));
    for(char c : s) count[c - 'a']++;
    for(char c : t) count[c - 'a']--;
    for(int i : count) if (i) return false;
    return true;
}
