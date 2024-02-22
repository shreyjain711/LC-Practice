// ***Problem Desc***: given arr of stones with specific weight, play game till left with 1/0 stones -> collide the heaviest stones, if one greater then their diff survives else both don't
// ***Brute [O(n<sup>2</sup>) time | O(n) space]***: find the top two, insert if needed and repeat till 1/0 left
// ***Sol [O(n.logn) time | O(n) space]***:
int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxQ(stones.begin(), stones.end());
    while (maxQ.size()>1) {
        int y = maxQ.top(); maxQ.pop();
        int x = maxQ.top(); maxQ.pop();
        if (y>x) maxQ.push(y-x);
    }
    return maxQ.size() ? maxQ.top() : 0;
}
