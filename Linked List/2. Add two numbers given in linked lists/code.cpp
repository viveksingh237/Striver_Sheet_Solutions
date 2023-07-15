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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      //defining a dummy and ans node to store the result
        ListNode *dummy ,*ans;
        ans = new ListNode(-1);
        dummy = ans;
        int c = 0;  //initially carry is 0
        while(l1 != 0 or l2 != 0 or c != 0){
            int sum = 0;
            ListNode *temp = new ListNode();
            if(l1 != 0){
                sum += l1->val;
                l1 = l1->next;
            }                       //sum is claculated based on the exiztence of the //                                   //lists elements
            if(l2 != 0){
                sum += l2->val;
                l2 = l2->next;
            }
            sum = sum + c;
            c = sum/10;

            temp->val = sum % 10;
            temp->next = nullptr;
            ans->next = temp;
            ans = ans->next;
        
        }
        
        return dummy->next;
    }
};
