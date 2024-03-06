// ***Problem Desc***: given list of triplets and a target triplet; can we do merge ops (where resultant has max of each elem from two) to get to target

// ***Brute [O(2<sup>n</sup>) time | O(n) space]***: backtracking to evaluate merging/not merging each element

// ***For all triplets with each elem <= target's, find if these can collectively give each of target values [O(n) time | O(1) space]***:
bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    bool can1=0, can2=0, can3=0; 
    for (auto &tr: triplets) {
        if (tr[0]>target[0] || tr[1]>target[1] || tr[2]>target[2]) continue;
        if (tr[0]==target[0]) can1=1;
        if (tr[1]==target[1]) can2=1;
        if (tr[2]==target[2]) can3=1;
    } return can1 && can2 && can3;
}
