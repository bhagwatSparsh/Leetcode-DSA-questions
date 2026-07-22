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
    ListNode* reverse_ll(ListNode* temp) {
        if (temp == NULL || temp->next == NULL) {
            return temp;
        }
        
        ListNode* prev = NULL;
        ListNode* current = temp;
        ListNode* front = NULL;
        while (current != NULL) {
            front = current->next;
            current->next = prev;
            prev = current;
            current = front;
        }
        return prev;
    }

    ListNode* get_kth_node(ListNode* temp, int k) {
        k = k - 1;

        while (temp != NULL && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* kth_node = get_kth_node(temp, k);

            // If there are fewer than k nodes remaining
            if (kth_node == NULL) {
                if (prev) { // if prev exists:
                    prev->next = temp;
                }
                break;
            }

            ListNode* next_node = kth_node->next;
            kth_node->next = NULL;

            // Reverse current group of size k
            reverse_ll(temp);

            if (temp == head) {
                head = kth_node;
            } else {
                prev->next = kth_node;
            }

            prev = temp;
            temp = next_node;
        }

        return head;
    }
};