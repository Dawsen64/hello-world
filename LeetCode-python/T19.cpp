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

//上面的这个版本也是双指针法，但是不简洁

//修改后的双指针法
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
        ListNode *forehead = new ListNode(0, head);
        ListNode *first = head, *second = forehead;
        short i = 1;
        while (i < n)
        {
            first = first->next;
            i++;
        }
        while (first->next != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return forehead->next;
    }
};
