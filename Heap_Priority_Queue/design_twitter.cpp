// ***Problem Desc***: design functions for follow, unfollow and generate news feed
// ***set for followers, vector for tweets, get into a maxHeap for top 10, add self to follower every time [O(logn) time for post, follow, unfollow, O(nlogn) time for getFeed | O(n + t) space]***:
  
unordered_map<int, unordered_set<int>> following;
unordered_map<int, vector<int>> tweets;
Twitter() {}

void postTweet(int userId, int tweetId) {
  following[userId].insert(userId);
  tweets[userId].push_back(tweetId);
}

vector<int> getNewsFeed(int userId) {
  vector<int> top10; priority_queue<int> orderTweets;
  if (following.count(userId)) {
      for (auto f: following[userId])
          if (tweets.count(f))
              for (int i=0; i<min(10, (int)tweets[f].size()); i++)
                  orderTweets.push(tweets[f][i]);
      while (!orderTweets.empty() && top10.size()<10) {
          top10.push_back(orderTweets.top()); orderTweets.pop();
      }
  } return top10;
}

void follow(int followerId, int followeeId) {
  following[followerId].insert(followerId);
  following[followerId].insert(followeeId);
}

void unfollow(int followerId, int followeeId) {
  if (followerId==followeeId) return;
  following[followerId].erase(followeeId);
}
