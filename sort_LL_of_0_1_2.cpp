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

// Brute force approach
// Time complexity: O(2N)
// Space complexity: O(1)
Node* sort_0_1_2(Node *head)
{
    // Write your code here.
    Node *temp = head;
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (cnt0 > 0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1 > 0)
        {
            temp->data = 1;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }
    return head;
}


// Optimal approach: Using 3 dummy nodes to store the linked list
// Time complexity: O(N), where N is the number of nodes in the linked list
// Space complexity: O(1)
Node *sort_0_1_2_optimal(Node *head)
{
    // Write your code here.
    Node *zero = new Node(-1);
    Node *one = new Node(-1);
    Node *two = new Node(-1);
    Node *temp = head;
    Node *temp0 = zero;
    Node *temp1 = one;
    Node *temp2 = two;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            temp0->next = temp;
            temp0 = temp0->next;
        }
        else if (temp->data == 1)
        {
            temp1->next = temp;
            temp1 = temp1->next;
        }
        else
        {
            temp2->next = temp;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    temp0->next = one->next != NULL ? one->next : two->next;
    temp1->next = two->next;
    temp2->next = NULL;
    delete zero;
    delete one;
    delete two;
    
    return zero->next;
}

int main(){
     Node *head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    return 0;
}