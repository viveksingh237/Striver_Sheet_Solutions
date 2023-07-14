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
    ListNode* middleNode(ListNode* head) {
        //Naive approach
        // if(head == nullptr) return head; //corner case
        // int cnt = 0;
        // ListNode *temp = head;
        // while(temp != nullptr){ //counting number of nodes
        //     temp = temp->next;
        //     cnt++;
        // }
        // //cout<<cnt;
        // int mid = cnt/2;
        
        // while(mid){
        //     head = head->next;   //traversing to middle node
        //     mid--;
        // }
        // return head;

        //Optimal approach O(n/2)
        if(head == nullptr) return head; //corner case
        ListNode *slow = head,*fast = head;
        
        while(fast->next != nullptr){
            slow = slow->next;          //using floyd cycle
            fast = fast->next;          //while next will reach last node
            if(fast->next)              // slow will reach the middle node
            fast = fast->next;
        }
        return slow;
    }
};
