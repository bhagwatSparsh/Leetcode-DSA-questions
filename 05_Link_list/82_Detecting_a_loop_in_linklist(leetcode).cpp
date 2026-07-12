// brute force solution:
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
    bool hasCycle(ListNode *head) {
        ListNode* temp=head;
        unordered_map<ListNode*, int> mpp;
        while(temp!=NULL){
            if (mpp.find(temp)!=mpp.end()){ // if we find temp again in the map, then return true as it is a cycle or a loop
                return true;
            }
            mpp[temp]=1; // else store node with visited 1
            temp=temp->next;


        }
        return false;
        

        
    }
};

// optimal soln using floyd's cycle detection algorithm (hare and tortoise method):g
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
    bool hasCycle(ListNode *head) {
    
        ListNode* slow=head;
        ListNode* fast=head;

        while( fast !=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast){
                return true;

            }
        }
        return false;

        
    }
};