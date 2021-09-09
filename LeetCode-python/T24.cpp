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
//本人写的；
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        
        ListNode* first = head;
        ListNode* second = nullptr;
        ListNode* tmp = nullptr;
        while (first && first->next)
        {
            second = first->next;
            
            if (tmp != nullptr)
                tmp->next = second;
            else head = second;

            first->next = second->next;
            second->next = first;
            tmp = first;
            first = first->next;
            
        }
        return head;
    }
};
