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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode *dummy = nullptr;
        while(head != NULL){
             ListNode *nxt = head->next; //storing the link to next pointer
             head->next = dummy;         //assigning prev node to current
             dummy = head;               //now curr is given to prev
             head = nxt;                 //next is stored in cur
        }
     return dummy;
    }
};
