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
    bool hasCycle(ListNode *head) {
      ///1. CAn do using hashing if pointer saved in hash table occurs again return true

      //2. usng slow and fast pointer
       ListNode *slow = head, *fast = head;
       while(fast and fast->next){
           slow = slow->next;
           fast = fast->next->next;
           if(slow == fast) return true;
       }
       return false;
    }
};
