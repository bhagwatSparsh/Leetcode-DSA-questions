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
int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=convert_to_ll(arr);
    print_link_list(head);
    cout<< endl;
    head=delete_head(head);
    print_link_list(head);
    cout<< endl;
    head=delete_tail(head);
    print_link_list(head);
    cout<< endl;
    head=removeKth_node(head, 2);
    print_link_list(head);
    cout<< endl;
    len_ll(head);
}