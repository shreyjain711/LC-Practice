// ***Problem Desc***: design functions for follow, unfollow and generate news feed
// ***Sol [O(logn) time for follow, unfollow, O(n.p.logFeedSize) time for news feed generation | O(feedSize) space]***:
int tweetNum;
unordered_map<int, unordered_set<int>> followList;
unordered_map<int, vector<vector<int>>> postList;
Twitter() {
    tweetNum = 0;
}

void postTweet(int userId, int tweetId) {
    if (followList.find(userId) == followList.end())
        followList[userId].insert(userId);
    postList[userId].push_back({tweetNum++, tweetId});
}

vector<int> getNewsFeed(int userId) {
    vector<int> newsFeed;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (auto followed: followList[userId]) {
        for (auto postDetails : postList[followed]) {
            pq.push(postDetails);
            if (pq.size() > 10) pq.pop();
        }
    }
    while (!pq.empty()) {newsFeed.push_back(pq.top()[1]); pq.pop();}
    reverse(newsFeed.begin(), newsFeed.end());
    return newsFeed;
}

void follow(int followerId, int followeeId) {
    if (followList.find(followerId) == followList.end())
        followList[followerId].insert(followerId);
    followList[followerId].insert(followeeId);
}

void unfollow(int followerId, int followeeId) {
    followList[followerId].erase(followeeId);
}
