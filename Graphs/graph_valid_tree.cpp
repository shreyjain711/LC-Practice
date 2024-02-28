// ***Problem Desc***: acyclic graph with n nodes and n-1 edges is a tree

// ***Build adj list, DFS to detect cycle [O(V+E) time | O(V+E) space]***

// ***Union find, for each edge, check if roots same, false if yes, else do union and decrement number of unique roots, at end if numRoot==1 then true [O(V+E) time | O(V) space]***:
vector<int> p;
int findRoot(int i) {if (p[i] != i) p[i] = findRoot(p[i]); return p[i];}
bool validTree(int n, vector<vector<int>>& edges) {
    p.resize(n); for(int i=0; i<n; ++i) p[i] = i;
    for (auto e: edges) {
        int p1 = findRoot(e[0]), p2 = findRoot(e[1]);
        if (p1 == p2) return 0;
        else if (p1 < p2) p[p2] = p1;
        else p[p1] = p2;
        n--;
    }
    return n==1;
}
