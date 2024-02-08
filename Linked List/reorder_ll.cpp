// ***Problem Desc***: rearrage list, first points to first from right which then points to second pair and so on

// ***slow fast to get to mid, split, reverse second half, merge left and right alternately [O() time | O() space]***:
void reorderList(ListNode* head) {
    // find mid
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *rightHead = slow->next, *prev = NULL, *next = NULL;
    slow->next = NULL; // split at mid
    // reverse right half
    while (rightHead) {
        next = rightHead->next;
        rightHead->next = prev;
        prev = rightHead;
        rightHead = next;
    }

    // merge alternatively
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
