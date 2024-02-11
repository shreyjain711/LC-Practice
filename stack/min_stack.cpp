// ***Problem Desc***: give pop, push, top, min in O1
// ***stack of pair {elem, minTillNow} [O(n) time | O(1) space]***:
deque<pair<int, int>> s;
MinStack() {}

void push(int val) {
    if (s.size() > 0) s.push_back({val, min(val, s.back().second)});
    else s.push_back({val, val});
}

void pop() {s.pop_back();}
int top() {return s.back().first;}
int getMin() {return s.back().second;}
