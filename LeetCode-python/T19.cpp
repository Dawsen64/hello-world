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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tmp = head, *cur = head, *after;
        short count = 1;
        while (cur->next != nullptr)
        {
            cur = cur->next;
            count++;
            if (count > n)
                {
                    after = tmp;
                    tmp = tmp->next;
                    count--;
                }
        }
        if (tmp == head)
            return head->next;
        else
        {
            after->next = after->next->next;
            return head;
        }        
    }
};
