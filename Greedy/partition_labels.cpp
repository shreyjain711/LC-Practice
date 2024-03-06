// ***Problem Desc***: make as many partitions as possible such that each letter is at most in one partition only

// ***make intervals of start and end occur of each char, sort & merge overlapping intervals and for each the size append to ans [O(n) time | O(1) space]***:
vector<int> partitionLabels(string s) {
    vector<int> ans;
    vector<vector<int>> startEnd(26, vector<int>(2,-1));
    for (int i=0; i<s.size(); ++i) {
        int ind = s[i]-'a';
        if (startEnd[ind][0]==-1) startEnd[ind][0] = i;
        startEnd[ind][1]=i;
    }
    sort(begin(startEnd), end(startEnd));
    for (int i=0; i<25; ++i) {
        if (startEnd[i][0]==-1) {continue;}
        if (startEnd[i][1] > startEnd[i+1][0]) {
            startEnd[i+1][0] = startEnd[i][0];
            startEnd[i+1][1] = max(startEnd[i][1], startEnd[i+1][1]);
        } else {
            ans.push_back(startEnd[i][1]-startEnd[i][0]+1);
        }
    } ans.push_back(startEnd[25][1] - startEnd[25][0] + 1);
    return ans;
}

// ***Only need last occur of each char, go over string, last occur gives range, keep going till i==range and then push, do till end [O(n) time | O(1) space]***:
vector<int> partitionLabels(string s) {
    vector<int> ans, last(26);
    for (int i=0; i<s.size(); ++i) last[s[i]-'a']=i;
    int currRange = 0, currSize=0;
    for (int i=0; i<s.size(); ++i) {
        currSize++;
        currRange = max(currRange, last[s[i]-'a']);
        if (i==currRange) {ans.push_back(currSize); currSize=0;}
    } 
    return ans;
}
