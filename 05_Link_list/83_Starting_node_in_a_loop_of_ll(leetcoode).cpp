// brute force soln:
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp=head;
        unordered_map<ListNode*, int> mpp;
        while(temp!=NULL){
            if (mpp.find(temp)!=mpp.end()){
                return temp;

            }
            mpp[temp]=1;
            temp=temp->next;
        }
        return NULL;
        
    }
};// optimal soln using floyd's cycle detection algorithm (hare and tortoise method):

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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while( fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){ // if they collide
                slow=head;// place any one pointer(slow) at head and then move them by one place both
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;

                }
                return slow; // point where they collide again is the starting node;

            }

        }
        return NULL;
        
    }
};