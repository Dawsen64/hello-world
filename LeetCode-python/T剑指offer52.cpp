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
        unordered_set <ListNode*> set;
        ListNode* p = headA;
        while(p != nullptr)
        {
            set.insert(p);
            p = p->next;
        }
        p = headB;
        while(p != nullptr)
        {
            if(set.count(p))
            {
                return p;
            }
            p = p->next;
        }
        return nullptr;
    }
};
//双指针法
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
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* pA, *pB;
        pA = headA;
        pB = headB;
        
        while(pA != nullptr || pB != nullptr)
        {
            if(pA == nullptr)
                pA = headB;
            if(pB == nullptr)
                pB = headA;
            if(pA == pB)
                return pA;

            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};
