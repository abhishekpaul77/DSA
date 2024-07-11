#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Brute force approach: Hashing
// Time complexity: O(2 * N) This is because we traverse the linked list twice: once to push the values onto the stack, and once to pop the values and compare with the linked list. Both traversals take O(2*N) ~ O(N) time.z
// Space complexity: O(N) The space complexity is O(N) because we use a stack to store the values of the linked list.
bool isPalindrome_BF(Node* head) {
    // Create an empty stack
    // to store values
    stack<int> st;

    // Initialize a temporary pointer
    // to the head of the linked list
    Node* temp = head;

    // Traverse the linked list and
    // push values onto the stack
    while (temp != NULL) {
        
        // Push the data from the
        // current node onto the stack
        st.push(temp->data); 
        
         // Move to the next node
        temp = temp->next;  
    }

    // Reset the temporary pointer back
    // to the head of the linked list
    temp = head;

    // Compare values by popping from the stack
    // and checking against linked list nodes
    while (temp != NULL) {
        if (temp->data != st.top()) {
            
            // If values don't match,
            // it's not a palindrome
            return false; 
        }
        
        // Pop the value from the stack
        st.pop();         
        
        // Move to the next node
        // in the linked list
        temp = temp->next; 
    }

     // If all values match,
     // it's a palindrome
    return true;
}


// Optimal approach: Reverse the second half of the linked list
// Time complexity: O(N) The algorithm traverses the linked list twice: once to find the middle node and once to reverse the second half of the linked list. Both traversals take O(N) time.
// Space complexity: O(1) The space complexity is O(1) because we only use a constant amount of extra space to store pointers and variables.

Node* reverse_LL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newH= reverse_LL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newH;
}

bool isPalindrome(Node* head){
    // Initialize two pointers to the head of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list to find the middle node
    while (fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead=reverse_LL(slow->next);
    Node* first=head;
    Node* second=newHead;
    while(second!=NULL){
        if(first->data!=second->data){
            reverse_LL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverse_LL(newHead);
    return true;
}



int main(){
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }
    return 0;
}