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

class Solution {
public:
    ListNode * removeDuplicates(ListNode *head) {
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* new_node=temp->next;
            while(new_node!=NULL && temp->val==new_node->val){
                ListNode* duplicate=new_node;
                new_node=new_node->next;
                delete duplicate;




            }
            temp->next=new_node;
            if (new_node){
                new_node->prev=temp;

            }
            temp=temp->next;
        }
        return head;

    }
};