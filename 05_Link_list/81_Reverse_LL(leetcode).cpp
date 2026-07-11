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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        stack<int> st;

        while(temp!=NULL){
            st.push(temp->val);// push the value of temp to stack(data);

            temp=temp->next;// move the temp pointer;

        }

        temp=head;
        while(temp!=NULL){
            temp->val=st.top(); //push value of tos into temp as data;
            st.pop();// pop out from stack so that tos change and we can add another value
            temp=temp->next;
        }
        return head;


        
    }
};

// optimal soln:
//1. Iterative approach:
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* front=temp;

        while(temp!=NULL){
            front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;

        }
        return prev;
        
    }
};


