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
    
    //Function to reverse a linked list
    ListNode *reversell(ListNode *head){
        ListNode *prev = NULL;
        while(head){
            ListNode *nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
            
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //******** Brute force using a vector
        // vector<int> ll;
        // while(head){
        //     ll.push_back(head->val);
        //     head = head->next;         //linked lit to vector
        // }

        // for(int i = 0,j = ll.size()-1;i <= j;i++, j--)
        //     if(ll[i] != ll[j]) return false;          //checking vector for plindrome using two pointer

        // return true;


        //*********without using extra space
        ListNode *slow = head,*fast = head;

        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;           //finding the middle element
        }

        slow->next = reversell(slow->next);  //reversing ll after middle element
        slow = slow->next;

        while(slow){                       //checking for palindrome
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
       
        return true;

    }
};
