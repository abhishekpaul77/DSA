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
Node* delete_middle_node_BF(Node* head){
    Node* temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp = temp->next;
    }
    int result = cnt/2;
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
// Time complexity: O(n/2)
// Space complexity: O(1)
Node* delete_middle_node(Node* head){
    // Write your code here.
    if(head==NULL || head->next==NULL) return nullptr;
    Node* last=NULL;
    Node* slow=head;
    Node* fast=head;
    fast=fast->next->next;
    while(fast!=NULL && fast->next!=NULL){
        last=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    last->next=slow->next;
    delete slow;

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

    // Call the function and print the result
    head = delete_middle_node(head);
    cout << "Linked List after deleting the middle node: ";
    printLinkedList(head);

    return 0;
}