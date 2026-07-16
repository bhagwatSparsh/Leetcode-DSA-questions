// brute force soln:
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;

        }
        if (cnt==n){
            // incase nth from end which is the head node so we have to remove it and return head-next
            ListNode* new_head=head->next;
            delete head;
            return new_head;

        }
        temp=head;
        int res=cnt-n;
        while(res>1){
            res--;
            temp=temp->next;

        }
        ListNode* del_node=temp->next;
        
        temp->next=temp->next->next;
        delete del_node;
        return head;

    }
};

// optimal soln:

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* fast=head;
        for (int i=0;i<n;i++){
            fast=fast->next;

        }
        ListNode* slow=head;
        if (fast==NULL){
            return head->next;

        }
        while(fast->next!=NULL ){
            slow=slow->next;
            fast=fast->next;

        }
        ListNode* del_node=slow->next;
        slow->next=slow->next->next;
        delete del_node;
        return head;
        
    }
};