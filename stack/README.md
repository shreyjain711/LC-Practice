# Problem Set

### ***[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)***: given a str of brackets, check if they’re correct
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


### ***[Min Stack](https://leetcode.com/problems/min-stack/)***: give pop, push, top, min in O1
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
    

### ***[Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)***:
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
    

### ***[Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)***: generate all possible valid parentheses with n pairs
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


### ***[Daily Temperatures](https://leetcode.com/problems/daily-temperatures/)***: given temp for each day, for each day tell how many days before a day with higher temp seen
  - ***Problem Desc***: given temp for each day, for each day tell how many days before a day with higher temp seen
  - ***Stack, 0..n iter [O(n) time | O(n) space]***:
    - can also keep only the indexes in stack, see the temp from the actual array
    ```cpp
    vector<int> dailyTemperatures(vector<int>& temps) {
        vector<int> ans(temps.size(), 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < temps.size(); ++i) {
            while (!s.empty() && s.top().first < temps[i]) {
                ans[s.top().second] = i - s.top().second;
                s.pop();
            } s.push({temps[i], i});
        } return ans;
    }
    ```
  - ***Stack, n-1..0 iter [O(n) time | O(n) space]***: pop if curr elem is >= top


### ***[Car Fleet](https://leetcode.com/problems/car-fleet/)***: 
  - ***Problem Desc***: given destination and list of car positions and speeds. find num of groups that’ll reach at target
  - ***sort based on position, make descending levels of time in stack [O(n.logn) time | O(n) space]***:
    ```cpp
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        for (int i = 0; i<n; ++i) cars[i] = {position[i], speed[i]};
        
        sort(cars.begin(), cars.end());

        stack<double> fleets;

        for (auto car: cars) {
            double timeNeeded = (target-car.first) / (double) car.second;
            while (!fleets.empty() && fleets.top() <= timeNeeded) fleets.pop();
            fleets.push(timeNeeded);
        }

        return fleets.size();
    }
    ```


### ***[Largest Rectangle In Histogram***](https://leetcode.com/problems/largest-rectangle-in-histogram/)***: given bar heights in an arr
  - ***Problem Desc***: given bar heights in a histogram, what would be the largest rectangle that can be fit in the bars 
  - ***store the height and from which index that height is possible [O(n) time | O(n) space]***:
    - stack stores pairs -> height, index -> the pair indicates a rectangle of height h can be formed from index i
    - pop from stack when the top has a higher height than curr height since that rectangle can no longer be achieved
    - push in the curr height and the index would be that of the last rectangle evicted from the stack or that of the elem itself
    - trick: to avoid special while loop at end, add a 0 element to heights
    ```cpp
    int largestRectangleArea(vector<int>& heights) {
          heights.push_back(0);
          int ans = 0, n = heights.size();
          stack<pair<int,int>> indexStack;
          for (int i = 0; i<n; ++i) {
              int start = i;
              ans = max(ans, heights[i]);
              while (!indexStack.empty() && indexStack.top().first > heights[i]) {
                  ans = max(ans, indexStack.top().first*(i-indexStack.top().second));
                  start = indexStack.top().second;
                  indexStack.pop();
              }
              indexStack.push({heights[i], start});
          }
          return ans;
      }
    ```
  - ***store index of left and right smaller for each bar [O(n) time | O(n) space]***:
    - then for each bar calc the rectangle of its height since it can be formed from the point its left smaller till its right smaller was seen
