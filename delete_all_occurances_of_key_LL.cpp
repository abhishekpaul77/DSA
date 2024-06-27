#include <bits/stdc++.h>
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

// Delete all occurances of key
// Time complexity: O(N)
// Space complexity: O(1)
Node *deleteAllOccurances(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = head->next;
            }
            Node *prevH = temp->prev;
            Node *frontH = temp->next;
            if (prevH != NULL)
            {
                prevH->next = frontH;
            }
            if (frontH != NULL)
            {
                frontH->prev = prevH;
            }
            free(temp);
            temp = frontH;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    // Make a linked list
    Node *head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(10);
    head->next->next->next = new Node(10);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = new Node(10);

    // Print the linked list
    printLinkedList(head);

    // Delete all occurances of key
    head = deleteAllOccurances(head, 10);

    // Print the linked list
    printLinkedList(head);
    return 0;
}