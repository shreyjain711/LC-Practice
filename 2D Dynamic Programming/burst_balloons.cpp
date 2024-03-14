// ***Problem Desc***: given a range of balloons with certain vals; burst all of them to gain max points if val gained at each step = val[prev] + val[balloon] + val[curr]

// ***Brute [O(n!) time | O(n) space]***: Backtracking burst each, remove that one from arr and then continue till all done

/*
***instead of calculating max from left and right sub arr of elem, let dp[i][j] = max if balloons from i+1 to j-1 were burst optimally [O(n<sup>3</sup>) time | O(n<sup>2</sup>) space]***:
  - we first insert 1 val balloons at the front and end and then create the new n sized 2D arr
  - we form ranges of increasing len start with len 2
  - in each range i start from 0 and j = i+len, j is increased till its less than n (new n)
  - dp[i][j] = popping all balloons in range except the ones at boundary = max(dp[i][a] + nums[i]*nums[a]*nums[j] + dp[a][j]) for a in i+1..j-1
  - So, initial brackets will be [0,2], [1,3]...[n-3,n-1]
      - this calculates the max of bursting a single balloon that was initially on ((i+j)/2)-1 index
      - so in [0,2] we only burst the one currently at index (0+2)/2 = 1; it was originally at index 1-1 = 0
*/
int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(),1); nums.push_back(1);
    int n=nums.size(), dp[n][n]; memset(dp, 0, sizeof dp);
    for (int l=2; l<n; ++l) 
        for (int i=0, j=i+l; j<n; ++i, ++j) 
            for (int a=i+1; a<j; ++a) 
                dp[i][j] = max(dp[i][j], dp[i][a] + nums[i]*nums[a]*nums[j] + dp[a][j]);
    return dp[0][n-1];
}
