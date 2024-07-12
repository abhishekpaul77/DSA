#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    // Data stored in the node
    int data;

    // Pointer to the next node in the list
    Node *next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1)
    {
        data = data1;
        next = nullptr;
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

// Optimal approach
// Time complexity: O(max(N, M)
// Space complexity: O(max(N, M))
Node* addTwoNumbers(Node* l1, Node* l2) {
    Node *dummy = new Node(0);
    Node *temp = dummy;
    Node* t1=l1;
    Node* t2=l2;
    int carry = 0;
    while (t1 != NULL || t2 != NULL){
        int sum=carry;
        if(t1)sum+=t1->data;
        if(t2)sum+=t2->data;
        carry=sum/10;
        Node* newNode = new Node(sum%10);
        temp->next = newNode;
        temp = newNode;
        if(t1!=NULL) t1=t1->next;
        if(t2!=NULL) t2=t2->next;
        if(carry>0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }
    return dummy->next;
}



int main(){
    //Make first linked list
    Node *head1 = new Node(3);
    head1->next = new Node(5); 
    
    //Make second linked list
    Node *head2 = new Node(4);
    head2->next = new Node(5);
    head2->next->next = new Node(9);
    head2->next->next->next = new Node(9);

    //Print the linked list
    printLinkedList(head1);
    printLinkedList(head2);

    //Add the two linked lists
    Node* head3 = addTwoNumbers(head1, head2);
    printLinkedList(head3);


    return 0;
}