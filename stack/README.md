# Problem Set

### **[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)**: given a str of brackets, check if they’re correct
  - ***Problem Desc***: given a str of brackets, check if they’re correct
  - ***If else tree [O(n) time | O(1) space]***:
    ```cpp
    bool isValid(string s) {
        stack<char> st;
        for (char c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else return 0;
            } else if (c == '}') {
                if (!st.empty() && st.top() == '{') st.pop();
                else return 0;
            } else { // ]
                if (!st.empty() && st.top() == '[') st.pop();
                else return 0;
            }
        }
        return st.empty();
    }
    ```
  - ***Switch case [O(n) time | O(1) space]***:
    ```cpp
    bool isValid(string s) {
        stack<char> st;
        for (char c: s) {
            switch (c) {
                case '}':
                    if (!st.empty() && st.top() == '{') st.pop();
                    else return 0;
                    break;
                case ')':
                    if (!st.empty() && st.top() == '(') st.pop();
                    else return 0;
                    break;
                case ']':
                    if (!st.empty() && st.top() == '[') st.pop();
                    else return 0;
                    break;
                default:
                    st.push(c);
            }
        }
        return st.empty();
    }
    ```


### [Min Stack](https://leetcode.com/problems/min-stack/): give pop, push, top, min in O1
  - ***Problem Desc***: give pop, push, top, min in O1
  - ***stack of pair {elem, minTillNow} [O(n) time | O(1) space]***:
    ```cpp
    deque<pair<int, int>> s;
    MinStack() {}
    
    void push(int val) {
        if (s.size() > 0) s.push_back({val, min(val, s.back().second)});
        else s.push_back({val, val});
    }
    
    void pop() {s.pop_back();}
    int top() {return s.back().first;}
    int getMin() {return s.back().second;}
    ```
    

### **[Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)**:
  - ***Problem Desc***: evaluate reverse polish notation; given expression always valid
  - ***stack to store nums and results[O(n) time | O(n) space]***:
    ```cpp
    int evalRPN(vector<string>& tokens) {
        stack<int> st; int n1, n2;
        for (string s : tokens) {
            if (s == "+") {
                n2 = st.top(); st.pop();
                n1 = st.top(); st.pop();
                st.push(n1 + n2);
            } else if (s == "-") {
                n2 = st.top(); st.pop();
                n1 = st.top(); st.pop();
                st.push(n1 - n2);
            } else if (s == "*") {
                n2 = st.top(); st.pop();
                n1 = st.top(); st.pop();
                st.push(n1 * n2);
            } else if (s == "/") {
                n2 = st.top(); st.pop();
                n1 = st.top(); st.pop();
                st.push(n1 / n2);
            } else {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
    ```
    

### [**Generate Parentheses**](https://leetcode.com/problems/generate-parentheses/): generate all possible valid parentheses with n pairs
  - ***Problem Desc***: generate all possible valid parentheses with n pairs
  - ***Recursive [O(2<sup>n</sup>) time | O(<sup>n</sup>) space]***: recursively call a helper, acc to num of open brackets, make further calls
  - ***Simul recur iter, through stacks[O(2<sup>n</sup>) time | O(2<sup>n</sup> space]***:
    - a stack of pair of (string, pair of (numOpen, numClose))
    - go over the stack, store results for next round in another stack
    - if numOpen == numClose
      - if == n: insert in ans arr
      - else (i.e. <n): insert a '(' and add to temp
    - else (can be only numOpen > numClose)
      - if numOpen < n: insert a '(' and add to temp
      - insert a ')' and add to temp
    ```cpp
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
    ```


### **[Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)**: given temp for each day, for each day tell how many days before a day with higher temp seen
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
  - ***[O() time | O() space]***:


### [**Car Fleet**](https://leetcode.com/problems/car-fleet/): given destination and list of car positions and speeds. find num of groups that’ll reach at target
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
  - ***[O() time | O() space]***:


### [**Largest Rectangle In Histogram**](https://leetcode.com/problems/largest-rectangle-in-histogram/): given bar heights in an arr
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
  - ***[O() time | O() space]***:
  - 
