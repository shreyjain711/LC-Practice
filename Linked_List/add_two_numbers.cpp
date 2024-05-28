// ***Problem Desc***: each digit in LL node, *in right to left order*
// ***Brute[O(n) time | O(n) space]***: solve while adding the nodes, taking carry, storing result in new node
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

// ***no new node[O(n) time | O(1) space]***: in the while loop, have separate if else for l1 l2 both exist, and only one of them exists
