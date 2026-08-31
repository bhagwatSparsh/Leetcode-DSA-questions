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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next){
            return {-1, -1};

        }
        
        ListNode* prev=head;
        ListNode* curr=head->next;
        int first_cp=-1;
        int prev_cp=-1;
        int min_dist=INT_MAX;
        int idx=1;
        
        while(curr->next!=NULL){
            ListNode* next=curr->next; //define next as it a member variable inside struct and needs to be defined to access separately
            bool is_local_min=false;
            bool is_local_max=false;
            if (curr->val < prev->val && curr->val < next->val){
                is_local_min=true;
            }
            if (curr->val > prev->val && curr->val > next->val){
                is_local_max=true;

            }
            if (is_local_min || is_local_max){
                if (first_cp==-1){ // if there has been no first cp so this is the first
                    first_cp=idx; // assign it to idx to remember for max distn

                }
                else{
                    min_dist=min(min_dist,idx-prev_cp); // calc the min_din so far by idx-prev_cp;
                }
                prev_cp=idx;



            }
            prev=curr;
            curr=next;
            idx++;
            


        }
        // if there are less than 2 cp:
        if (first_cp==-1 || first_cp==prev_cp){
            return {-1,-1};
        }
        int max_dist=prev_cp-first_cp;
        return {min_dist, max_dist};
    }
};