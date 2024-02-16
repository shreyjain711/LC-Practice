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


### Quick Notes
- Set vs unorderedSet <br>
  <img width="585" alt="image" src="https://github.com/shreyjain711/LC-Practice/assets/31862368/4e3117cf-ec69-422d-b748-9564b943fe99">

    
   - Both set and unordered_set can be traversed but only in case of set that traversal order would be a sorted one
   - Why not unordered better here even after worst case complexity being higher - the hash table approach in unordered set will give O(n) if every insertion ends up creating a collision in hash table during insertion; this will not be the case in almost all practical cases
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
