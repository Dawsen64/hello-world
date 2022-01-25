/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//哈希表
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while (head != nullptr)
        {
            if (visited.count(head))
                return head;
            else 
            {
                visited.insert(head);
                head = head->next;
            }
        }
        return nullptr;
    }
};

//快慢指针
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *quik = head;
        ListNode* cur = head;
        // if (head == nullptr || head->next == nullptr)
        //     return nullptr;
        while (quik != nullptr)
        {
            slow = slow->next;
            if (quik->next == nullptr)
                return nullptr;
            else quik = quik->next->next;
            if (slow == quik)
            {
                while (cur != slow)
                {
                    cur = cur->next;
                    slow = slow->next;
                }
                return cur;
            }
        }
        return nullptr;
    }
};
