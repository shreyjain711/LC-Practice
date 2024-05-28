// ***Problem Desc***: clone LL with a random pointer

// ***hashmap to store corresponding pointers[O(n) time | O(n) space]***

// ***Insert copy after each node linearly, set random ptrs, disentangle LLs[O(n) time | O(1) space]***:
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

    // disentangle the LLs
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
