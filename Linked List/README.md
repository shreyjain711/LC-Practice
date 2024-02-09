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
- ***Problem Desc***: each digit in LL node, *in right to left order*
- ***Brute[O(n) time | O(n) space]***: solve while adding the nodes, taking carry, storing result in new node
  ```cpp
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0; ListNode *dummy = new ListNode(), *curr = dummy;
        while (l1 || l2 || carry) {
            carry += (l1 ? l1->val:0) + (l2 ? l2->val:0);
            curr->next = new ListNode(carry % 10);
            carry /= 10;
            curr = curr->next; 
            if (l1) l1 = l1->next; 
            if (l2) l2 = l2->next;
        }
        return dummy->next;
    }
  ```
- ***no new node[O(n) time | O(1) space]***: in the while loop, have separate if else for l1 l2 both exist, and only one of them exists

### ***[Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)***: 
- ***Problem Desc***: detect if LL has a cycle
- ***Brute[O(n) time | O(n) space]***: make arr from LL and check
- ***fast and slow[O(n) time | O(1) space]***: **START BOTH FROM HEAD**
    ```cpp
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return 1;
        }
        return 0;
    }
    ```

### ***[Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)***: arr of n+1 elms and only 1 num repeats. **BUT, it can repeat more than twice**. 
- ***Problem Desc***: arr of n+1 elms and only 1 num repeats. **BUT, it can repeat more than twice**. Time linear, space constant
- ***Brute[O(n) time | O(n) space]***: hashmap to save count
- ***slow, fast[O() time | O() space]***: Arr is LL, each val defines what index it points to. LL cycle problem
    - initiate s, f taking the first step from 0 i.e. s = arr[0], f = arr[arr[0]]
    - after first match, take one jump for s from 0 and for f from where it is.. next match will be at duplicate
    ```cpp
    int findDuplicate(vector<int>& nums) {
        int i = nums[0], j = nums[nums[0]];
        while (i != j) {
            i = nums[i];
            j = nums[nums[j]];
        } i = 0;
        while (i != j) {
            i = nums[i];
            j = nums[j];
        }
        return i;
    }
    ```

### ***[LRU Cache](https://leetcode.com/problems/lru-cache/)***: get and put in O1 time (On space) **[REDO]**
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```   

### ***[Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)***:
- ***Problem Desc***: given k LLs, merge them in order
- ***Brute[O(l.n<sup>2</sup>) time | O(1) space]***: go through all list heads, find top and merge. 
- ***min heap[O(n.logl) time | O(1) space]***: add first elem of all LL to min heap, keep popping and pushing the next elem of the popped pointer
    ```cpp
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(), *dummy = head;
        auto comparator = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> q(comparator);
        for (auto node : lists) {
            if (!node) continue;
            q.push(node);
            node = node->next;
        }

        while (!q.empty()) {
            ListNode* node = q.top(); q.pop();
            if (node->next) q.push(node->next);
            dummy->next = node; dummy = dummy->next;
        }
        return head->next;
    }
    ```    
- ***Keep on merging lists in pairs. [O(nlogl) time | O(1) space]***

### ***[Reverse Nodes in K-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)***: reverse in groups of size k. do not reverse last group if incomplete
- ***Problem Desc***:
- ***Brute[O() time | O() space]***:
- ***[O() time | O() space]***:
    ```cpp
    ```
