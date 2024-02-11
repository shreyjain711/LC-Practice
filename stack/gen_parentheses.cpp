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
    stack<pair<string, pair<int,int>>> st; st.push({"", {0,0}});
    ans.clear();
    while (st.size()) {
        stack<pair<string, pair<int,int>>> temp;
        while (st.size()) {
            string str = st.top().first;
            int open = st.top().second.first, close = st.top().second.second;
            st.pop();
            if (open == close) {
                if (open == n) ans.push_back(str);
                else temp.push({str + '(', {open+1, close}});
            } else { // open > close
                if (open < n) temp.push({str + '(', {open+1, close}});
                temp.push({str + ')', {open, close+1}});
            }
        }
        st = temp;
    }

    return ans;
}
