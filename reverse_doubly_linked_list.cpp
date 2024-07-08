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

// Brute force approach: Using stack
// Time complexity: O(n)
// Space complexity: O(n)
Node* reverse_BF(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    stack<Node*> s;
    Node* curr=head;
    while(curr!=NULL){
        s.push(curr);
        curr=curr->next;
    }
    head=s.top();
    curr=head;
    s.pop();
    while(!s.empty()){
        curr->next=s.top();
        s.top()->back=curr;
        s.pop();
        curr=curr->next;
    }
    curr->next=NULL;    
    return head;
}

// Optimal solution
// Time complexity: O(n)
// Space complexity: O(1)
Node* reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* curr=head;
    Node* last=NULL;
    while(curr!=NULL){
        last=curr->back;
        curr->back=curr->next;
        curr->next=last;
        curr=curr->back;
    }
    return last->back;
}

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
    int n;
    cin>>n;
    vector<int> v={1,2,3,4,5};
    Node* head=arr_to_linkedList(v);
    // head=reverse_BF(head);
    // print_linked_list(head);

    head=reverse(head);
    print_linked_list(head);

    return 0;
}