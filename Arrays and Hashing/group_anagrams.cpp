// ***Problem Desc***: from list of strings form groups of anagrams

// ***Brute [O(l<sup>2</sup>.n<sup>2</sup>) time | O(n) space]***: compare pair-wise all strings (n<sup>2</sup>); comparison len<sup>2</sup>

// ***make unique identifier, use hashmap [O(n.l) time | O(n) space]***
string counterString_counts(string s) {
    string ans = "";
    int arr[26]; memset(arr, 0, sizeof(arr));
    for (char c:s) arr[c-'a']++;
    for (int i: arr) ans += to_string(i) + "|";
    return ans;
}

// O(n.l.logl) - but this is still faster as l is very small, hypo: the string comparison in this works faster
string counterString_sort(string s) {
    sort(s.begin(), s.end());
    return s;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int size = 0; unordered_map<string, int> m;
    vector<vector<string>> grps;
    for (string s: strs) {
        string identifier = counterString_sort(s);
        if (m.find(identifier) == m.end()) {
            m[identifier] = size++;
            grps.push_back(vector<string>());
        }
        grps[m[identifier]].push_back(s);
    }
    return grps;
}
