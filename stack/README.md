# Problem Set

### **[Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)**: given a str of brackets, check if they’re correct
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
  - ***[O() time | O() space]***:


### [Min Stack](https://leetcode.com/problems/min-stack/): give pop, push, top, min in O1
  - ***Problem Desc***: give pop, push, top, min in O1
  - ***stack of pair {elem, minTillNow} [O(n) time | O(1) space]***:
    ```cpp
    stack<pair<int, int>> s;
    MinStack() {}
    
    void push(int val) {
        if (s.size() > 0) s.push({val, min(val, s.top().second)});
        else s.push({val, val});
    }
    
    void pop() {s.pop();}
    int top() {return s.top().first;}
    int getMin() {return s.top().second;}
    ```
    

### **[Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)**:
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
  - ***[O() time | O() space]***:
    

### [**Generate Parentheses**](https://leetcode.com/problems/generate-parentheses/): generate all possible valid parentheses with n pairs
  - ***Problem Desc***:
  - ***Brute [O() time | O() space]***:
  - ***[O() time | O() space]***:


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
