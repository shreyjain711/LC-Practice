// ***Problem Desc***: given cards, make hands/batch of given group size using cards with consecutive nums

// ***Brute [O(n<sup>grpSize</sup>) time | O(1) space]***: go over the arr, find the smallest elem and keep making hands

// ***Sorted map and go over making hands and return 0 if impossible to make triplets; after making delete elems from map as well [O(n.logn) time | O(n) space]***:
bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize) return 0;
    map<int,int> count; 
    for(int i: hand) count[i]++;
    for(auto p: count) {
        int start=p.first, neededCount = p.second;
        for(int x=1; x<groupSize; ++x) {
            int next = start+x;
            if (!count.count(next) || count[next] < neededCount) return 0;
            else count[next] -= neededCount;
            if (!count[next]) count.erase(next);
        } count.erase(start);
    } return 1;
}
