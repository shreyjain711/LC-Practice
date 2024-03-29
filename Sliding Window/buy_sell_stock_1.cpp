// ***Problem Desc***: given stock prices in an arr, find best day to buy and then to sell
// ***Brute [O(n<sup>2</sup>) time | O(1) space]***: for each elem, try every other elem
// ***keep looking for minimum Price and maximum profit at each step[O(n) time | O(1) space]***:
int maxProfit(vector<int>& prices) {
    int minPrice = prices[0], profit = 0;
    for (auto p: prices) {
        profit = max(profit, p - minPrice);
        minPrice = min(minPrice, p);
    }
    return profit;
}

/*
 * above is a simpler version of the below code
  int maxProfit(vector<int>& prices) {
      int minPrice = INT_MAX, maxPrice = INT_MIN, profit = 0;
      for (auto p: prices) {
          if (p < minPrice) {
              if (maxPrice > minPrice) profit = max(profit, maxPrice-minPrice);
              minPrice = p; maxPrice = INT_MIN;
          } maxPrice = max(maxPrice, p);
          profit = max(profit, maxPrice-minPrice);
      }
      return profit;
  }
*/
