/*
Definition of doubly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode()
    {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1)
    {
        val = data1;
        next = next1;
        prev = prev1;
    }
};
*/
// delete all occr of DLL:
// optimal soln:

class Solution {
public:
    ListNode * deleteAllOccurrences(ListNode* head, int target) {
        ListNode* temp=head;
        while(temp!=NULL){
            if (temp->val==target){ // if we find the temp->data equal to key
                if (temp==head){
                    head=head->next;

                }
                ListNode* next_node=temp->next;
                ListNode* prev_node=temp->prev;

                if (next_node){ // if next node is not nullptr or end:
                    next_node->prev=prev_node;

                }
                if (prev_node){ // if prev node is not nullptr
                    prev_node->next=next_node;
                }
                temp=next_node;
            }
            else{
                temp=temp->next;
            }
        }
        return head;

    }
};