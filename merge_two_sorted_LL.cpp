#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    // Data stored in the node
    int data;   
    
    // Pointer to the next node in the list
    Node* next;      

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// Brute force approach: Using array to store the data of both linked lists and then sorting the array and then creating a new linked list from the sorted array
// Time complexity: O(N1) + O(N2) + O((N1+N2)log(N1+N2)) + O(N1+N2) = O(2N) + O(2N) = O(4N) = O(N)
// Space complexity: O(1)
Node* merge_two_sorted_LL_BF(Node* head1, Node* head2){
    vector<int> arr;
    Node* temp = head1;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    temp = head2;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(), arr.end());
    Node* head = new Node(arr[0]);
    temp = head;
    for(int i=1; i<arr.size(); i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Optimal approach: Using two pointers to merge the two linked lists
// Time complexity: O(N1+N2)
// Space complexity: O(1)
Node* merge_two_sorted_LL(Node* first, Node* second)
{
    // Write your code here.
    Node* t1=first;
    Node* t2=second;
    Node* dNode=new Node(-1);
    Node* temp=dNode;
    while(t1!=NULL && t2!=NULL){
        if(t1->data < t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
        } 
        else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;
        }
        if(t1!=NULL){
            temp->next=t1;
        }
        else{
            temp->next=t2;
        }
    }

    return dNode->next;
}

int main(){
    // Makine first linked list
    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    head1->next->next->next->next = new Node(9);
    head1->next->next->next->next->next = new Node(11);
    cout << "First linked list: ";
    printLinkedList(head1);

    // Making second linked list
    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    head2->next->next->next->next = new Node(10);
    cout << "Second linked list: ";
    printLinkedList(head2);

    // Merging two linked lists
    Node* head = merge_two_sorted_LL(head1, head2);
    cout << "Merged linked list: ";
    printLinkedList(head);

    return 0;
}