// brute force soln:

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        vector<int> arr;
        
        // 1. Collect odd-indexed node values
        ListNode* temp = head;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            if (temp->next == nullptr) break;
            temp = temp->next->next;
        }

        // 2. Collect even-indexed node values
        temp = head->next;
        while (temp != nullptr) {
            arr.push_back(temp->val);
            if (temp->next == nullptr) break;
            temp = temp->next->next;
        }

        // 3. Reset temp back to head and overwrite values
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->val = arr[i];
            temp = temp->next;
        }

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next){
            return head;

        }
        ListNode* temp=head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* even_head=head->next;

        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next; // odd next points to odd-next-next
            even->next=even->next->next;

            odd=odd->next; // odd advances to odd next
            even=even->next;


        }
        odd->next=even_head;
        return head;

        
    }
};