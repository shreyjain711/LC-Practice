# Problem Set

### ***[Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)***: reverse LL
- ***Problem Desc***: reverse an LL
- ***Brute [O(n<sup>2</sup>) time | O(1) space]***: go to end, reverse, repeat
- ***stack [O(n) time | O(n) space]***: push all in stack, popping gives reversed order
- ***store next, reverse, move reversed, move to next, repeat [O(n) time | O(1) space]***: 
    ```cpp
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *next = NULL;
        while (head != NULL) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
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
- ***Problem Desc***: rearrage list, first points to first from right which then points to second pair and so on
- ***slow fast to get to mid, split, reverse second half, merge left and right alternately [O(n) time | O(1) space]***:
    ```cpp
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rightHead = slow->next, *prev = NULL, *next = NULL;
        slow->next = NULL;
        while (rightHead) {
            next = rightHead->next;
            rightHead->next = prev;
            prev = rightHead;
            rightHead = next;
        }

        ListNode *l1 = head, *l2 = prev;
        while (l1 && l2) {
            next = l1->next;
            l1->next = l2;
            l1 = next;
            next = l2->next;
            l2->next = l1;
            l2 = next;
        }
    }
    ```

### ***[Remove Nth Node from End of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)***: 
- ***Problem Desc***: remove nth node from end
- ***Brute[O(n) time | O(1) space]***: go to end, count nodes, go to node to be del
- ***go n forward, if any left, keep progressing both, replace next of back at end[O(n) time | O(1) space]***:
    ```cpp
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next) return NULL;

        ListNode *back = head, *front = head;
        while (n--) front = front->next;
        if (!front) return head->next;
        
        while (front->next) {
            back = back->next;
            front = front->next;
        }
        back->next = back->next->next;
        return head;
    }
    ```

### ***[Copy List with Random Pointer](https://leetcode.com/problems/copy-list-with-random-pointer/)***: 
- ***Problem Desc***: clone LL with a random pointer
- ***hashmap to store corresponding pointers[O(n) time | O(n) space]***
- ***Insert copy after each node linearly, set random ptrs, disentangle LLs[O(n) time | O(1) space]***:
    ```cpp
    Node* copyRandomList(Node* head) {
        // insert new node after each, linearly
        Node *curr = head, *next;
        while (curr) {
            next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }

        // set random pointers
        curr = head;
        while (curr) {
            next = curr->next->next;
            curr->next->random = (curr->random) ? curr->random->next : NULL;
            curr = next;
        }

        // remove from main LL
        curr = head; Node *dummyHead = new Node(0), *dummy = dummyHead;
        while (curr) {
            dummy->next = curr->next;
            next = curr->next->next;
            dummy = dummy->next;
            curr->next = next;
            curr = curr->next;
        }
        return dummyHead->next;
    }
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
