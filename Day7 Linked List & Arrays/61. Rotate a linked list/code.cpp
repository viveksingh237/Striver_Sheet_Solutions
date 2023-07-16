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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or  k == 0 or !head->next) return head;

    //     //******Brute force using extra space
    //     ListNode *temp = head;
    //     int cnt = 0;
    //     while(temp){
    //         cnt++;              //counting the nodes
    //         temp = temp->next;
    //     }

    //     vector<int> v(cnt , 0);
    //     int j = k;
    //     temp = head; 
    //      while(temp){           //copying nodes value in vector alongwith rotation
    //         v[j%cnt] = temp->val;
    //         temp = temp->next;
    //         j++;
    //     }

    //     temp = head;
    //     int i = 0;
    //      while(temp){          //copying back values to linked list after rotation
    //         temp->val = v[i];
    //         temp = temp->next;
    //         i++;
    //     }
        
    //   return head;


    //***********Optimized approach....
    //point last->next to first node and make n-kth node->next = NULL
          ListNode *temp1 = head,*temp2 = head,*result;
          int cnt = 0;
          while(temp1->next){
              cnt++;             //counting the elements
              temp1 = temp1->next;
          }
          //cout<<temp1->val<<' ';
          cnt++;
          if(k % cnt == 0) return head; //if k multiple of size
          int r = k%cnt;
          
          for(int i = 0;i < cnt - r -1;i++)
             temp2 = temp2->next;
          //cout<<temp2->val<<' ';
          result = temp2->next;       //storing the node to return
          temp2->next = nullptr;      //making the new last node to null 
          temp1->next = head;         //linking the last and first node

          return result;

    }
};
