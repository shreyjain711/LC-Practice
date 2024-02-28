// ***Problem Desc***: find number of connected components given all edges.
// ***Build adj list, DFS [O(V+E) time | O(V+E) space]***
// ***Union find, count num of roots at end [O(V+E) time | O(V) space]***:
vector<int> p;
int findRoot(int i) {if (p[i] != i) p[i] = findRoot(p[i]); return p[i];}
int countComponents(int n, vector<vector<int>>& edges) {
    p.resize(n); for(int i=0; i<n; ++i) p[i] = i;
    for (auto e: edges) {
        int p1 = findRoot(e[0]), p2 = findRoot(e[1]);
        if (p1 == p2) continue;
        else if (p1 < p2) p[p2] = p1;
        else p[p1] = p2;
    }
    int ans = 0; for(int i=0; i<n; ++i) ans += (int)findRoot(i) == i;
    return ans;
}
