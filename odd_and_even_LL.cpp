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
// Time complexity: O(2n)
// Space complexity: O(n)
Node* odd_and_even_BF(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    vector<int> store;
    Node* temp = head;
    // Storing the odd indexed elements
    while(temp!=NULL && temp->next!=NULL){
        store.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp!=NULL){
        store.push_back(temp->data);
    }

    // Storing the even indexed elements
    temp = head->next;
    while(temp!=NULL && temp->next!=NULL){
        store.push_back(temp->data);
        temp = temp->next->next;
    }
    if(temp!=NULL){
        store.push_back(temp->data);
    }

    // Creating a new linked list with the stored elements
    int i=0;
    temp=head;
    while(temp!=NULL){
        temp->data = store[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// Optimal approach: Two pointer approach
// Time complexity: O(n)
// Space complexity: O(1)
Node* odd_and_even(Node* head)
{
	// Write your code here.
    if (!head || !head->next) return head;
    Node* first=head;
    Node* second=head->next;
    Node* evenHead = second;
    while(first->next!=nullptr && first->next->next!=nullptr){
        first->next=first->next->next;
        second->next=second->next->next;
        first=first->next;
        second=second->next;
    }
    first->next=evenHead;

    return head;
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

    // Call the function and print the result
    // head = odd_and_even_BF(head);
    // cout << "After Odd and Even: ";
    // printLinkedList(head);

    head = odd_and_even(head);
    cout << "After Odd and Even: ";
    printLinkedList(head);
    return 0;
}