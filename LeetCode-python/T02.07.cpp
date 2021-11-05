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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *foreheadA = new ListNode(-1, headA);
        ListNode *foreheadB = new ListNode(-1, headB);
        ListNode *ptr1 = foreheadA, *ptr2;
        while (ptr1 != nullptr)
        {
            ptr2 = foreheadB;

            while (ptr2 != nullptr)
            {
                if (ptr2->next == ptr1->next && ptr2->next != nullptr)
                    return ptr1->next;
                ptr2 = ptr2->next;
            }

            ptr1 = ptr1->next;
        }
        return nullptr;
    }
};
