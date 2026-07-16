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
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
        vector<int> arr;
        
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;


        }

        sort(arr.begin(), arr.end());
        temp=head;
        int i=0;
        while(temp!=NULL){
            temp->val=arr[i];
            i++;
            temp=temp->next;
        }
        return head;

    }
};
// optimized soln: merge sort
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
    ListNode* find_middle(ListNode* head){
        // modify tortoise and hare algo to get the first middle in gterms of even no so that we can split and apply merge sort
        ListNode* temp=head;
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

        }
        return slow;
    }
    ListNode* merge_lists(ListNode* list1, ListNode* list2){
        ListNode* dummy_node=new ListNode(-1);
        ListNode* temp=dummy_node;
        while(list1!=NULL && list2!=NULL){
            if (list1->val < list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;

            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;

            }
        }
        if (list1){
            temp->next=list1;

        }
        else{
            temp->next=list2;

        }
        return dummy_node->next;


    }
    ListNode* sortList(ListNode* head) {  
        if (head==NULL || head->next==NULL){
            return head;

        }
        ListNode* midd_elem=find_middle(head);// find the midd_elem for the ll
        ListNode* right=midd_elem->next;// get the right eleme to get two separate arrays/ ll
        midd_elem->next=nullptr; // point the mid elem next to null ptr for separate ll after partitioning
        ListNode* left=head;

        left=sortList(left);
        right=sortList(right);
        return merge_lists(left, right);



        
    }
};