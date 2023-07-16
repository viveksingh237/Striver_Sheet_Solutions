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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //**Brute force using two loops O(n2)
        // while(headA){
        //     ListNode *temp = headB;
        //     while(temp){
        //         if(headA == temp) return headA;
        //         temp = temp->next;
        //     }
        //     headA = headA->next;
        // }
        // return 0;

        //**Using hashing
        //Or we can use unordered_saet<ListNode*>
        // unordered_map<ListNode*,int> mp;
        // while(headA){
        //     mp[headA]++;
        //     headA = headA->next;    //storing the pinters
        // }
        // while(headB){
        //     if(mp.find(headB) != mp.end())  //looking for pointer in hash table in O(1)
        //     return headB;
        //     headB = headB->next;
        // }
        // return nullptr;

        // //**********Optimized approach using difference in length
        // int l1 = 0, l2 = 0;
        // ListNode *temp1 = headA, *temp2 = headB;

        // while(temp1){
        //     l1++;                    //calc length of list1
        //     temp1 = temp1->next;
        // }
        // while(temp2){
        //     l2++;                     //calc length of list2
        //     temp2 = temp2->next;
        // }
        // if(l1 > l2){
        //     int diff = l1 - l2;
        //     while(diff--)          //moving the ponter ahead by diff if greater
        //     headA = headA->next;
        // }

        // else {
        //      int diff = l2 - l1;     //moving the ponter ahead by diff if greater
        //     while(diff--)
        //     headB = headB->next;
        // }
        // while(headA and headB){
        //     if(headA == headB)   //finally if intersection present they will meet
        //     return headA;
        //     headA = headA->next;
        //     headB = headB->next;
        // }
        // return nullptr;

        // //*****Optimized in one go
        // ListNode *temp1 = headA, *temp2 = headB;
        // while(temp1 != temp2){
        //     temp1 = temp1 == NULL ? headB : temp1->next;
        //     temp2 = temp2 == NULL ? headA : temp2->next;
        // }
        // return temp1;
        ///*********** OR *** Alternate code for above approach
        //easy to understand
        ListNode *temp1 = headA, *temp2 = headB;
        while(temp1 != temp2){
        if(temp1 != nullptr)
        temp1 = temp1->next;
        else 
        temp1 = headB;

        if(temp2 != nullptr)
        temp2 = temp2->next;
        else 
        temp2 = headA;
        }
        return temp1;
    }
};
