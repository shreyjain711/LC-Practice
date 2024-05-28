// ***Problem Desc***: longest substring where each char appears only once (chars can be other than alphanumeric vals as well)
// ***Brute [O(n<sup>2</sup>) time | O(1) space]***: make substrings starting from each index
// ***extend window while new chars haven't already appeared in it, contract when char repeated[O(n) time | O(1) space]***:
int lengthOfLongestSubstring(string s) {
    int n = s.length(), j = 0, maxLen = 0; 
    bitset<256> cache(0); 
    for (int i = 0; i < n; i++) {
        while (cache[s[i]] && j < i) cache[s[j++]] = 0;
        cache[s[i]] = 1;
        maxLen = max(maxLen, (int)cache.count());
        // replacing (i-j+1) with cache.count()
    }
    return maxLen;
}
