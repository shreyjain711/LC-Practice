// ***Problem Desc***: given tasks (identified by uppercase chars), they have to be exec. Can be exec but between each same task, gap of n needed. How much time need to run total

/*
***max heap and priority queue [O(n*tasks) time | O(1) space]***:
  - we need to prioritise the task with max count since that will define the empty intervals
    - make maxQ with only counts of each task (task id doesn't matter)
    - it'll tell which task to run at any time
  - then we need a Q to know when a task is again eligible
    - relying only on pq would lead to diff tasks running fist and then the max occus task adds up the idle time
    - when task run, if it needs to be run again then store its count and the curr ts in Q
    - at each ts check if q has an item in front that can be run again, take it out of Q and re-enter into maxQ
  - now run till task left in maxQ (to be run) or Q (waiting) states
*/
int leastInterval(vector<char>& tasks, int n) {
    vector<int> counts(26);
    priority_queue<int> mxq; queue<vector<int>> q;
    for (char t: tasks) counts[t-'A']++;
    for (auto c: counts) if (c) mxq.push(c);

    int ts = 0;
    while (!q.empty() || !mxq.empty()) {
        ts++;
        if (!mxq.empty()) {
            if (mxq.top() > 1) 
                q.push({mxq.top()-1, ts+n});
            mxq.pop();
        }
        if (!q.empty() && q.front()[1] == ts) {
            mxq.push(q.front()[0]);
            q.pop();
        }
    }
    return ts;
}

/*
***greedy, maths [O(n) time | O(1) space]:
  - maxOccur task will define the n+1 spaced intervals needed (provided n is big enough)
  - so (maxOccur-1)*(n+1) spaces will definitely exist
  - now count for each elem that occurs == maxOccur, the last extra window will get added
    - won't be of length n+1 so we increment ans by 1 for each such elem
  - if n not big enough then tasks size is going to matter
*/
int leastInterval(vector<char>& tasks, int n) {
    vector<int> counts(26); int ans = 0, maxOccur = 0;
    for (char t: tasks) maxOccur = max(maxOccur, ++counts[t-'A']);
    
    ans = (maxOccur - 1) * (n + 1);
    for (int c: counts) if (c == maxOccur) ans++;
    
    return max(ans, (int)tasks.size());
}
