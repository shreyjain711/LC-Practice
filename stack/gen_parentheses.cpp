// ***Problem Desc***: generate all possible valid parentheses with n pairs

// ***Recursive [O(2<sup>n</sup>) time | O(<sup>n</sup>) space]***: recursively call a helper, acc to num of open brackets, make further calls

/*
***Simul recur iter, through stacks[O(2<sup>n</sup>) time | O(2<sup>n</sup> space]***:
  - a stack of pair of (string, pair of (numOpen, numClose))
  - go over the stack, store results for next round in another stack
  - if numOpen == numClose
    - if == n: insert in ans arr
    - else (i.e. <n): insert a '(' and add to temp
  - else (can be only numOpen > numClose)
    - if numOpen < n: insert a '(' and add to temp
    - insert a ')' and add to temp
*/
vector<string> generateParenthesis(int n) {
    vector<string> ans; 
    vector<pair<string, vector<int>>> curr(1, {"", {0,0}}), next; 
    while (curr.size()) {
        next.clear();
        for(auto t: curr) {
            string s = t.first; int open = t.second[0], close = t.second[1];
            if (open == n && close == n) {ans.push_back(s); continue;}
            if (open > close) next.push_back({s+')', {open, close+1}});
            if (open < n) next.push_back({s+'(', {open+1, close}});
        } curr = next;
    }
    return ans;
}

// ***Backtracking [O(2<sup>n</sup>) time | O(<sup>n</sup>) space]***: keep open and close count in recursive calls and take actions accordingly
vector<string> generateParenthesis(int n) {
    vector<string> ans; 
    string s = ""; backtrack(0, 0, n, s, ans); 
    return ans;
}
void backtrack(int open, int close, int n, string &s, vector<string>&ans) {
    if (open == n && close == n) {ans.push_back(s); return;}
    if (open > close) {s += ')'; backtrack(open, close+1, n, s, ans); s.pop_back();}
    if (open < n) {s += '('; backtrack(open+1, close, n, s, ans); s.pop_back();}
}
