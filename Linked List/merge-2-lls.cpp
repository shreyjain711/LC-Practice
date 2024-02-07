/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// ***Problem Desc***: merge together two sorted LL
// ***[O(n) time | O(1) space]***: make dummy ptr, maintain a tail/curr ptr. append to curr the pts from lists 1 and 2 the one that's the smaller

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
