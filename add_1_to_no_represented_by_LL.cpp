#include <bits/stdc++.h>
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
// Time complexity: O(3N)
// Space complexity: O(1)
Node *reverse_linked_list_optimal(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

Node *add_1_to_LL_BF(Node *head)
{
    // Reverse the linked list
    head = reverse_linked_list_optimal(head);

    Node *temp = head;
    int carry = 1;
    while (temp != NULL)
    {
        temp->data += carry;
        if (temp->data > 9)
        {
            temp->data = 0;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        temp = temp->next;
    }

    // Reverse the linked list again
    head = reverse_linked_list_optimal(head);

    if (carry)
    {
        Node *new_head = new Node(1);
        new_head->next = head;
        head = new_head;
    }

    return head;
}

// Optimal approach: Recursive approach
// Time complexity: O(N)
// Space complexity: O(N)
int addHelper(Node *head)
{
    if (head == NULL)
    {
        return 1;
    }
    int carry = addHelper(head->next);
    head->data += carry;
    if (head->data > 9)
    {
        head->data = 0;
        return 1;
    }
    return 0;
}

Node *add_1_to_LL_optimal(Node *head)
{
    int carry = addHelper(head);
    if (carry)
    {
        Node *new_head = new Node(1);
        new_head->next = head;
        head = new_head;
    }
    return head;
}

int main()
{
    // Make a linked list
    // Node *head = new Node(1);
    // head->next = new Node(5);
    // head->next->next = new Node(9);
    Node *head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);

    // Print the linked list
    printLinkedList(head);

    // Add 1 to the linked list
    head = add_1_to_LL_optimal(head);

    // Print the linked list
    printLinkedList(head);
    return 0;
}