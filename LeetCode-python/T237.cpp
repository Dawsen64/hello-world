/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *ptr1 = node->next, *ptr2;
        while (node->next != nullptr)
            {
                node->val = ptr1->val;
                ptr2 = node;
                node = node->next;
                ptr1 = node->next;
            }
        ptr2->next = nullptr;
    }
};
