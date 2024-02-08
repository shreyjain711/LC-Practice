# Problem Set

### ***[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)***: reverse LL
- ***Problem Desc***: reverse an LL
- ***Brute [O(n<sup>2</sup>) time | O(1) space]***: go to end, reverse, repeat
- ***reverse, move to next, repeat [O(n) time | O(1) space]***: 
    ```cpp
    
    ```

### ***[Merge Two Linked Lists](https://leetcode.com/problems/merge-two-sorted-lists/)***: merge two LL in sorted order
- ***Problem Desc***: merge together two sorted LL
- ***[O(n) time | O(1) space]***: make dummy ptr, maintain a tail/curr ptr. append to curr the pts from lists 1 and 2 the one that's the smaller
    ```cpp
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(), *curr = dummy;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                curr->next = list2;
                curr = curr->next;
                list2 = list2->next;
            } else {
                curr->next = list1;
                curr = curr->next;
                list1 = list1->next;
            }
        }
        if (list1) curr->next = list1;
        if (list2) curr->next = list2;
        return dummy->next;
    }
    ```

### ***[Reorder List](https://leetcode.com/problems/reorder-list/)***: E0, E1, … En-1, En → E0, En, E1, En-1 …
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```

### ***[Remove Nth Node from End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)***: remove nth node from end
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```

### ***[Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)***: clone LL with a random pointer
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```

### ***[Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)***: given two nums in LL
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```

### ***[Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)***: detect cycle
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```

### ***[Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)***: arr of n+1 elms and only 1 num repeats. **BUT, it can repeat more than twice**. Time linear, space constant
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```

### ***[LRU Cache](https://leetcode.com/problems/lru-cache/)***: get and put in O1 time (On space) **[REDO]**
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```   

### ***[Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)***:
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```
    
- sol#3 - keep on merging lists in pairs. Onlogk time, O1 space.

### ***[Reverse Nodes in K-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)***: reverse in groups of size k. do not reverse last group if incomplete
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```