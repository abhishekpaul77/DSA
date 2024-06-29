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

// Insertion at the head of the linked list
Node* insert_head(Node* head, int data){
    head=new Node(data, head);
    return head;
}

// Insertion at the end of the linked list
Node* insert_tail(Node* head,int data){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(data);
    temp->next=newNode;

    return head;
}


// Insert at the given position
Node* insert_at_position(Node* head,int data,int k){
    if(head==NULL){
        if(k==1){
            return new Node(data);
        }
        else{
            return head;
        }
    }

    if(k==1) return new Node(data,head);

    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* newNode=new Node(data,temp->next);
            temp->next=newNode;
            return head;
        }
        temp=temp->next;

    }
    return head;

}

// Insert at the given value
Node* insert_at_value(Node* head,int data,int k){
     if(head==NULL){
       return NULL;
    }

    if(head->data==k) return new Node(data,head);

    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==k){
            Node* newNode=new Node(data,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;

    }
    return head;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head=array_to_linkedList(arr);
    // Inserting at the head of the linked list
    // head=insert_head(head, 7);
    // print_linked_list(head);

    // Inserting at the end of the linked list
    // head=insert_tail(head,7);
    // print_linked_list(head);

    // Inserting at the given position
    // head=insert_at_position(head,7,3);
    // print_linked_list(head);

    // Inserting at the given value
    // head=insert_at_value(head,7,3);
    // print_linked_list(head);

    return 0;
}