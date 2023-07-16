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
        // //*****Brute force****
        // //Use a hash table for storing nodes
        // unordered_set<ListNode*> hash;
        // ListNode *temp = head;
        // while(temp){
        //     if(hash.find(temp) != hash.end())
        //     return temp;
        //     hash.insert(temp);
        //     temp = temp->next;
        // }
        // return nullptr;

       
        //******Using floyd cycle or Hare-tortoise method
        if(!head or !head->next) return nullptr;
        ListNode *slow = head, *fast = head,*entry = head;
        while(fast->next and fast->next->next){
            
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){     ///forst collision point
              while(slow != entry){
                slow = slow->next;
                entry = entry->next;
              }
              return slow;     //second collision or entry point
           }
        }
        
        return nullptr;
    }
};
