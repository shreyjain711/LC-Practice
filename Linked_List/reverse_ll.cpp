// ***Problem Desc***: reverse an LL

// ***Brute [O(n<sup>2</sup>) time | O(1) space]***: go to end, reverse, repeat

// ***store next, reverse, move reversed, move to next, repeat [O(n) time | O(1) space]***: 
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
