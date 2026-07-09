#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data=data1;
        next=next1;

    }
    Node(int data1){
        data=data1;
        next=NULL;
    }

};

// converting array to link list:

Node* convert_to_ll(vector<int> arr){
    Node* head=new Node(arr[0]);
    int n=arr.size();
    Node* temp=head;
    for (int i=1;i<n;i++){
        Node* new_node=new Node(arr[i]);
        temp->next=new_node;
        temp=new_node;
    }
    return head;
}

// traversal of link list:

void print_link_list(Node* head){
    Node* temp=head; // store head value in temp so that we can traverse the link list without losing the head value
    while(temp!=NULL){
        cout<< temp->data<<" ";// print the temp value stored   
        temp=temp->next;




    }
}

// length of an link list:

void len_ll(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;

    }
    cout<< cnt<< endl;
}

// delete head in LL:
Node* delete_head(Node* head){
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;

}

// delete tail in LL:
Node* delete_tail(Node* head){
    Node* temp=head;
    if (head==NULL || head->next==NULL){
        return NULL;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;

    }
    delete temp->next;
    temp->next=NULL;
    return head;
    

}

// remove kth position node in LL:

Node* removeKth_node(Node* head, int k){
    if (head==NULL){
        return NULL;
    }
    if (k == 1){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=0;
    while(temp!=NULL){
        cnt++;
        if (cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

}
// insertion operations in LINKED LIST:

// insertion before head in ll:

Node* insert_before_head(Node* head , int data){
    Node* new_node=new Node(data); // enter the data to  be inserted in new node
    new_node->next=head; // point the next of new node to head
    head=new_node;// point the head to new node
    return head;// return the new head of the link list

}
// inseertion at tail in ll:

Node* insert_at_tail(Node* head, int data){
    Node* new_node=new Node(data); // create a new node with the data to be inserted
    if (head==NULL){ // if the link list is empty
        head=new_node; // point the head to new node
        return head; // return the new head of the link list
    }
    Node* temp=head; // store the head value in temp so that we can traverse the link list without losing the head value
    while(temp->next!=NULL){ // traverse till the last node of the link list
        temp=temp->next;
    }
    temp->next=new_node; // point the next of last node to new node
    return head; // return the head of the link list

}
// insertion at kth place in link list:

Node* insert_at_kth(Node* head, int data, int k){
    Node* new_node=new Node(data); // create a new node with the data to be inserted
    if (k==1){ // if the position to be inserted is 1
        new_node->next=head; // point the next of new node to head
        head=new_node; // point the head to new node
        return head; // return the new head of the link list
    }
    int cnt=0;
    Node* temp=head; // store the head value in temp so that we can traverse the link list without losing the head value
    while(temp!=NULL){ // traverse till the last node of the link list
        cnt++;
        if (cnt==k-1){ // if the position to be inserted is k-1
            new_node->next=temp->next; // point the next of new node to next of temp
            temp->next=new_node; // point the next of temp to new node
            break;
        }
        temp=temp->next;
    }
    return head; // return the head of the link list

}
// insert before a value in link list:

Node* insert_before_value(Node* head, int data, int value){
    Node* new_node=new Node(data); // create a new node with the data to be inserted
    if (head==NULL){ // if the link list is empty
        head=new_node; // point the head to new node
        return head; // return the new head of the link list
    }
    if (head->data==value){ // if the value to be inserted is at the head
        new_node->next=head; // point the next of new node to head
        head=new_node; // point the head to new node
        return head; // return the new head of the link list
    }
    Node* temp=head; // store the head value in temp so that we can traverse the link list without losing the head value
    while(temp->next!=NULL){ // traverse till the last node of the link list
        if (temp->next->data==value){ // if the value to be inserted is found
            new_node->next=temp->next; // point the next of new node to next of temp
            temp->next=new_node; // point the next of temp to new node
            break;
        }
        temp=temp->next;
    }
    return head; // return the head of the link list

}
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convert_to_ll(arr);
    print_link_list(head);
    cout<< endl;
    // head=delete_head(head);
    // print_link_list(head);
    // cout<< endl;
    // head=delete_tail(head);
    // print_link_list(head);
    // cout<< endl;
    // head=removeKth_node(head, 2);
    // print_link_list(head);
    // cout<< endl;
    head = insert_before_head(head, 7);
    print_link_list(head);
    head = insert_at_tail(head, 6);
    print_link_list(head);
    head = insert_at_kth(head, 8, 3);
    print_link_list(head);
    head = insert_before_value(head, 9, 4);
    print_link_list(head);

    // len_ll(head);
}