#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
    }
};

// Function to convert an array to a linked list
Node *array_to_linkedList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Function to print the linked list
void print_linked_list(Node* head)
{
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

// Delete the head of the linked list
Node* delete_head(Node* head){
    if(head==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    free(temp);// or delete temp;
    return head;
}

// Delete the tail of the linked list
Node* delete_tail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);// or delete temp->next;
    temp->next=NULL;
    return head;
}

// Delete the node at a given position
Node* delete_node(Node* head, int k){
    if(head==NULL) return NULL;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

// Delete the node with a given value
Node* delete_node_with_value(Node* head, int val){
    if(head==NULL) return NULL;
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==val){
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
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head=array_to_linkedList(arr);
    // Deletion of head
    // head=delete_head(head);
    // print_linked_list(head);

    // Deletion of tail
    // head=delete_tail(head);
    // print_linked_list(head);

    // Deletion of node at a given position
    // head=delete_node(head, 3);
    // print_linked_list(head);

    // Deletion of node with a given value
    // head=delete_node_with_value(head, 3);
    // print_linked_list(head);

    return 0;
}