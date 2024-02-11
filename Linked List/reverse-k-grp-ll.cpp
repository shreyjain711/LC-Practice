// ***Problem Desc***: reverse in groups of size k. do not reverse last group if incomplete
// ***iterative, check k nodes exist, reverse, repeat on next[O(n) time | O(1) space]***:
bool hasKNodes(ListNode* head, int k) {
    while (k--) {
        if (!head) return 0;
        head = head->next;
    }
    return 1;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode * dummy = new ListNode(); 
    ListNode *curr = head, *prev, *next, *origHead = NULL, *prevTail = dummy;
    while (curr && hasKNodes(curr, k)) {
        origHead = curr;
        prev = NULL;
        for (int _ = 0; _<k; ++_) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        origHead->next = curr;
        prevTail->next = prev;
        prevTail = origHead;
    }
    
    return dummy->next;
}

// ***recursion [O(n) time | O(1) space]***: check k or more nodes exist, reverse, pass last recursively to next function
