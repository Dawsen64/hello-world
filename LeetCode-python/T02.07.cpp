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
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        phead1 = ListNode(-1, headA)
        phead2 = ListNode(-1, headB)
        p1 = phead1
        p2 = phead2
        flag1, flag2 = False, False
        while ~flag1 or ~flag2:
            if p1.next == p2.next:
                return p1.next

            if p1.next == None:
                p1 = phead2
                flag1 = True
            else:   
                p1 = p1.next

            if p2.next == None:
                p2 = phead1
                flag2 = True
            else:
                p2 = p2.next
        return None
