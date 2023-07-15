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
        // //naive approach using two iterations
        // if(head->next == nullptr) return nullptr;
        //  ListNode *temp;
        // temp = head;
        // int cnt = 0;
        // while(temp != nullptr){   //counting number of nodes
        //     cnt++;
        //     temp = temp->next;
        // }
        
        // if(cnt == n)          //to delete first element
        //     return head->next;

        // int target = cnt - n - 1; //keep count of targeted node
        // ListNode *nxt, *prev = head;
        // while(target--){
        //     prev = prev->next;
        // }
        // nxt = prev->next->next;  //deleting the required link
        // prev->next = nxt;

        // return head;

        //Optimmized with only one iteration
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;

        for(int i = 0;i < n;i++) fast = fast->next; //moves to nth node
        
        while(fast->next != nullptr){
            fast = fast->next;           //moves end and along with it
            slow = slow->next;           //slow reaches size - n
        }
        slow->next = slow->next->next;  //deleting the link

        return dummy->next;

    }
};
