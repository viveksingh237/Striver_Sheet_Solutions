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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
    //    //****** Using extra space
    //     ListNode *dummy,*mergeList;
    //     if(list2 == nullptr) return list1;
    //     mergeList = new ListNode();
    //     dummy = mergeList;

    //     while(list1 != nullptr and list2 != nullptr){
    //         if(list1->val <= list2->val){              //if list1 val is smaller
    //         mergeList->next = new ListNode(list1->val);
    //         list1 = list1->next;
    //         }
    //         else{                                       //if list2 val is smaller
    //             mergeList->next = new ListNode(list2->val);
    //         list2 = list2->next;
    //         }
    //         mergeList = mergeList->next;                //increasing ptr in new list
    //     }
    //     while(list1 != nullptr){
    //           mergeList->next = new ListNode(list1->val);
    //         list1 = list1->next;                    //adding remaining elements of list1
    //         mergeList = mergeList->next;
    //     }

    //     while(list2 != nullptr){                    //adding remaining elements of list2
    //           mergeList->next = new ListNode(list2->val);
    //         list2 = list2->next;
    //         mergeList = mergeList->next;
    //     }

    //   return dummy->next;


    //without using extra space
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;

     ListNode *dummy;
     if(list1->val >= list2->val) //if list2 greater initially swap
     swap(list1, list2);          //we are always keeping list1 with smaller element
     dummy = list1;               //head is stored in dummy
    while(list1 and list2){
        ListNode *tmp;
         while(list1 != nullptr and list1->val <= list2->val){
            tmp = list1;
            list1 = list1->next;   //if next greatr is found in another list
         }
         tmp->next = list2;
         swap(list1, list2);
    }

    return dummy;
    }
};
