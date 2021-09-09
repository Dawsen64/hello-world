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
//递归 //参考 https://lyl0724.github.io/2020/01/25/1/
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* cur;
        cur = head->next;
        head->next = swapPairs(cur->next);
        cur->next = head;
        return cur;
    }
};

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
