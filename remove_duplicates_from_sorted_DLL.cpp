#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

// Function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Optimized approach
// Time complexity: O(N)
// Space complexity: O(1)
Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        Node* NextN=temp->next;
        while(NextN!=NULL && NextN->data==temp->data){
            NextN=NextN->next;
        }
        temp->next=NextN;
        if(NextN) NextN->prev=temp;
        temp=temp->next;
    }
    return head;
}


int main(){
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(1);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    cout << "Original linked list: ";
    printLinkedList(head);

    Node *newHead = removeDuplicates(head);

    cout << "Linked list after removing duplicates: ";
    printLinkedList(newHead);
    
    return 0;
}