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
        // bypassing the node technique by copying:
        node->val=node->next->val; // take the value of next after node, and store it in node
        ListNode* temp=node->next; // poit the temp to next of node

        node->next=node->next->next; // node  next will point to node next next thereby bypassing temp which is node next;
        delete temp; // free or delete temp;
        
        
    }
};