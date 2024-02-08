// ***Problem Desc***: remove nth node from end

// ***Brute[O(n) time | O(1) space]***: go to end, count nodes, go to node to be del

// ***go n forward, if any left, keep progressing both, replace next of back at end[O(n) time | O(1) space]***:
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
