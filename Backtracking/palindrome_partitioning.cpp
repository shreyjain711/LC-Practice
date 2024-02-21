// ***Problem Desc***: possible ways to part given string such that each partition is a palindrome

// ***Backtracking, start from 0th index, keep inc subStr and if it is a palindrome then recur call on remainder string [O(n.2^n) time | O(n) space]***:
bool isPalindrome(string str) {
    int i = 0, j = str.size()-1;
    while (i<j) if (str[i++] != str[j--]) return 0;
    return 1;
}
void backtrack(int ind, string &s, vector<string>&vecStr, vector<vector<string>>&ans) {
    if (ind==s.size()) {ans.push_back(vecStr); return;}
    for(int i = ind; i<s.size(); ++i) {
        string sub = s.substr(ind, i-ind+1);
        if (isPalindrome(sub)) {
            vecStr.push_back(sub);
            backtrack(i+1, s, vecStr, ans);
            vecStr.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> vecStr;
    backtrack(0, s, vecStr, ans);
    return ans;
}
