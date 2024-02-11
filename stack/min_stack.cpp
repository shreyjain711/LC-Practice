// ***Problem Desc***: give pop, push, top, min in O1
// ***stack of pair {elem, minTillNow} [O(n) time | O(1) space]***:
stack<pair<int, int>> s;
MinStack() {}

void push(int val) {
    if (s.size() > 0) s.push({val, min(val, s.top().second)});
    else s.push({val, val});
}

void pop() {s.pop();}
int top() {return s.top().first;}
int getMin() {return s.top().second;}
