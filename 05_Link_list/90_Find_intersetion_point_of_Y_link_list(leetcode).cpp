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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode* , int> mpp;
        ListNode* temp=headA;
        while(temp!=NULL){
            mpp[temp]=1;
            temp=temp->next;
        }
        temp=headB;
        while(temp!=NULL){
            if (mpp.find(temp)!=mpp.end()){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
        
    }
};

// better soln: /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* collide_node(ListNode* t1, ListNode* t2, int d){
        while(d){
            d--;
            t2=t2->next;

        }
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
        }
        return t1;

    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        int n1=0;
        int n2=0;
        ListNode* temp2=headB;

        while(temp1!=NULL){
            n1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            n2++;
            temp2=temp2->next;
        }
        if (n1<n2){
            return collide_node(headA, headB, n2-n1);

        }
        else{
            return collide_node(headB, headA, n1-n2);
        }
        return NULL;

        
    }
};
//optimal soln:

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA==NULL || headB == NULL){
            return NULL;
        }
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=temp2){
            temp1=temp1->next;
            temp2=temp2->next;
            if (temp1==temp2){
                return temp1;
            }
            if (temp1==NULL){
                temp1=headB;
            }
            if (temp2==NULL){
                temp2=headA;
            }
        }
        return temp1;
        
    }
};