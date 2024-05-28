// ***Problem Desc***: num of ways to reach nth steo if can take 1 or 2 len steps at once

// ***init array with 0, 1 elem = 1, then each elem = sum of prev two [O(n) time | O(n) space]***:
int climbStairs(int n) {
    vector<int> ways(n+1);
    ways[0] = ways[1] = 1;
    for (int i=2; i<=n; i++) ways[i] = ways[i-1] + ways[i-2];
    return ways[n];
}

// ***need only prev two vals, use int for them instead of arr [O(n) time | O(1) space]***:
int climbStairs(int n) {
    int wayP=1, wayPP=1, ans=1;
    for (int i=2; i<=n; i++) {
        ans = wayP + wayPP;
        wayPP = wayP;
        wayP = ans;
    }
    return ans;
}
