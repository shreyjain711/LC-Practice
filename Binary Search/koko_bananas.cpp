// ***Problem Desc***: koko eats k bananas in an hour. has to finish all piles in h hours. time taken for each pile = ceil(pile/speed)
// ***Brute [O(p.max(p)) time | O(1) space]***: try each speed from 1...max(p)
// ***Binary search for the right speed[O(p.log(max(p))) time | O(1) space]***:
int minEatingSpeed(vector<int>& piles, int h) {
      int lo = 1, hi = 1e9, mid, ans = 1e9;
      long long t;
      while (lo <= hi) {
          mid = lo + (hi-lo)/2; t = 0;
          for (int p: piles) t += ceil(p/(double)mid);
          if (t <= h) {
              ans = min(ans, mid);
              hi = mid - 1;
          } else lo = mid + 1;
      }
      return ans;
  }
