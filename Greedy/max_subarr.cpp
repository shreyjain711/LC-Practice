// ***Problem Desc***: given an arr with [-R, R] nums, find the max sum possible for any subarr

// ***Brute [O(n<sup>2</sup>) time | O(1) space]***: for each sub arr find the sum

// ***Keep summing from left, reset sum to 0 if it ever goes -ve; keep noting the max of this sum [O(n) time | O(1) space]***:
int maxSubArray(vector<int>& nums) {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int sum=0, maxSum=INT_MIN;
    for (int n:nums) {
        sum += n; maxSum = max(maxSum, sum);
        if(sum<0) sum=0;
    } return maxSum;
}

// ***Divide and conquer, find the pre and suf sums for each elem, reset to 0 if -ve; for each val find max sum [O(n) time | O(n) space]***:
int maxSubArray(vector<int>& nums) {
    int n=nums.size(), sum=0; vector<int> pre(n), suf(n);
    for(int i=1; i<n; ++i) {sum = max(0, sum+nums[i-1]); pre[i] = sum;} cout<<endl;
    sum=0; for(int i=n-2; i>=0; --i) {sum = max(0, sum+nums[i+1]); suf[i] = sum;} 
    sum=INT_MIN; for(int i=0; i<n; ++i) {sum = max(sum, nums[i]+pre[i]+suf[i]);}
    return sum;
}
