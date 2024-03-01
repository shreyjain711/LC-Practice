// ***Problem Desc***: given string, find its longest palindrome substr

// ***Brute, check for every substr [O(n<sup>3</sup>) time | O(1) space]***

// ***2D DP, table reps if sub str from i..j is a palin, iter diagonally (right) by increasing len, i=0, j=i+len [O(n<sup>2</sup>) time | O(<sup>2</sup>) space]***:
string longestPalindrome(string s) {
    int n = s.size(), ansStart = 0, ansLen = 1; 
    bool isPalin[n][n]; memset(isPalin, 0x1, sizeof isPalin);

    for (int len = 1; len<n; len++) {
        for (int i=0, j; i<n-len; ++i) {
            j = i+len;
            isPalin[i][j] = 0;
            if ((i>j || isPalin[i+1][j-1]) && s[i]==s[j]) {
                isPalin[i][j]=1;
                if (ansLen < len+1) {ansStart=i; ansLen=len+1;}
            }
        }
    }
    return s.substr(ansStart, ansLen);
}


/*
***Expand from each elem rightwards till chars same, then expand both sides if same, i moves to where the curr elem's repeat ends [O(n<sup>2</sup>) time | O(n) space]***:
  - DP approach will take (n.n-1)/2 steps, this practically takes lesser even tho same complexity
  - i moves to point where curr elem's repeat ends because all of the variants with the same char at centre would already be calculated
    - no point trying for odd len from here either as the longest palin will keep all same chars at centre regardless if the centre gets odd len or even
*/
string longestPalindrome(string s) {
    int n = s.size(), ansStart = 0, ansLen = 1; 
    
    for (int i = 0; i<n-1; i++) {
        int l = i-1, r=i;
        while(r<n && s[i]==s[r]) { //expand centre rightwards till same chars
            if(ansLen < r-i+1) {ansLen=r-i+1; ansStart=i;} 
            r++;
        } i=r-1; // we move i to point where the same char existence ends
        while (l>=0 && r<n && s[l]==s[r]) { // expand on both sides
            if(ansLen < r-l+1) {ansLen = r-l+1; ansStart=l;}
            l--;r++;
        }
    }
    return s.substr(ansStart, ansLen);
}
