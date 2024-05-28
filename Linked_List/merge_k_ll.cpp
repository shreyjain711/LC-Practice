// ***Problem Desc***: given k LLs, merge them in order
// ***Brute[O(l.n<sup>2</sup>) time | O(1) space]***: go through all list heads, find top and merge. 
// ***min heap[O(n.logl) time | O(1) space]***: add first elem of all LL to min heap, keep popping and pushing the next elem of the popped pointer
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

// ***Keep on merging lists in pairs. [O(nlogl) time | O(1) space]***
