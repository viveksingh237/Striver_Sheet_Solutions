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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Optimized approach using three pointers
        if(!head or k == 1) return head;
        int cnt = 0;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *pre = dummy,*cur = dummy,*nxt = dummy;
        while(head){
            cnt++;
            head = head->next;
        }
         while(cnt >= k){
             cur = pre->next;
             nxt = cur->next;

             for(int i = 1;i < k;i++){
                 cur->next = nxt->next;
                 nxt->next = pre->next;
                 pre->next = nxt;
                 nxt = cur->next;
             }
             pre = cur;
             cnt -= k;
         }
         return dummy->next;
    }
};
