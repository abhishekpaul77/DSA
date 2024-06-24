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

// Brute force approach
// Time complexity: O(2n)
// Space complexity: O(1)
Node* delete_nth_node_from_back_BF(Node* head, int n){
    int cnt=0;
    Node* temp = head;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    int result=cnt-n;
    temp = head;
    while(temp!=NULL){
        result--;
        if(result==0){
            Node* delete_node = temp->next;
            temp->next = temp->next->next;
            delete delete_node;
            break;
    }
    temp = temp->next;
    }
    return head;
}

// Optimal approach
Node* delete_nth_node_from_back_(Node* head, int n){
    if(head==NULL){
        return NULL;
    }
    Node* fast=head;
    for(int i=0;i<n;i++){
        fast = fast->next;
    }
    Node* slow = head;
    while(fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
    }
    Node* delete_node = slow->next;
    slow->next = slow->next->next;
    delete delete_node;
    return head;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Delete the nth node from the back
    int n = 2;
    // head = delete_nth_node_from_back_BF(head, n);
    // cout << "Linked List after deleting the " << n << "th node from the back: ";
    // printLinkedList(head);

    head = delete_nth_node_from_back_(head, n);
    cout << "Linked List after deleting the " << n << "th node from the back: ";
    printLinkedList(head);

    return 0;
}