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
    void deleteNode(ListNode* node) {
        // here we are not actually deleting the node 
        //instead we are copying neat node value into this node and next node is deleted/ignored
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
