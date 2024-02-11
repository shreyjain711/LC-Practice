// ***Problem Desc***: given a str of brackets, check if they’re correct
// ***If else tree [O(n) time | O(1) space]***:
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

// ***Switch case [O(n) time | O(1) space]***:
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
