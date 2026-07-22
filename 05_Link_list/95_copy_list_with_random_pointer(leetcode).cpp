/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
//  brute force approach is to use a map to store the mapping of original node to copied node. Then we can iterate through the original list and set the next and random pointers of the copied nodes using the map. Finally, we return the copied head node.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head;
        unordered_map<Node* , Node*> mpp;
        while(temp!=NULL){
            Node* new_node=new Node(temp->val);
            mpp[temp]=new_node;
            temp=temp->next;


        }

        temp=head;
        while(temp!=NULL){
            Node* copy_node=mpp[temp];
            copy_node->next=mpp[temp->next];
            copy_node->random=mpp[temp->random];
            temp=temp->next;

        }
        return mpp[head];



        
    }
};

// optimal soln:
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insert_copy_nodes(Node* head){
        Node* temp=head;

        while(temp!=NULL){
            // we will insert copy nodes in between two nodes of LL:
            Node* new_node=new Node(temp->val);
            new_node->next=temp->next;
            temp->next=new_node;
            temp=temp->next->next;


        }
        
    }
    void connect_random_points(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* new_node=temp->next;
            if (temp->random){
                new_node->random=temp->random->next;
            }
            else{
                new_node->random=nullptr;

            }
            temp=temp->next->next;
            
        }
    }

    Node* connect_next(Node* head){
        Node* temp=head;
        Node* dummy_node=new Node(-1);
        Node* res=dummy_node;

        while(temp!=NULL){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;


        }
        return dummy_node->next;

    }
    Node* copyRandomList(Node* head) {
        insert_copy_nodes(head);
        connect_random_points(head);
        return connect_next(head);
        
        
    }
};