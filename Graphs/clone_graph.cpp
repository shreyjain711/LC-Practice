// ***Problem Desc***: given a undirected graph, clone it

// ***Iterative bfs, clone map maintain and keep pointing according and check if already visited [O(V+E) time | O(V+E) space]***:
Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    unordered_map<Node*, Node*> clones;
    queue<Node*> bfs; bfs.push(node);
    while (bfs.size()) {
        Node* curr = bfs.front(); bfs.pop();
        if (!clones.count(curr)) clones[curr] = new Node(curr->val);
        if (clones[curr]->neighbors.size() != curr->neighbors.size()) {
            for (auto n: curr->neighbors) {
                if (!clones.count(n)) clones[n] = new Node(n->val);
                clones[curr]->neighbors.push_back(clones[n]);
                if (clones[n]->neighbors.size() != n->neighbors.size()) bfs.push(n);
            }
        }
    } return clones[node];
}

// ***Recursive, check if it already exists in clone map, if not then create clone node, put  in map, set neighbors recursively [O(V+E) time | O(V+E) space]***:
unordered_map<Node*, Node*> cloneMap;
Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    if (cloneMap.count(node)) return cloneMap[node];
    cloneMap[node] = new Node(node->val);
    for (auto neighbor : node->neighbors)
        cloneMap[node]->neighbors.push_back(cloneGraph(neighbor));
    return cloneMap[node];
}
