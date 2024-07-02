#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node in the list (forward direction)
    Node *back; // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node *arr_to_linkedList(vector<int> arr)
{
    // Create the head node with the first element of the array
    Node *head = new Node(arr[0]);
    // Initialize 'prev' to the head node

    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node *temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node

        prev->next = temp;
        // Move 'prev' to the newly created node for the next iteration

        prev = temp;
    }
    // Return the head of the doubly linked list

    return head;
}


// Function to insert at the head of the doubly linked list
Node* insert_head(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* newNode=new Node(val);
    head->back=newNode;
    newNode->next=head;
    head=newNode;
    return head;
}

// Function to insert before the tail of the doubly linked list
Node* insert_before_tail(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    if(head->next==nullptr){
        return insert_head(head,val);
    }
    Node* temp=head;
    Node* prev=nullptr;
    while(temp->next!=nullptr){
        prev=temp;
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    newNode->next=temp;
    newNode->back=prev;
    prev->next=newNode;
    temp->back=newNode;
    return head;

}

// Function to insert before kth node of the doubly linked list
Node* insert_before_kth(Node* head,int val,int k){
    if(head == nullptr){
        return nullptr;
    }
    if(k==1){
        return insert_head(head,val);
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=nullptr;
    while(temp->next!=nullptr){
        cnt++;
        prev=temp;
        temp=temp->next;
        if(cnt==k-1){
            break;
        }
    }
    Node* newNode=new Node(val,temp,prev);
    temp->back=newNode;
    prev->next=newNode;
    return head;
}


// Insert before a node in a doubly linked list
void insert_before_node(Node* node,int val){
    Node* prev=node->back;
    Node* newNode=new Node(val,node,prev);
    prev->next=newNode;
    node->back=newNode;
}

// Function to print the linked list
void print_linked_list(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = arr_to_linkedList(arr);

    // Insert 0 at the head of the doubly linked list
    // head = insert_head(head, 0);
    // print_linked_list(head);

    // Insert 6 before the tail of the doubly linked list
    // head = insert_before_tail(head, 6);
    // print_linked_list(head);

    // Insert 10 before the 3rd node of the doubly linked list
    // head = insert_before_kth(head, 10, 3);
    // print_linked_list(head);

    // Insert 7 before the 4th node of the doubly linked list
    // Node* temp=head;
    // for(int i=0;i<4;i++){
    //     temp=temp->next;
    // }
    insert_before_node(head->next->next,7);
    print_linked_list(head);
    return 0;
}