#include <iostream>
using namespace std;

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct LinkNode {
        int val;
        LinkNode* next;
        LinkNode(int x, LinkNode* ptr) :val(x), next(ptr) {}
    };
    LinkNode* head;
    int length;
    MyLinkedList() {
        head = new LinkNode(0, nullptr);
        length = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >=0 && index < length){
            LinkNode* ptr = head->next;
            while (index > 0) {
                ptr = ptr->next;
                index--;
            }
            return ptr->val;
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        LinkNode* tmp = new LinkNode(val, head->next);
        head->next = tmp;
        length++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        LinkNode* tmp = new LinkNode(val, nullptr);
        LinkNode* ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = tmp;
        length++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if (index <= length) {

            LinkNode* ptr = head;
            while (index > 0) {
                ptr = ptr->next;
                index--;
            }
            LinkNode* tmp = new LinkNode(val, ptr->next);
            ptr->next = tmp;
            length++;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        LinkNode* ptr = head;
        if (index >= 0 && index < length) {
            while (index > 0) {
                ptr = ptr->next;
                index--;
            }
            ptr->next = ptr->next->next;
            length--;
        }
    }
    void printlist(void)
    {
        LinkNode* ptr = head->next;
        while (ptr != nullptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    MyLinkedList linkedList;
    linkedList.addAtHead(1);

    linkedList.printlist();

    linkedList.addAtTail(3);

    linkedList.printlist();
    cout << linkedList.length << endl;
    linkedList.addAtIndex(1, 2);   //链表变为1-> 2-> 3

    cout << "//链表变为1-> 2-> 3:  ";
    linkedList.printlist();

    cout << "//返回2  " << linkedList.get(1) << endl;
    linkedList.deleteAtIndex(1);//现在链表是1-> 3
    cout << "//现在链表是1-> 3:   ";
    linkedList.printlist();
    cout << "//返回3  " << linkedList.get(1) << endl;
}

//来源：力扣（LeetCode）
//链接：https ://leetcode-cn.com/problems/design-linked-list
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
