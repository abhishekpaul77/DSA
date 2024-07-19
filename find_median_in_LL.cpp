#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = NULL;
    }

};


// Function to convert an array to a doubly linked list
Node *arr_to_linkedList(vector<int> arr)
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
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Brute force approach
// Time complexity: O(n)
// Space complexity: O(1)
Node* find_middle_BF(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    temp = head;
    int midNode=(count/2)+1;
    while(temp!=NULL){
        midNode--;
        if(midNode==0){
            return temp;
        }
        temp = temp->next;
    }

    return temp;

}

// Optimal approach: Tortoise and hare approach
// Time complexity: O(n/2)
// Space complexity: O(1)
Node* find_middle_optimal(Node* head){
    Node* slow = head;
    Node* fast = head;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    
}     


int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = arr_to_linkedList(arr);

    Node* middle = find_middle_BF(head);
    cout << middle->data << endl;

    Node* middle1 = find_middle_optimal(head);
    cout << middle1->data << endl;

    return 0;
}