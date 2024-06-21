#include <bits/stdc++.h>
using namespace std;

// Define a Node class for doubly linked list
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

// Function to convert an array to a doubly linked list
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

// Function to delete the head of the doubly linked list
// The functionality of this has been explained in our previous
// article, please refer to it.
Node *delete_head(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        // Return NULL if the list is empty or contains only one element
        return nullptr;
    }

    // Store the current head as 'prev'
    Node *prev = head;
    // Move 'head' to the next node
    head = head->next;

    // Set 'back' pointer of the new head to nullptr
    head->back = nullptr;

    // Set 'next' pointer of 'prev' to nullptr
    prev->next = nullptr;

    // Return the new head
    return head;
}

// Function to delete the tail of the doubly linked list
Node *delete_tail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        // If the list is empty or has only one node, return null
        return nullptr;
    }

    Node *tail = head;
    while (tail->next != nullptr)
    {
        // Traverse to the last node (tail)
        tail = tail->next;
    }

    Node *newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;

    // Free memory of the deleted node
    delete tail;

    return head;
}

// Function to delete a node at a given position
Node *delete_Kth_node(Node *head, int pos)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        if (cnt == pos)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front->next = nullptr)
    {
        return delete_tail(head);
    }
    else if (prev->back == nullptr)
    {
        return delete_head(head);
    }

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}

// Function to delete a node with a given pointer
void delete_node(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;
    if (front == nullptr)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }
    prev->next = nullptr;
    front->back = nullptr;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
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

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = arr_to_linkedList(arr);

    // Deleting head node
    // head=delete_head(head);
    // print_linked_list(head);

    // Deleting tail node
    // head=delete_tail(head);
    // print_linked_list(head);

    // Deleting node at a given position
    // head=delete_node(head,2);
    // print_linked_list(head);

    // Deleting a specific node with a given pointer
    // delete_node(head->next);
    // print_linked_list(head);

    return 0;
}