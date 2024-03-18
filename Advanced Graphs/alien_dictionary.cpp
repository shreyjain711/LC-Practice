// ***Problem Desc***: alien lang uses same letters but diff order; given a dict of alien words telling the order of words, determine the order of letters

// ***compare each word with its next to get an edge between letters; do topological sort from these edges (keep edges & inDegree) [O(numWor.numWorLen + numLet<sup>2</sup>) time | O(numLet) space]***:
string alienOrder(vector<string> &words) {
    unordered_map<char, bitset<26>> edges;
    unordered_map<char, int> inDegree;
    for (int i=0; i+1<words.size(); ++i) {
        string w1 = words[i];
        string w2 = words[i+1];
        int a=0,b=0;
        while (a<w1.size() && b<w2.size() && w1[a]==w2[b]) {a++; b++;}
        if (a<w1.size() && b<w2.size() && !edges[w1[a]][w2[b]-'a']) {
            edges[w1[a]][w2[b]-'a'] = 1;
            if (!inDegree.count(w1[a])) inDegree[w1[a]]=0; inDegree[w2[b]]++;
       }
    }
    queue<char> tpSort; string order = "";
    for (auto count: inDegree) if (!count.second) {tpSort.push(count.first);}
    while (!tpSort.empty()) {
        char curr = tpSort.front(); tpSort.pop(); order += curr; 
        for (int i=0; i<26; i++) {
            char next = 'a' + i;
            if (!edges[curr][i]) continue;
            if (--inDegree[next] == 0) tpSort.push(next);
        }
    } return order.size()==inDegree.size() ? order : "";
}
