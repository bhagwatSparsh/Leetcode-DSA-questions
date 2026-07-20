// optimal soln: recursive approach:


/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int data1) : val(data1), next(NULL) {}
    ListNode(int data1, ListNode *next1) : val(data1), next(next1) {}
};
*/

class Solution {
public:
    // Helper function processes nodes recursively and returns the carry to add
    int helper(ListNode* temp) {
        // Base case: beyond the last node, start with a carry of 1
        if (temp == NULL) {
            return 1;
        }

        // Recurse to the tail first
        int carry = helper(temp->next);

        // Add carry to the current node's value
        temp->val += carry;

        // If total is less than 10, no carry is passed up
        if (temp->val < 10) {
            return 0;
        }

        // If total is 10, set value to 0 and pass carry = 1 to the previous node
        temp->val = 0;
        return 1;
    }

    ListNode *addOne(ListNode *head) {
        int carry = helper(head);

        // If a carry remains after processing the head (e.g., 999 -> 1000),
        // create a new node with value 1 at the beginning.
        if (carry == 1) {
            ListNode* new_node = new ListNode(1);
            new_node->next = head;
            return new_node;
        }

        return head;
    }
};