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


// Function to convert an array to a doubly linked list
Node *arr_to_linkedList(vector<int> arr)
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
void print_linked_list(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Brute force approach: Using stack
// Time complexity: O(n)
// Space complexity: O(n)
Node* reverse_linked_list_BF(Node* head){
    Node* temp = head;  
    
    // Create a stack to temporarily
    // store the data values
    stack<int> st;     

    // Step 1: Push the values of the
    // linked list onto the stack
    while (temp != nullptr) {
        // Push the current node's
        // data onto the stack
        st.push(temp->data); 
        
        // Move to the next node
        // in the linked list
        temp = temp->next;    
    }
    
    // Reset the temporary pointer to
    // the head of the linked list
    temp = head; 
    
    // Step 2: Pop values from the stack
    // and update the linked list
    while (temp != nullptr) {
        // Set the current node's data to
        // the value at the top of the stack
        temp->data = st.top();  
        
        // Pop the top element from the stack
        st.pop();              
        
        // Move to the next node
        // in the linked list
        temp = temp->next;     
    }
    
    // Return the new head of
    // the reversed linked list
    return head;  
}


// Optimal approach: Iterative approach
// Time complexity: O(n)
// Space complexity: O(1)
Node* reverse_linked_list_optimal(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

// Optimal approach: Recursive approach
// Time complexity: O(n)
// Space complexity: O(n)
Node* reverse_linked_list_recursive(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = reverse_linked_list_recursive(head->next);
    Node* front=head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main(){
     vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = arr_to_linkedList(arr);
    // Brute force approach
    // cout << "Original linked list: ";
    // print_linked_list(head);
    // head = reverse_linked_list_BF(head);
    // cout << "Reversed linked list: ";
    // print_linked_list(head);

    // Optimal approach: Iterative approach
    // cout << "Original linked list: ";
    // print_linked_list(head);
    // head = reverse_linked_list_optimal(head);
    // cout << "Reversed linked list: ";
    // print_linked_list(head);

    // Optimal approach: Recursive approach
    cout << "Original linked list: ";
    print_linked_list(head);
    head = reverse_linked_list_recursive(head);
    cout << "Reversed linked list: ";
    print_linked_list(head);

    return 0;
}