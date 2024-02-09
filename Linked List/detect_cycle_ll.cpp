// ***Problem Desc***: detect if LL has a cycle

// ***Brute[O(n) time | O(n) space]***: make arr from LL and check

// ***fast and slow[O(n) time | O(1) space]***: **START BOTH FROM HEAD**
bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return 1;
    }
    return 0;
}
