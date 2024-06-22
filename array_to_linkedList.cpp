#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

// Function to convert an array to a linked list
Node *array_to_linkedList(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Function to print the linked list
void print_linked_list(Node *head)
{
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

// Function to find the length of the linked list
int length_LL(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

// Function to search in the linked list
int search_LL(Node* head,int target){
    Node* temp=head;
    while(temp){
        if(temp->data==target){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = array_to_linkedList(arr);
    cout<<head->data<<endl;

    // Printing the linked list
    print_linked_list(head);

    // Finding the length of the linked list
    cout<<length_LL(head);

    cout<<endl;

    // Searching in the linked list
    cout<<search_LL(head, 3);
    return 0;
}