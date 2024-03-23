# LC-Practice

### Problems For Revision

1. Arrays and Hashing
   - [Top K Frequent Elems](https://github.com/shreyjain711/LC-Practice/blob/main/Arrays%20and%20Hashing/top_k_freq.cpp)
     - learn about heap and custom comparator
   - [Longest Consecutive Sequence (if arr sorted)](https://github.com/shreyjain711/LC-Practice/blob/main/Arrays%20and%20Hashing/longest_consec_seq_if_sorted.cpp)
     - hashmap, iterate and eval sequences from elems that don't have an elem-1 in arr
2. Two Pointers
   - [3Sum](https://github.com/shreyjain711/LC-Practice/blob/main/Two%20Pointers/3sum.cpp)
      - sort, pick first, other two with two ptr approach
   - [Trapping rain water](https://github.com/shreyjain711/LC-Practice/blob/main/Two%20Pointers/trapping_rain_water.cpp)
      - don't need to calc maxLeft and right for all, go with two ptr approach
3. Linked Lists
   - Notes:
      - for cycle start slow and fast pointers taking 1 step (starting from node 0)
      - for finding cycle point, start slow from 0 and fast from where first collision happened; move only one step at a time
   - [LRU Cache](https://leetcode.com/problems/lru-cache/):
      - doubleLL with node also storing key, val
      - a map of key->doubleLL
      - also maintain *head, *tail, size and capacity
   - [Reverse Nodes In K Group](https://leetcode.com/problems/reverse-nodes-in-k-group/):
      - iterative: check k nodes exist, reverse, repeat on next; store the prevTail (tail of LL till now) and currHead
      - recursive: check k or more nodes exist, reverse, pass last recursively to next function
4. Stacks
   - [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/):
      - recursively call a helper, acc to num of open brackets, make further calls
         - if numOpen == numClose
            - if == n: insert in ans arr
            - else (i.e. <n): insert a '(' and add to temp
         - else (can be only numOpen > numClose)
            - if numOpen < n: insert a '(' and add to temp
            - insert a ')' and add to temp
      - iterative: use stacks, iterate on each n, like its BFS
   - [Largest Rectangle In Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/):
      - find indexes where the element's left and right smaller heights exist, dis b/w these * the height of the bar across the arr gives max
      - approach 2:
         - stack stores (height, index) pairs -> the pair indicates a rectangle of height h can be formed from index i
         - pop from stack when the top has a higher height, push in the curr height and the index would be that of the last rectangle evicted from the stack or that of the elem itself
         - trick: to avoid special while loop at end, add a 0 element to heights
5. Binary Search
   - [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/):
      - keep checking mid for min and keep going towards the side that's broken
         - could be lo > mid (if left side has break)
         - OR mid > high (if right side has break)
   - [Search In Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/):
      - check if mid is target
      - check if left side is correctly sorted (lo < mid)
         - if target in range lo to mid, move to that
         - else move to mid+1..high range
      - else (right side is sorted)
         - if target in mid...high, move to it, else move to left half
   - [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/):
      - make sure arr1 is not longer than arr2, median element numbering goes wrong otherwise
      - find mid of arr1, then corresponding ```mid for arr2 = (l1+l2+1)/2 - m1```
      - set points m1-1, m1 on arr1 and m2-1,m2 on arr2
         - check if each point even exists otherwise their val = INT_MAX/MIN
      - check if !(arr1[m1-1] >= arr2[m2]) and if !(arr2[m2-1] <= arr1[m1]) i.e. elements from 0..m1-1 and 0..m2-1 will **NOT** merge together
      - if they will merge then
         - if ```l1+l2 = odd``` median is max of the left halves (m1-1 or m2-1) else
         - else ```avg of max(m1-1, m2-1) and min(m1,m2)```
6. Sliding Window
   - [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/):
      - grow window till condition met, move along if not met, grow when met again
      - optimisations/tricks:
         - no need to find elem with maxCount, the elem being inserted in window is the only contender
         - move window when conditions not met, i.e. no need to shrink with a while loop, just remove one char from front since once added to back
   - [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/):
      - track nums of charCounts that curr window has and shrink or grow as per haves vs needs
      - optimisations/tricks:
         - hashmap to track elems in t str
         - counter for haves (needs met) and needed chars (with respective count)
         - track haves and needs,
            - if ```haves == needs```, remove first letter of window, check if that violated a have met, then haves--
            - else, add one more letter to window, check if adding makes a have met, then have++
         - if after window setting, ```haves == needs``` and curr len < curr min len, set start and len values
   - [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/):
      - maintain a deque, front maintains the max elem in curr window, back maintains the decreasing order
      - firstly, pop from back till the back is < curr elem
      - then push index
      - then if front has an elem from previous iter that's no longer in the window then remove it
      - then front has the ans value for current window
7. Trees
   - [Construct Binary Tree From Preorder And Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/):
      - go one by one on the preorder array to find the node to be made
      - split the inorder at the index where current node val found
   - [Serialize And Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/):
     - use of [o|i]stringstream -> put in strings in an order and get them out in the same one as well.. essentially like an array of strings
     - preorder push into an ostringstream and then get its str for serialization
     - put the string into istringstream for splitting by space, make the nodes in a preorder manner too (works as no recur call made if null denoting char detected in string)
8. Backtracking
   - [Permutations](https://leetcode.com/problems/permutations/):
      - while backtracking, swap the elements on the curr index i in the recursive call and the jth pointer
         - jth pointer goes from i to end of list
      - swap, then recur call, then swap back
   - [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/):
      - sort the array and avoid recursive calling on elements if they're the same as the previous
   - [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/):
      - take brute approach, start taking substr of increasing length from the starting and if it is a palindrome (validate every time), call recursively on the remaining string
   - remember to not ignore the brute approach in such questions
9. Heaps Priority Queue
   - [Kth Largest Element In An Array](https://leetcode.com/problems/kth-largest-element-in-an-array/):
      - sort and pick
      - make it into a max heap, pop k-1 times, top is ans
      - min heap of size k, top is the ans, push all elem one by one while maintaining size
      - quick select algorithm (average case O(n), otherwise O(n<sup>2</sup>) time so not the accepted solution):
         - like quick sort
         - pick a pivot -> can do randomly or the last elem
         - sort the array as in quick sort, i.e. starting from the beginning, store the elements that are less than the pivot in front
         - store the position of the pivot in an int and
            - if that pos is > n-k then ans must be in this left half
            - if < n-k then in right half
            - else the pivot is the ans
   - [Task Scheduler](https://leetcode.com/problems/task-scheduler/):
      - algorithmic approach:
         - ignore the diff elem type, treat them just as per their count
         - must get done with the largest count first (since that defines how many n+1 sized buckets will be formed) so a max PQ of the counts needed
         - since we can't run the same task for n slots so we also keep a queue where we keep checking in every iteration if its front can be again processed; if yes then it is again sent into the max PQ
      - maths:
         - since maxFreq of a task will be the one creating buckets of n+1 size so ans will be ```max ((maxFreq-1)*(n+1) + (number of tasks with freq = maxFreq)   ,   total count of tasks)``` 
         - maxFreq-1 as that many full buckets will be formed and the subsequent bucket size will be the number of tasks with freq = max freq
         - if n isn't too high then tasks.size() will dictate the total time needed so we check for its max
   - [Find Median From Data Stream](https://leetcode.com/problems/find-median-from-data-stream/):
      - keep a maxPQ (left half) and minPQ (right half), check which side the elem belongs based on the maxPQ's top (if less than equal it then to left half else right half)
      - rebalance post pushing, keep maxPQ shouldb't be < minPQ and maxPQ shouldn't be > minPQ+1
      - return median as avg of both PQs' top or the maxPQ top
10. Graphs
    - Topological sort, count indegree, push 0s in Q, iterate, change inDegree and if inDegree goes 0 then add to Q
    - [Redundant Connection](https://leetcode.com/problems/redundant-connection/):
       - use dsu, all parents set to self or to 0 (non existent elem)
       - keep doing union while going over each edge, union -> if parent[x] != x then p[x] = findP(x); return p[x] and the smaller parent can be used as the root for both elems
    - [Word Ladder](https://leetcode.com/problems/word-ladder/):
       - it can be done n<sup>2</sup>.m or n.m<sup>2</sup>
          - n<sup>2</sup> when we try each word to make next level of the BFS
          - m<sup>2</sup> if we try to make all possible words from the curr word and check if its in word set to add to Q
          - select based on n and m values
11. 1D Dynamic Programming
    - [House Robber II](https://leetcode.com/problems/house-robber-ii/):
       - do a max find from 0..n-2 and 1..n-1 -> they find the max val considering last house not robbed and first house not robbed
    - [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/):
       - can do a grid search but rather expand for each elem from center -> practically, this should be fewer steps than n<sup>2</sup> like in grid search
    - [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/):
       - iter over elems, store possible min & max products till then and ans becomes the max found in these iters
       - OR continuous max prod from left and then from right - setting prod to 1 if 0 is seen - then max from one of these iters is the ans
    - [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/):
      - keep a 1D dp arr to store the LIS at each elem and while iterating compare with all prev elem to find biggest LIS val at curr elem
       - OR maintain an arr with LIS elems, if a bigger elem seen then append else replace it with the lower_bound (i.e. elem in arr >= the curr elem) -> given n.logn complexity
    - [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/):
       - memoisation, dp[i][j] -> that a sum j can be formed with elems i..n-1
       - make hashset with all possible vals that can be formed -> on each elem, add to set the curr elems and the one formed by adding to them the curr elem from arr
          - can do this using a bitset -> becomes an O(1) operation with it
12. Intervals
    - [Insert Interval](https://leetcode.com/problems/insert-interval/):
    - [Non Overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/):
    - [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/):
    - [Minimum Interval to Include Each Query](https://leetcode.com/problems/minimum-interval-to-include-each-query/):
14. Greedy
    - [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/):
    - [Jump Game II](https://leetcode.com/problems/jump-game-ii/):
    - [Partition Labels](https://leetcode.com/problems/partition-labels/):
    - [Valid Parenthesis String](https://leetcode.com/problems/valid-parenthesis-string/):
16. 2D Dynamic Programming
    - [Best Time to Buy And Sell Stock With Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/):
    - [Target Sum](https://leetcode.com/problems/target-sum/):
    - [Interleaving String](https://leetcode.com/problems/interleaving-string/):
    - [Longest Increasing Path In a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/):
    - [Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/):
    - [Burst Balloons](https://leetcode.com/problems/burst-balloons/):
    - [Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/):
18. Bit Manipulation
    - [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/):
    - [Reverse Integer](https://leetcode.com/problems/reverse-integer/):
20. Advanced Graphs
    - [Reconstruct Itinerary](https://leetcode.com/problems/reconstruct-itinerary/):
    - [Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/):
    - [Network Delay Time](https://leetcode.com/problems/network-delay-time/):
    - [Swim In Rising Water](https://leetcode.com/problems/swim-in-rising-water/):
    - [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/):
    - [Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/):
22. Math Geometry
    - [Rotate Image](https://leetcode.com/problems/rotate-image/):
    - [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/):
    - [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/):
    - [Happy Number](https://leetcode.com/problems/happy-number/):
    - [Pow(x, n)](https://leetcode.com/problems/powx-n/):
      - multiply once by x if the curr n is odd and then square and n gets /2 and do till n >0
    - [Multiply Strings](https://leetcode.com/problems/multiply-strings/):
      - simple maths, no short way. make a temp str with m+n 0s


### Quick Notes
- Set vs unorderedSet <br>
  <img width="585" alt="image" src="https://github.com/shreyjain711/LC-Practice/assets/31862368/4e3117cf-ec69-422d-b748-9564b943fe99">

    
   - Both set and unordered_set can be traversed but only in case of set that traversal order would be a sorted one
   - Why not unordered better here even after worst case complexity being higher - the hash table approach in unordered set will give O(n) if every insertion ends up creating a collision in hash table during insertion; this will not be the case in almost all practical cases
- multiset -> essentially a sorted array, insert(val) and erase(val) is logn
- unordered_map operations:
    - iteration:
        - `for(auto p: m) p.first p.second`
        - `map<.,.>::iterator it; = m.begin()` `while ≠ m.end()`; access with `it→first, it→second`
        - for_each
            
            ```cpp
            for_each(m.begin(), m.end(),
            	[](std::pair<string, int> k_v)
            		{
            	    // Accessing the key -> k_v.first;
                  // Accessing the value -> k_v.second;
            	});
            
            ```
            
    - find: m.find(value); = m.end() if not found
    - erase: key | iterator
- Vector:
    - push_back for appending at the end,
    - .insert(v.begin(), val) for inserting at any position
    - .resize(n), truncates and gives first n values
    - sort(arr.begin(), arr.end(), [comparator])
- Heaps:
    - binary heap Heapify time = On
    - max: priority_queue<int>
    - min: priority_queue<int, vector<int>, greater<int>>, priority_queue<pi, vector<pi>, greater<pi>>
    - to use custom comparator
        
        ```cpp
        auto comparator =[](pair<int, vector<int>> &a, pair<int, vector<int>> &b) {
            return a.first < b.first;
        };
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, decltype(comparator)> minH(comparator);
        
        ```
        
    - greater<int> as a comparator makes min heap
    - greater<vector<int>> compares vector elements one by one from beginning
- Comparator
    - pass myComp, instead of greater etc
        
        ```cpp
        struct myComp {
            constexpr bool operator()(
                pair<int, int> const& a,
                pair<int, int> const& b)
                const noexcept
            {
                return a.second < b.second;
            }
        };
        ```
        
- String:
    - to lower case: transform(str.begin(), str.end(), str.begin(), ::tolower)
    - to upper case: transform(str.begin(), str.end(), str.begin(), ::toupper)
    - substring: s1.substr(pos, len); (On time)
    - to int: stoi();
    - istringstream i(str) -> splits the string by space char and can get values one by one through -> i >> str
    - ostringstream o -> can keeping appending strings and other literals to stream -> o << str/int/double/etc
    - copying a string takes O(n) time; so copying into a vector of string is O(n) op
- Struct:
    - Constructor, just like classes. Can be polymorphic. example :
        
        ```cpp
        struct Node{
            int key;
            Node * next;
            Node * prev;
            
            Node(): key(0), next(NULL), prev(NULL){}
            Node(int val) : key(val), next(NULL), prev(NULL){}
        };
        ```
        
- deque: implemented as a doubly LL. has push & pop for front and back. erase from a certain position also available
- tips:
    - INT_MIN and INT_MAX for 32bit signed int limits
    - `nullptr` or `NULL` to provide null val in c++
