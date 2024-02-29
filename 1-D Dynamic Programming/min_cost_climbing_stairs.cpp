// ***Problem Desc***: climbing each step has a cost, can go to next or the next to next from any stair, can start from 0/1; what min cost to climb the n stairs

// ***to reach nth stair (goal to reach n+1, so arr of sz n+1) cost = min of cost of climbing from st n-1 or st n-2 [O(n) time | O(n) space]***:
int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size(); vector<int> minC(n+1);
    for (int i=2; i<=n; ++i)
        minC[i] = min(minC[i-1] + cost[i-1], minC[i-2] + cost[i-2]);
    return minC[n];
}

// ***Since need only prev two vals for the curr step, store only those [O(n) time | O(1) space]***:
int minCostClimbingStairs(vector<int>& cost) {
    int n=cost.size(), prev1 = 0, prev2 = 0, ans = 0;
    for (int i=2; i<=n; ++i) {
        ans = min (prev1 + cost[i-1], prev2 + cost[i-2]);
        prev2 = prev1;
        prev1 = ans;
    }
    return ans;
}
