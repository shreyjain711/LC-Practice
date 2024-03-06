# Problem Set

### [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/):
- ***Problem Desc***: given an arr with [-R, R] nums, find the max sum possible for any subarr
- ***Brute [O(n<sup>2</sup>) time | O(1) space]***: for each sub arr find the sum
- ***Keep summing from left, reset sum to 0 if it ever goes -ve; keep noting the max of this sum [O(n) time | O(1) space]***:
  ```cpp
  int maxSubArray(vector<int>& nums) {
      ios_base::sync_with_stdio(false);cin.tie(0);
      int sum=0, maxSum=INT_MIN;
      for (int n:nums) {
          sum += n; maxSum = max(maxSum, sum);
          if(sum<0) sum=0;
      } return maxSum;
  }
  ```
- ***Divide and conquer, find the pre and suf sums for each elem, reset to 0 if -ve; for each val find max sum [O(n) time | O(n) space]***:
  ```cpp
  int maxSubArray(vector<int>& nums) {
      int n=nums.size(), sum=0; vector<int> pre(n), suf(n);
      for(int i=1; i<n; ++i) {sum = max(0, sum+nums[i-1]); pre[i] = sum;} cout<<endl;
      sum=0; for(int i=n-2; i>=0; --i) {sum = max(0, sum+nums[i+1]); suf[i] = sum;} 
      sum=INT_MIN; for(int i=0; i<n; ++i) {sum = max(sum, nums[i]+pre[i]+suf[i]);}
      return sum;
  }
  ```

### [Jump Game](https://leetcode.com/problems/jump-game/):
- ***Problem Desc***: given arr where each elem = num steps that one can jump further from that index; can we reach index n-1 if starting from 0
- ***keep track of range, at each elem new range i+arr[i]; if it reaches n-1 then can reach else not [O(n) time | O(1) space]***:
  ```cpp
  bool canJump(vector<int>& nums) {
      int range = nums[0];
      for (int i=0; i<=range;++i) {
          range = max(range, i+nums[i]);
          if (range+1 >= nums.size()) return 1;
      }
      return 0;
  }
  ```

### [Jump Game II](https://leetcode.com/problems/jump-game-ii/):
- ***Problem Desc***: count min jumps needed for reaching the end
- ***in the range, iterate to find the next range, jumps++, then continue in the arr till new range and keep repeating [O(n) time | O(1) space]***:
  ```cpp
  int jump(vector<int>& nums) {
      if (nums.size()==1) return 0;
      int jumps=1, range=nums[0], pos=0; 
      while (range < nums.size()-1) {
          jumps++; int newRange = range;
          while (pos<=range) {
              newRange = max(newRange, pos+nums[pos++]);
          } range = newRange;
      } return jumps;
  }
  ```

### [Gas Station](https://leetcode.com/problems/gas-station/):
- ***Problem Desc***: for each i, gas available there and cost from there to next station is given; where can one start to complete a loop
- ***Brute [O(n<sup>2</sup>) time | O(1) space]***: start from each position and try going in a loop
- ***Keep adding up the gas deficit from 0, if it hits -ve, can start from it next so loop from there again, at end eval if gas>=fuel, start stored [O(n) time | O(1) space]***:
  ```cpp
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int overall=0, start=0, currDiff=0;
      for (int i=0; i<cost.size(); ++i) {
          overall += gas[i]-cost[i];
          currDiff += gas[i]-cost[i];
          if (currDiff < 0) {
              currDiff=0;
              start = i+1;
          }
      }
      
      return overall>=0 ? start : -1;
  }
  ```

### [Hand of Straights](https://leetcode.com/problems/hand-of-straights/):
- ***Problem Desc***: given cards, make hands/batch of given group size using cards with consecutive nums
- ***Brute [O(n<sup>grpSize</sup>) time | O(1) space]***: go over the arr, find the smallest elem and keep making hands
- ***Sorted map and go over making hands and return 0 if impossible to make triplets; after making delete elems from map as well [O(n.logn) time | O(n) space]***:
  ```cpp
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
  ```

### [Merge Triplets to Form Target Triplet](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/):
- ***Problem Desc***: given list of triplets and a target triplet; can we do merge ops (where resultant has max of each elem from two) to get to target
- ***Brute [O(2<sup>n</sup>) time | O(n) space]***: backtracking to evaluate merging/not merging each element
- ***For all triplets with each elem <= target's, find if these can collectively give each of target values [O(n) time | O(1) space]***:
  ```cpp
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
      bool can1=0, can2=0, can3=0; 
      for (auto &tr: triplets) {
          if (tr[0]>target[0] || tr[1]>target[1] || tr[2]>target[2]) continue;
          if (tr[0]==target[0]) can1=1;
          if (tr[1]==target[1]) can2=1;
          if (tr[2]==target[2]) can3=1;
      } return can1 && can2 && can3;
  }
  ```

### [Partition Labels](https://leetcode.com/problems/partition-labels/):
- ***Problem Desc***: make as many partitions as possible such that each letter is at most in one partition only
- ***make intervals of start and end occur of each char, sort & merge overlapping intervals and for each the size append to ans [O(n) time | O(1) space]***:
  ```cpp
  vector<int> partitionLabels(string s) {
      vector<int> ans;
      vector<vector<int>> startEnd(26, vector<int>(2,-1));
      for (int i=0; i<s.size(); ++i) {
          int ind = s[i]-'a';
          if (startEnd[ind][0]==-1) startEnd[ind][0] = i;
          startEnd[ind][1]=i;
      }
      sort(begin(startEnd), end(startEnd));
      for (int i=0; i<25; ++i) {
          if (startEnd[i][0]==-1) {continue;}
          if (startEnd[i][1] > startEnd[i+1][0]) {
              startEnd[i+1][0] = startEnd[i][0];
              startEnd[i+1][1] = max(startEnd[i][1], startEnd[i+1][1]);
          } else {
              ans.push_back(startEnd[i][1]-startEnd[i][0]+1);
          }
      } ans.push_back(startEnd[25][1] - startEnd[25][0] + 1);
      return ans;
  }
  ```
- ***Only need last occur of each char, go over string, last occur gives range, keep going till i==range and then push, do till end [O(n) time | O(1) space]***:
  ```cpp
  vector<int> partitionLabels(string s) {
      vector<int> ans, last(26);
      for (int i=0; i<s.size(); ++i) last[s[i]-'a']=i;
      int currRange = 0, currSize=0;
      for (int i=0; i<s.size(); ++i) {
          currSize++;
          currRange = max(currRange, last[s[i]-'a']);
          if (i==currRange) {ans.push_back(currSize); currSize=0;}
      } 
      return ans;
  }
  ```

### [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/):
- ***Problem Desc***:
- ***Brute [O() time | O() space]***:
- ***Sol [O() time | O() space]***:
  ```cpp
  ```
