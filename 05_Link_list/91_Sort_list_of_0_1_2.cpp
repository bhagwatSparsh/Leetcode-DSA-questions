/*
Definition of singly linked list:
class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode() : data(0), next(nullptr) {}
    ListNode(int x) : data(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : data(x), next(next) {}
};
*/

class Solution {
    public:
        ListNode* sortList(ListNode* &head) {
            if (head==NULL || head->next==NULL){
                return head;

            }
            ListNode* zero_head=new ListNode(-1);
            ListNode* one_head=new ListNode(-1);
            ListNode* two_head=new ListNode(-1);
            ListNode * zero=zero_head;
            ListNode* one=one_head;
            ListNode* two=two_head;

            ListNode* temp=head;
            while(temp!=NULL){
                if (temp->data==0){
                    zero->next=temp;
                    zero=temp;

                }
                else if(temp->data==1){
                    one->next=temp;
                    one=temp;

                }
                else{
                    two->next=temp;
                    two=temp;
                }
                temp=temp->next;
            }
            zero->next=(one_head->next)? (one_head->next) : two_head->next;
            one->next=two_head->next;
            two->next=NULL;
            ListNode* new_head=zero_head->next;
            
            return new_head;
            
        }
};