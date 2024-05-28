// ***Problem Desc***: str has only upper case chars. Given k, find longest substr of only one letter that can be formed with k replacements 

// ***Brute [O(n<sup>2</sup>) time | O(1) space]***: try each substr

/*
***grow window till condition met, move along if not met, grow when met again [O(n) time | O(1) space]***:
  - optimization #1: no need to check for max count letter
    - since in one iteration only this letter's count is increasing so only this letter can be the contender for maxCount
  - optimization #2: move window along, no need to shrink
    - decreasing window size by only one ensure the window size remains same
    - window grows and it moves along the string till it can grow again
    - No need to decrease window size with while loop since ans can be a window bigger in size than ones already detected
*/
int characterReplacement(string s, int k) {
    int counts[26]; memset(counts, 0, sizeof(counts));
    int j = 0, res = 0, maxCount = 0;
    for (int i = 0; i < s.size(); i++) {
        counts[s[i]-'A']++;

        // optimization #1: no need to check for max count letter
        maxCount = max(maxCount, counts[s[i]-'A']); 

        // optimization #2: move window along, no need to shrink
        if (i-j+1 - maxCount > k) counts[s[j++]-'A']--;
        
        res = max(res, i-j+1);
    }
    return res;
}
