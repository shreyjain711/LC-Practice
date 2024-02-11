// ***Problem Desc***: evaluate reverse polish notation; given expression always valid
// ***stack to store nums and results[O(n) time | O(n) space]***:
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
