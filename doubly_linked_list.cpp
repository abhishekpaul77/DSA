#include<bits/stdc++.h>
using namespace std;

// Doubly linked list node:
// It has three parts:
// 1. Data part: It stores the data
// 2. Next part: It stores the address of the next node
// 3. Back part: It stores the address of the previous node

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    Node(int data1, Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = NULL;
        back = NULL;
    }
};

// Function to convert an array to a linked list
Node* array_to_linkedList(vector<int> arr)
{
    Node* head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        prev->next=temp;
        prev=temp;
    }
    return head;
}


// Function to print the linked list
void print_linked_list(Node* head)
{
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=array_to_linkedList(arr);
    print_linked_list(head);
    return 0;
}