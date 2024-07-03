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

// Optimal approach: Using 3 pointers to reverse the linked list
// Time complexity: O(logN)*O(N + N/2),where N is the number of nodes in the linked list
// Space complexity: O(1)
Node *find_middle(Node *head)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
        return nullptr;
    Node *last = NULL;
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        last = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    return last;
}

Node *merge_two_sorted_LL(Node *first, Node *second)
{
    // Write your code here.
    Node *t1 = first;
    Node *t2 = second;
    Node *dNode = new Node(-1);
    Node *temp = dNode;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
        if (t1 != NULL)
        {
            temp->next = t1;
        }
        else
        {
            temp->next = t2;
        }
    }

    return dNode->next;
}

// Function to merge the linked list
Node *merge(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *middle = find_middle(head);
    Node *leftHead = head;
    Node *rightHead = middle->next;
    middle->next = nullptr;

    leftHead = merge(leftHead);
    rightHead = merge(rightHead);

    return merge_two_sorted_LL(leftHead, rightHead);
}

int main()
{
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

    // Call the function and print the result
    head = merge(head);
    cout << "Linked List after merging: ";
    printLinkedList(head);

    return 0;
}