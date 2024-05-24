// ***Problem Desc***: given tickets with to and fro given, find the lexically smallest path that uses all tickets, starting from JFK

// ***Sort and then make adjList with a queue; we do dfs and pop the airport being visited, and once dfs back then we push to ans [O(A+TlogT) time | O(T) space]***:
vector<string> findItinerary(vector<vector<string>>& tickets) {
    sort(begin(tickets), end(tickets));
    unordered_map<string,queue<string>> adjList; vector<string> ls;
    for (auto t: tickets) adjList[t[0]].push(t[1]);
    dfs("JFK", adjList, ls); reverse(begin(ls), end(ls)); return ls;
}
void dfs (string curr, unordered_map<string,queue<string>> &adjList, vector<string> &ls) {
    while(adjList[curr].size()) {
        string next = adjList[curr].front(); adjList[curr].pop();
        dfs (next, adjList, ls);
    } ls.push_back(curr);
}
