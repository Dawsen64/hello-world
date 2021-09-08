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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* ptr1 = head;
        head = nullptr;
        ListNode* ptr2 =  nullptr;


        while (ptr1)
        {
            ptr2 = ptr1->next;

            ptr1->next = head;
            head = ptr1;
            ptr1 = ptr2;
        }

        return head;
    }
};



//我自己写的，对于边缘没有处理好
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) 
        {
            return head;
        }
        else if (head->next->next == nullptr)
        {
            ListNode* tmp = head->next;
            head->next->next = head;
            head->next = nullptr;
            head = tmp;
            return head;
        }
        ListNode* ptr1 = head->next, *ptr2 = ptr1->next; 
        head->next = nullptr;

        while (ptr2->next != nullptr)
        {
            ptr1->next = head;
            head = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        //最后两个节点的时候跳出循环，在循环外反转
        ptr1->next = head;
        head = ptr1;
        ptr1 = ptr2;
        ptr1->next = head;
        head = ptr1;

        return head;
    }
};
