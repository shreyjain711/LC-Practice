// ***Problem Desc***: given a undirected graph, clone it

// ***Iterative bfs, clone map maintain and keep pointing according and check if already visited [O(V+E) time | O(V+E) space]***:
Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> cloneMap;
    unordered_set<Node*> visited;
    queue<Node*> bfs; 
    if (node) bfs.push(node);
    while (!bfs.empty()) {
        Node* curr = bfs.front(); bfs.pop();
        if (visited.find(curr) != visited.end()) continue;
        visited.insert(curr);
        if(cloneMap.find(curr) == cloneMap.end()) cloneMap[curr] = new Node(curr->val);
        for (auto neighbor: curr->neighbors) {
            bfs.push(neighbor);
            if(cloneMap.find(neighbor) == cloneMap.end()) 
                cloneMap[neighbor] = new Node(neighbor->val);
            cloneMap[curr]->neighbors.push_back(cloneMap[neighbor]);
        }
    }
    return (cloneMap.size()) ? cloneMap[node] : NULL;
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
