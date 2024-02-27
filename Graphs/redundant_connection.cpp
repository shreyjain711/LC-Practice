// ***Problem Desc***: given n connections between nodes 1..n; one connection is redundant, graph stays connected even without that edge, find it

/*
***union-find algo [O(n) time | O(n) space]***:
  - make an arr with of size n+1, each elem = 0, i.e. not in set
  - iterate over all edges:
    - if both unset elems, use the smallest index as the root for both
    - if one of them unset, point the unset to the others' root
    - if both set, check if root same, i.e. redundant edge, else point the bigger root to smallest (union op)
*/
int findRoot(int i, vector<int> &dsu) {
    if (dsu[i] == i) return i;
    dsu[i] = findRoot(dsu[i], dsu);
    return dsu[i];
}
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> dsu(edges.size()+1), ans;

    for (auto e: edges) {
        if (!dsu[e[0]] && !dsu[e[1]]) { 
            // union and use smaller elem for root
            dsu[e[0]] = dsu[e[1]] = min(e[0], e[1]); 
        } else if (!dsu[e[0]] || !dsu[e[1]]) { 
            // union, max gets rid of unset (0) elem
            dsu[e[0]] = dsu[e[1]] = max(findRoot(e[0], dsu), findRoot(e[1], dsu)); 
        } else {
            int root1 = findRoot(e[0], dsu), root2 = findRoot(e[1], dsu);
            if (root1 == root2) ans = e;
            // union to keep smaller root
            dsu[root1] = dsu[root2] = min(root1, root2); 
        }
    }
    return ans;
}
