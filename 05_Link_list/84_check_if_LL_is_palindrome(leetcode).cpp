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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        stack<int> st;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;

        }
        temp=head;
        while(temp!=NULL){
            if (temp->val!=st.top()){
                return false;

            }
            st.pop();
            temp=temp->next;

        }
        return true;

        
    }
};
// optimal sol :
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
    ListNode* reverse_ll(ListNode* head){
        ListNode* prev=NULL;
        ListNode* temp=head;
        ListNode* front=temp;

        while(temp!=NULL){
            front=temp->next; // save the temp next in front;
            temp->next=prev; // rewire the temp next to previous to change the links and reverse the link list;
            prev=temp;
            temp=front;
        }
        return prev;

    }
    bool isPalindrome(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return true;

        }
        // find the middle element in the link list to separate it into two halves:
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        ListNode *new_head=reverse_ll(slow->next);
        ListNode* first=head;
        ListNode* second=new_head;
        while(second!=NULL){
            if (second->val!=first->val){
                reverse_ll(slow->next);
                return false;
            }
            first=first->next;
            second=second->next;

        }
        reverse_ll(slow->next);
        return true;

        
    }
};